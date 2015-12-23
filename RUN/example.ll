; ModuleID = 'example_.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [10 x i8] c"sup meme\0A\00", align 1
@.str1 = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@str = private unnamed_addr constant [9 x i8] c"sup meme\00"

; Function Attrs: ssp uwtable
define void @printStr() #0 {
  %puts = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @str, i64 0, i64 0))
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: ssp uwtable
define void @print(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %i)
  ret void
}

; Function Attrs: ssp uwtable
define void @printd(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: nounwind ssp uwtable
define i8* @memcpy(i8* %a, i8* %b, i64 %s) #2 {
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %a, i8* %b, i64 %s, i32 1, i1 false)
  ret i8* %a
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #3

; Function Attrs: ssp
define i64 @main() #4 {
entry:
  %arr65 = alloca [9 x i64], align 8
  %arr65.sub = getelementptr inbounds [9 x i64]* %arr65, i64 0, i64 0
  store i64 0, i64* %arr65.sub, align 8
  %el1 = getelementptr [9 x i64]* %arr65, i64 0, i64 1
  store i64 1, i64* %el1, align 8
  %el2 = getelementptr [9 x i64]* %arr65, i64 0, i64 2
  store i64 2, i64* %el2, align 8
  %el3 = getelementptr [9 x i64]* %arr65, i64 0, i64 3
  store i64 3, i64* %el3, align 8
  %el4 = getelementptr [9 x i64]* %arr65, i64 0, i64 4
  store i64 4, i64* %el4, align 8
  %el5 = getelementptr [9 x i64]* %arr65, i64 0, i64 5
  store i64 5, i64* %el5, align 8
  %el6 = getelementptr [9 x i64]* %arr65, i64 0, i64 6
  store i64 6, i64* %el6, align 8
  %el7 = getelementptr [9 x i64]* %arr65, i64 0, i64 7
  store i64 7, i64* %el7, align 8
  %el8 = getelementptr [9 x i64]* %arr65, i64 0, i64 8
  store i64 8, i64* %el8, align 8
  br label %loop

loop:                                             ; preds = %entry
  br label %tailrecurse.i

tailrecurse.i:                                    ; preds = %cont0.i, %loop
  %accumulator.tr.i = phi i64 [ 1, %loop ], [ %mul_res.i, %cont0.i ]
  %"$0.tr.i" = phi i64 [ 0, %loop ], [ %sub_res.i, %cont0.i ]
  %cmp_lte_res.i = icmp slt i64 %"$0.tr.i", 2
  br i1 %cmp_lte_res.i, label %fact.exit, label %cont0.i

cont0.i:                                          ; preds = %tailrecurse.i
  %sub_res.i = add i64 %"$0.tr.i", -1
  %mul_res.i = mul i64 %accumulator.tr.i, %"$0.tr.i"
  br label %tailrecurse.i

fact.exit:                                        ; preds = %tailrecurse.i
  %accumulator.tr.i.lcssa = phi i64 [ %accumulator.tr.i, %tailrecurse.i ]
  store i64 %accumulator.tr.i.lcssa, i64* %arr65.sub, align 8
  %ptr.1 = getelementptr [9 x i64]* %arr65, i64 0, i64 1
  br label %tailrecurse.i4

tailrecurse.i4:                                   ; preds = %cont0.i5, %fact.exit
  %accumulator.tr.i1 = phi i64 [ 1, %fact.exit ], [ %mul_res.i7, %cont0.i5 ]
  %"$0.tr.i2" = phi i64 [ 1, %fact.exit ], [ %sub_res.i6, %cont0.i5 ]
  %cmp_lte_res.i3 = icmp slt i64 %"$0.tr.i2", 2
  br i1 %cmp_lte_res.i3, label %fact.exit8, label %cont0.i5

