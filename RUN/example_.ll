; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

; Function Attrs: ssp uwtable
define void @print(i64 %i) #0 {
  %1 = alloca i64, align 8
  store i64 %i, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i64 %2)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: ssp uwtable
define void @printd(double %d) #0 {
  %1 = alloca double, align 8
  store double %d, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), double %2)
  ret void
}

define i64 @main() {
entry:
  %tot = alloca i64
  store i64 0, i64* %tot
  br label %loop

loop:                                             ; preds = %cont, %entry
  %i = phi i64 [ 0, %entry ], [ %nexti, %cont ]
  %nexti = add i64 1, %i
  %rem_res = urem i64 %i, 3
  %cmp_eq_res = icmp eq i64 %rem_res, 0
  %rem_res1 = urem i64 %i, 5
  %cmp_eq_res2 = icmp eq i64 %rem_res1, 0
  %or_res = or i1 %cmp_eq_res, %cmp_eq_res2
  br i1 %or_res, label %then0, label %cont

afterloop:                                        ; preds = %cont
  %tot4 = load i64* %tot
  call void @print(i64 %tot4)
  %tot7 = load i64* %tot
  %cmp_gt_res = icmp sgt i64 %tot7, 1
  br i1 %cmp_gt_res, label %loop5, label %afterloop6

cont:                                             ; preds = %loop, %then0
  %looptest = icmp sle i64 %nexti, 100000000
  br i1 %looptest, label %loop, label %afterloop

then0:                                            ; preds = %loop
  %tot3 = load i64* %tot
  %add_res = add i64 %tot3, %i
  store i64 %add_res, i64* %tot
  br label %cont

loop5:                                            ; preds = %loop5, %afterloop
  %tot8 = load i64* %tot
  %div_res = udiv i64 %tot8, 2
  store i64 %div_res, i64* %tot
  %tot9 = load i64* %tot
  call void @print(i64 %tot9)
  %tot10 = load i64* %tot
  %cmp_gt_res11 = icmp sgt i64 %tot10, 1
  br i1 %cmp_gt_res11, label %loop5, label %afterloop6

afterloop6:                                       ; preds = %loop5, %afterloop
  ret i64 0
}

attributes #0 = { ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
