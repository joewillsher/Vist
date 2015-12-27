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
  br label %tailrecurse.i

tailrecurse.i:                                    ; preds = %cont0.i, %entry
  %accumulator.tr.i = phi i64 [ 1, %entry ], [ %mul_res.i, %cont0.i ]
  %a.tr.i = phi i64 [ 100, %entry ], [ %sub_res.i, %cont0.i ]
  %cmp_lte_res.i = icmp slt i64 %a.tr.i, 2
  br i1 %cmp_lte_res.i, label %fact.exit, label %cont0.i

cont0.i:                                          ; preds = %tailrecurse.i
  %sub_res.i = add i64 %a.tr.i, -1
  %mul_res.i = mul i64 %accumulator.tr.i, %a.tr.i
  br label %tailrecurse.i

fact.exit:                                        ; preds = %tailrecurse.i
  %accumulator.tr.i.lcssa = phi i64 [ %accumulator.tr.i, %tailrecurse.i ]
  %0 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %accumulator.tr.i.lcssa)
  %backedge.overflow = icmp eq i64 100000000, -1
  %overflow.check.anchor = add i64 0, 0
  br i1 %backedge.overflow, label %scalar.ph, label %overflow.checked

overflow.checked:                                 ; preds = %fact.exit
  br i1 false, label %middle.block, label %vector.ph

vector.ph:                                        ; preds = %overflow.checked
  br label %vector.body

vector.body:                                      ; preds = %vector.body, %vector.ph
  %index = phi i64 [ 0, %vector.ph ], [ %index.next, %vector.body ]
  %vec.phi = phi i64 [ 0, %vector.ph ], [ %predphi, %vector.body ]
  %vec.phi1 = phi i64 [ 0, %vector.ph ], [ %predphi3, %vector.body ]
  %induction = add i64 %index, 0
  %induction2 = add i64 %index, 1
  %1 = add i64 %induction, 1
  %2 = add i64 %induction2, 1
  %3 = urem i64 %induction, 3
  %4 = urem i64 %induction2, 3
  %5 = icmp eq i64 %3, 0
  %6 = icmp eq i64 %4, 0
  %7 = urem i64 %induction, 5
  %8 = urem i64 %induction2, 5
  %9 = icmp eq i64 %7, 0
  %10 = icmp eq i64 %8, 0
  %11 = or i1 %5, %9
  %12 = or i1 %6, %10
  %13 = add i64 %induction, %vec.phi
  %14 = add i64 %induction2, %vec.phi1
  %15 = or i1 false, %11
  %16 = or i1 false, %12
  %17 = select i1 %15, i64 %13, i64 %13
  %18 = select i1 %16, i64 %14, i64 %14
  %19 = xor i1 %11, true
  %20 = xor i1 %12, true
  %predphi = select i1 %19, i64 %vec.phi, i64 %17
  %predphi3 = select i1 %20, i64 %vec.phi1, i64 %18
  %21 = icmp slt i64 %1, 100000001
  %22 = icmp slt i64 %2, 100000001
  %index.next = add i64 %index, 2
  %23 = icmp eq i64 %index.next, 100000000
  br i1 %23, label %middle.block, label %vector.body, !llvm.loop !2

middle.block:                                     ; preds = %vector.body, %overflow.checked
  %resume.val = phi i64 [ 0, %overflow.checked ], [ 100000000, %vector.body ]
  %trunc.resume.val = phi i64 [ 0, %overflow.checked ], [ 100000000, %vector.body ]
  %rdx.vec.exit.phi = phi i64 [ 0, %overflow.checked ], [ %predphi, %vector.body ]
  %rdx.vec.exit.phi4 = phi i64 [ 0, %overflow.checked ], [ %predphi3, %vector.body ]
  %bin.rdx = add i64 %rdx.vec.exit.phi4, %rdx.vec.exit.phi
  %cmp.n = icmp eq i64 100000001, %resume.val
  br i1 %cmp.n, label %afterloop, label %scalar.ph

scalar.ph:                                        ; preds = %middle.block, %fact.exit
  %bc.resume.val = phi i64 [ %resume.val, %middle.block ], [ 0, %fact.exit ]
  %bc.trunc.resume.val = phi i64 [ %trunc.resume.val, %middle.block ], [ 0, %fact.exit ]
  %bc.merge.rdx = phi i64 [ 0, %fact.exit ], [ %bin.rdx, %middle.block ]
  br label %loop

loop:                                             ; preds = %cont, %scalar.ph
  %tot.0 = phi i64 [ %bc.merge.rdx, %scalar.ph ], [ %tot.1, %cont ]
  %i = phi i64 [ %bc.trunc.resume.val, %scalar.ph ], [ %nexti, %cont ]
  %nexti = add i64 %i, 1
  %rem_res = urem i64 %i, 3
  %cmp_eq_res = icmp eq i64 %rem_res, 0
  %rem_res2 = urem i64 %i, 5
  %cmp_eq_res3 = icmp eq i64 %rem_res2, 0
  %or_res = or i1 %cmp_eq_res, %cmp_eq_res3
  br i1 %or_res, label %then0, label %cont

afterloop:                                        ; preds = %middle.block, %cont
  %tot.1.lcssa = phi i64 [ %tot.1, %cont ], [ %bin.rdx, %middle.block ]
  %24 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %tot.1.lcssa)
  %cmp_gt_res = icmp sgt i64 %tot.1.lcssa, 1
  br i1 %cmp_gt_res, label %loop6.preheader, label %afterloop7

loop6.preheader:                                  ; preds = %afterloop
  br label %loop6

cont:                                             ; preds = %then0, %loop
  %tot.1 = phi i64 [ %25, %then0 ], [ %tot.0, %loop ]
  %looptest = icmp slt i64 %nexti, 100000001
  br i1 %looptest, label %loop, label %afterloop, !llvm.loop !5

then0:                                            ; preds = %loop
  %25 = add i64 %i, %tot.0
  br label %cont

loop6:                                            ; preds = %loop6.preheader, %loop6
  %tot.2 = phi i64 [ %div_res, %loop6 ], [ %tot.1.lcssa, %loop6.preheader ]
  %div_res = lshr i64 %tot.2, 1
  %26 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %div_res)
  %cmp_gt_res12 = icmp ugt i64 %tot.2, 3
  br i1 %cmp_gt_res12, label %loop6, label %afterloop7.loopexit

afterloop7.loopexit:                              ; preds = %loop6
  br label %afterloop7

afterloop7:                                       ; preds = %afterloop7.loopexit, %afterloop
  ret i64 0
}

define i64 @fact(i64 %a) {
entry:
  br label %tailrecurse

tailrecurse:                                      ; preds = %else1, %entry
  %accumulator.tr = phi i64 [ 1, %entry ], [ %mul_res, %else1 ]
  %a.tr = phi i64 [ %a, %entry ], [ %sub_res, %else1 ]
  %cmp_lte_res = icmp slt i64 %a.tr, 2
  br i1 %cmp_lte_res, label %then0, label %cont0

cont0:                                            ; preds = %tailrecurse
  br label %else1

then0:                                            ; preds = %tailrecurse
  ret i64 %accumulator.tr

else1:                                            ; preds = %cont0
  %sub_res = add i64 %a.tr, -1
  %mul_res = mul i64 %accumulator.tr, %a.tr
  br label %tailrecurse
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