cont0.i5:                                         ; preds = %tailrecurse.i4
  %sub_res.i6 = add i64 %"$0.tr.i2", -1
  %mul_res.i7 = mul i64 %accumulator.tr.i1, %"$0.tr.i2"
  br label %tailrecurse.i4

fact.exit8:                                       ; preds = %tailrecurse.i4
  %accumulator.tr.i1.lcssa = phi i64 [ %accumulator.tr.i1, %tailrecurse.i4 ]
  store i64 %accumulator.tr.i1.lcssa, i64* %ptr.1, align 8
  %ptr.2 = getelementptr [9 x i64]* %arr65, i64 0, i64 2
  br label %tailrecurse.i12

tailrecurse.i12:                                  ; preds = %cont0.i13, %fact.exit8
  %accumulator.tr.i9 = phi i64 [ 1, %fact.exit8 ], [ %mul_res.i15, %cont0.i13 ]
  %"$0.tr.i10" = phi i64 [ 2, %fact.exit8 ], [ %sub_res.i14, %cont0.i13 ]
  %cmp_lte_res.i11 = icmp slt i64 %"$0.tr.i10", 2
  br i1 %cmp_lte_res.i11, label %fact.exit16, label %cont0.i13

cont0.i13:                                        ; preds = %tailrecurse.i12
  %sub_res.i14 = add i64 %"$0.tr.i10", -1
  %mul_res.i15 = mul i64 %accumulator.tr.i9, %"$0.tr.i10"
  br label %tailrecurse.i12

fact.exit16:                                      ; preds = %tailrecurse.i12
  %accumulator.tr.i9.lcssa = phi i64 [ %accumulator.tr.i9, %tailrecurse.i12 ]
  store i64 %accumulator.tr.i9.lcssa, i64* %ptr.2, align 8
  %ptr.3 = getelementptr [9 x i64]* %arr65, i64 0, i64 3
  br label %tailrecurse.i20

tailrecurse.i20:                                  ; preds = %cont0.i21, %fact.exit16
  %accumulator.tr.i17 = phi i64 [ 1, %fact.exit16 ], [ %mul_res.i23, %cont0.i21 ]
  %"$0.tr.i18" = phi i64 [ 3, %fact.exit16 ], [ %sub_res.i22, %cont0.i21 ]
  %cmp_lte_res.i19 = icmp slt i64 %"$0.tr.i18", 2
  br i1 %cmp_lte_res.i19, label %fact.exit24, label %cont0.i21

cont0.i21:                                        ; preds = %tailrecurse.i20
  %sub_res.i22 = add i64 %"$0.tr.i18", -1
  %mul_res.i23 = mul i64 %accumulator.tr.i17, %"$0.tr.i18"
  br label %tailrecurse.i20

fact.exit24:                                      ; preds = %tailrecurse.i20
  %accumulator.tr.i17.lcssa = phi i64 [ %accumulator.tr.i17, %tailrecurse.i20 ]
  store i64 %accumulator.tr.i17.lcssa, i64* %ptr.3, align 8
  %ptr.4 = getelementptr [9 x i64]* %arr65, i64 0, i64 4
  br label %tailrecurse.i28

tailrecurse.i28:                                  ; preds = %cont0.i29, %fact.exit24
  %accumulator.tr.i25 = phi i64 [ 1, %fact.exit24 ], [ %mul_res.i31, %cont0.i29 ]
  %"$0.tr.i26" = phi i64 [ 4, %fact.exit24 ], [ %sub_res.i30, %cont0.i29 ]
  %cmp_lte_res.i27 = icmp slt i64 %"$0.tr.i26", 2
  br i1 %cmp_lte_res.i27, label %fact.exit32, label %cont0.i29

cont0.i29:                                        ; preds = %tailrecurse.i28
  %sub_res.i30 = add i64 %"$0.tr.i26", -1
  %mul_res.i31 = mul i64 %accumulator.tr.i25, %"$0.tr.i26"
  br label %tailrecurse.i28

