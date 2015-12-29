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

define i64 @main() {
entry:
  ret i64 0
}

define i1 @lt(i64 %"$0", i64 %"$1") {
entry:
  %cmp_lt_res = icmp slt i64 %"$0", %"$1"
  ret i1 %cmp_lt_res
}

define i1 @or(i1 %"$0", i1 %"$1") {
entry:
  %or_res = or i1 %"$0", %"$1"
  ret i1 %or_res
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

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
