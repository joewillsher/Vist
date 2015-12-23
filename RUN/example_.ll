; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [10 x i8] c"sup meme\0A\00", align 1
@.str1 = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

; Function Attrs: ssp uwtable
define void @printStr() #0 {
  %1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([10 x i8]* @.str, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: ssp uwtable
define void @print(i64 %i) #0 {
  %1 = alloca i64, align 8
  store i64 %i, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i32 0, i32 0), i64 %2)
  ret void
}

; Function Attrs: ssp uwtable
define void @printd(double %d) #0 {
  %1 = alloca double, align 8
  store double %d, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %2)
  ret void
}

; Function Attrs: nounwind ssp uwtable
define i8* @memcpy(i8* %a, i8* %b, i64 %s) #2 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i64, align 8
  store i8* %a, i8** %1, align 8
  store i8* %b, i8** %2, align 8
  store i64 %s, i64* %3, align 8
  %4 = load i8** %1, align 8
  %5 = load i8** %2, align 8
  %6 = load i64* %3, align 8
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %4, i8* %5, i64 %6, i32 1, i1 false)
  ret i8* %4
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #3

define i64 @main() {
entry:
  %arr = alloca [9 x i64]
  %base = bitcast [9 x i64]* %arr to i64*
  %el0 = getelementptr i64* %base, i64 0
  store i64 0, i64* %el0
  %el1 = getelementptr i64* %base, i64 1
  store i64 1, i64* %el1
  %el2 = getelementptr i64* %base, i64 2
  store i64 2, i64* %el2
  %el3 = getelementptr i64* %base, i64 3
  store i64 3, i64* %el3
  %el4 = getelementptr i64* %base, i64 4
  store i64 4, i64* %el4
  %el5 = getelementptr i64* %base, i64 5
  store i64 5, i64* %el5
  %el6 = getelementptr i64* %base, i64 6
  store i64 6, i64* %el6
  %el7 = getelementptr i64* %base, i64 7
  store i64 7, i64* %el7
  %el8 = getelementptr i64* %base, i64 8
  store i64 8, i64* %el8
  %arr1 = alloca i64*
  store i64* %base, i64** %arr1
  br label %loop

loop:                                             ; preds = %loop, %entry
  %i = phi i64 [ 0, %entry ], [ %nexti, %loop ]
  %nexti = add i64 1, %i
  %ptr = getelementptr i64* %base, i64 %i
  %0 = call i64 @fact(i64 %i)
  store i64 %0, i64* %ptr
  %looptest = icmp sle i64 %nexti, 8
  br i1 %looptest, label %loop, label %afterloop

afterloop:                                        ; preds = %loop
  br label %loop2

loop2:                                            ; preds = %loop2, %afterloop
  %i4 = phi i64 [ 0, %afterloop ], [ %nexti5, %loop2 ]
  %nexti5 = add i64 1, %i4
  %ptr6 = getelementptr i64* %base, i64 %i4
  %element = load i64* %ptr6
  call void @print(i64 %element)
  %looptest7 = icmp sle i64 %nexti5, 8
  br i1 %looptest7, label %loop2, label %afterloop3

afterloop3:                                       ; preds = %loop2
  ret i64 0
}

define i64 @fact(i64 %a) {
entry:
  %cmp_lte_res = icmp sle i64 %a, 1
  br i1 %cmp_lte_res, label %then0, label %cont0

cont0:                                            ; preds = %entry
  br label %else1

then0:                                            ; preds = %entry
  ret i64 1

else1:                                            ; preds = %cont0
  %sub_res = sub i64 %a, 1
  %0 = call i64 @fact(i64 %sub_res)
  %mul_res = mul i64 %a, %0
  ret i64 %mul_res
}

attributes #0 = { ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