fact.exit32:                                      ; preds = %tailrecurse.i28
  %accumulator.tr.i25.lcssa = phi i64 [ %accumulator.tr.i25, %tailrecurse.i28 ]
  store i64 %accumulator.tr.i25.lcssa, i64* %ptr.4, align 8
  %ptr.5 = getelementptr [9 x i64]* %arr65, i64 0, i64 5
  br label %tailrecurse.i36

tailrecurse.i36:                                  ; preds = %cont0.i37, %fact.exit32
  %accumulator.tr.i33 = phi i64 [ 1, %fact.exit32 ], [ %mul_res.i39, %cont0.i37 ]
  %"$0.tr.i34" = phi i64 [ 5, %fact.exit32 ], [ %sub_res.i38, %cont0.i37 ]
  %cmp_lte_res.i35 = icmp slt i64 %"$0.tr.i34", 2
  br i1 %cmp_lte_res.i35, label %fact.exit40, label %cont0.i37

cont0.i37:                                        ; preds = %tailrecurse.i36
  %sub_res.i38 = add i64 %"$0.tr.i34", -1
  %mul_res.i39 = mul i64 %accumulator.tr.i33, %"$0.tr.i34"
  br label %tailrecurse.i36

fact.exit40:                                      ; preds = %tailrecurse.i36
  %accumulator.tr.i33.lcssa = phi i64 [ %accumulator.tr.i33, %tailrecurse.i36 ]
  store i64 %accumulator.tr.i33.lcssa, i64* %ptr.5, align 8
  %ptr.6 = getelementptr [9 x i64]* %arr65, i64 0, i64 6
  br label %tailrecurse.i44

tailrecurse.i44:                                  ; preds = %cont0.i45, %fact.exit40
  %accumulator.tr.i41 = phi i64 [ 1, %fact.exit40 ], [ %mul_res.i47, %cont0.i45 ]
  %"$0.tr.i42" = phi i64 [ 6, %fact.exit40 ], [ %sub_res.i46, %cont0.i45 ]
  %cmp_lte_res.i43 = icmp slt i64 %"$0.tr.i42", 2
  br i1 %cmp_lte_res.i43, label %fact.exit48, label %cont0.i45

cont0.i45:                                        ; preds = %tailrecurse.i44
  %sub_res.i46 = add i64 %"$0.tr.i42", -1
  %mul_res.i47 = mul i64 %accumulator.tr.i41, %"$0.tr.i42"
  br label %tailrecurse.i44

fact.exit48:                                      ; preds = %tailrecurse.i44
  %accumulator.tr.i41.lcssa = phi i64 [ %accumulator.tr.i41, %tailrecurse.i44 ]
  store i64 %accumulator.tr.i41.lcssa, i64* %ptr.6, align 8
  %ptr.7 = getelementptr [9 x i64]* %arr65, i64 0, i64 7
  br label %tailrecurse.i52

tailrecurse.i52:                                  ; preds = %cont0.i53, %fact.exit48
  %accumulator.tr.i49 = phi i64 [ 1, %fact.exit48 ], [ %mul_res.i55, %cont0.i53 ]
  %"$0.tr.i50" = phi i64 [ 7, %fact.exit48 ], [ %sub_res.i54, %cont0.i53 ]
  %cmp_lte_res.i51 = icmp slt i64 %"$0.tr.i50", 2
  br i1 %cmp_lte_res.i51, label %fact.exit56, label %cont0.i53

cont0.i53:                                        ; preds = %tailrecurse.i52
  %sub_res.i54 = add i64 %"$0.tr.i50", -1
  %mul_res.i55 = mul i64 %accumulator.tr.i49, %"$0.tr.i50"
  br label %tailrecurse.i52

