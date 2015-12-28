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
  %0 = call i64 @fact(i64 10)
  %y = alloca i64
  store i64 %0, i64* %y
  %y1 = load i64* %y
  call void @bar(i64 %y1)
  %tot = alloca i64
  store i64 0, i64* %tot
  br label %loop

loop:                                             ; preds = %cont, %entry
  %i = phi i64 [ 0, %entry ], [ %nexti, %cont ]
  %nexti = add i64 1, %i
  %rem_res = urem i64 %i, 3
  %cmp_eq_res = icmp eq i64 %rem_res, 0
  %rem_res2 = urem i64 %i, 5
  %cmp_eq_res3 = icmp eq i64 %rem_res2, 0
  %or_res = or i1 %cmp_eq_res, %cmp_eq_res3
  br i1 %or_res, label %then0, label %cont

afterloop:                                        ; preds = %cont
  %tot5 = load i64* %tot
  call void @print(i64 %tot5)
  ret i64 0

cont:                                             ; preds = %loop, %then0
  %looptest = icmp sle i64 %nexti, 10000
  br i1 %looptest, label %loop, label %afterloop

then0:                                            ; preds = %loop
  %tot4 = load i64* %tot
  %add_res = add i64 %tot4, %i
  store i64 %add_res, i64* %tot
  br label %cont
}

define i64 @foo(i64 %a, i64 %b) {
entry:
  %add_res = add i64 %a, %b
  ret i64 %add_res
}

define void @bar(i64 %"$0") {
entry:
  call void @print(i64 %"$0")
  ret void
}

define i64 @fact(i64 %a) {
entry:
  %cmp_lte_res = icmp sle i64 %a, 1
  br i1 %cmp_lte_res, label %then0, label %cont0

cont0:                                            ; preds = %entry
  br label %else1

then0:                                            ; preds = %entry
  %0 = call i64 @foo(i64 0, i64 1)
  ret i64 %0

else1:                                            ; preds = %cont0
  %sub_res = sub i64 %a, 1
  %1 = call i64 @fact(i64 %sub_res)
  %mul_res = mul i64 %a, %1
  ret i64 %mul_res
}

attributes #0 = { ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