fact.exit56:                                      ; preds = %tailrecurse.i52
  %accumulator.tr.i49.lcssa = phi i64 [ %accumulator.tr.i49, %tailrecurse.i52 ]
  store i64 %accumulator.tr.i49.lcssa, i64* %ptr.7, align 8
  %ptr.8 = getelementptr [9 x i64]* %arr65, i64 0, i64 8
  br label %tailrecurse.i60

tailrecurse.i60:                                  ; preds = %cont0.i61, %fact.exit56
  %accumulator.tr.i57 = phi i64 [ 1, %fact.exit56 ], [ %mul_res.i63, %cont0.i61 ]
  %"$0.tr.i58" = phi i64 [ 8, %fact.exit56 ], [ %sub_res.i62, %cont0.i61 ]
  %cmp_lte_res.i59 = icmp slt i64 %"$0.tr.i58", 2
  br i1 %cmp_lte_res.i59, label %fact.exit64, label %cont0.i61

cont0.i61:                                        ; preds = %tailrecurse.i60
  %sub_res.i62 = add i64 %"$0.tr.i58", -1
  %mul_res.i63 = mul i64 %accumulator.tr.i57, %"$0.tr.i58"
  br label %tailrecurse.i60

fact.exit64:                                      ; preds = %tailrecurse.i60
  %accumulator.tr.i57.lcssa = phi i64 [ %accumulator.tr.i57, %tailrecurse.i60 ]
  store i64 %accumulator.tr.i57.lcssa, i64* %ptr.8, align 8
  br label %loop2

loop2:                                            ; preds = %fact.exit64
  %element = load i64* %arr65.sub, align 8
  %0 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %element)
  %ptr6.1 = getelementptr [9 x i64]* %arr65, i64 0, i64 1
  %element.1 = load i64* %ptr6.1, align 8
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %element.1)
  %ptr6.2 = getelementptr [9 x i64]* %arr65, i64 0, i64 2
  %element.2 = load i64* %ptr6.2, align 8
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %element.2)
  %ptr6.3 = getelementptr [9 x i64]* %arr65, i64 0, i64 3
  %element.3 = load i64* %ptr6.3, align 8
  %3 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %element.3)
  %ptr6.4 = getelementptr [9 x i64]* %arr65, i64 0, i64 4
  %element.4 = load i64* %ptr6.4, align 8
  %4 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %element.4)
  %ptr6.5 = getelementptr [9 x i64]* %arr65, i64 0, i64 5
  %element.5 = load i64* %ptr6.5, align 8
  %5 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %element.5)
  %ptr6.6 = getelementptr [9 x i64]* %arr65, i64 0, i64 6
  %element.6 = load i64* %ptr6.6, align 8
  %6 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %element.6)
  %ptr6.7 = getelementptr [9 x i64]* %arr65, i64 0, i64 7
  %element.7 = load i64* %ptr6.7, align 8
  %7 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %element.7)
  %ptr6.8 = getelementptr [9 x i64]* %arr65, i64 0, i64 8
  %element.8 = load i64* %ptr6.8, align 8
  %8 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %element.8)
  ret i64 0
}

define i64 @fact(i64 %"$0") {
entry:
  br label %tailrecurse

tailrecurse:                                      ; preds = %else1, %entry
  %accumulator.tr = phi i64 [ 1, %entry ], [ %mul_res, %else1 ]
  %"$0.tr" = phi i64 [ %"$0", %entry ], [ %sub_res, %else1 ]
  %cmp_lte_res = icmp slt i64 %"$0.tr", 2
  br i1 %cmp_lte_res, label %then0, label %cont0

cont0:                                            ; preds = %tailrecurse
  br label %else1

then0:                                            ; preds = %tailrecurse
  ret i64 %accumulator.tr

else1:                                            ; preds = %cont0
  %sub_res = add i64 %"$0.tr", -1
  %mul_res = mul i64 %accumulator.tr, %"$0.tr"
  br label %tailrecurse
}

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture) #3

attributes #0 = { ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }
attributes #4 = { ssp }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
