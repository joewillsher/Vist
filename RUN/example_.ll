; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@str1 = private unnamed_addr constant [5 x i8] c"true\00"
@str = private unnamed_addr constant [6 x i8] c"false\00"

; Function Attrs: noinline nounwind ssp uwtable
define void @_print_i64(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i)
  ret void
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: noinline nounwind ssp uwtable
define void @_print_i32(i32 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), i32 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @_print_FP64(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @_print_FP32(float %d) #0 {
  %1 = fpext float %d to double
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %1)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @_print_b(i1 zeroext %b) #0 {
  br i1 %b, label %1, label %2

; <label>:1                                       ; preds = %0
  %puts1 = tail call i32 @puts(i8* getelementptr inbounds ([5 x i8]* @str1, i64 0, i64 0))
  br label %3

; <label>:2                                       ; preds = %0
  %puts = tail call i32 @puts(i8* getelementptr inbounds ([6 x i8]* @str, i64 0, i64 0))
  br label %3

; <label>:3                                       ; preds = %2, %1
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_Int_S.i64({ i64 } %o) #2 {
entry:
  ret { i64 } %o
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_Int_i64(i64 %v) #2 {
entry:
  %.fca.0.insert = insertvalue { i64 } undef, i64 %v, 0
  ret { i64 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @_Bool_S.b({ i1 } %o) #2 {
entry:
  ret { i1 } %o
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @_Bool_b(i1 %v) #2 {
entry:
  %.fca.0.insert = insertvalue { i1 } undef, i1 %v, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @_Double_S.FP64({ double } %o) #2 {
entry:
  ret { double } %o
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @_Double_FP64(double %v) #2 {
entry:
  %.fca.0.insert = insertvalue { double } undef, double %v, 0
  ret { double } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind
define void @_print_S.i64({ i64 } %a) #3 {
entry:
  %value = extractvalue { i64 } %a, 0
  tail call void @_print_i64(i64 %value)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @_print_S.b({ i1 } %a) #3 {
entry:
  %value = extractvalue { i1 } %a, 0
  tail call void @_print_b(i1 %value)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @_print_S.FP64({ double } %a) #3 {
entry:
  %value = extractvalue { double } %a, 0
  tail call void @_print_FP64(double %value)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @"_+_S.FP64S.FP64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %add_res = fadd double %value, %value1
  %.fca.0.insert.i = insertvalue { double } undef, double %add_res, 0
  ret { double } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @"_+_S.i64S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %add_res = add i64 %value1, %value
  %.fca.0.insert.i = insertvalue { i64 } undef, i64 %add_res, 0
  ret { i64 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_-_S.i64S.i64({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %sub_res = sub i64 %value, %value1
  %.fca.0.insert.i = insertvalue { i64 } undef, i64 %sub_res, 0
  ret { i64 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @"_*_S.i64S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %mul_res = mul i64 %value1, %value
  %.fca.0.insert.i = insertvalue { i64 } undef, i64 %mul_res, 0
  ret { i64 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @"_/_S.i64S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %div_res = udiv i64 %value, %value1
  %.fca.0.insert.i = insertvalue { i64 } undef, i64 %div_res, 0
  ret { i64 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @"_%_S.i64S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %rem_res = urem i64 %value, %value1
  %.fca.0.insert.i = insertvalue { i64 } undef, i64 %rem_res, 0
  ret { i64 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_<_S.i64S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_lt_res = icmp slt i64 %value, %value1
  %.fca.0.insert.i = insertvalue { i1 } undef, i1 %cmp_lt_res, 0
  ret { i1 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_<=_S.i64S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_lte_res = icmp sle i64 %value, %value1
  %.fca.0.insert.i = insertvalue { i1 } undef, i1 %cmp_lte_res, 0
  ret { i1 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_>_S.i64S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_gt_res = icmp sgt i64 %value, %value1
  %.fca.0.insert.i = insertvalue { i1 } undef, i1 %cmp_gt_res, 0
  ret { i1 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_>=_S.i64S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_gte_res = icmp sge i64 %value, %value1
  %.fca.0.insert.i = insertvalue { i1 } undef, i1 %cmp_gte_res, 0
  ret { i1 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_==_S.i64S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_eq_res = icmp eq i64 %value, %value1
  %.fca.0.insert.i = insertvalue { i1 } undef, i1 %cmp_eq_res, 0
  ret { i1 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_!=_S.i64S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_neq_res = icmp ne i64 %value, %value1
  %.fca.0.insert.i = insertvalue { i1 } undef, i1 %cmp_neq_res, 0
  ret { i1 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_&&_S.bS.b"({ i1 } %a, { i1 } %b) #2 {
entry:
  %value = extractvalue { i1 } %a, 0
  %value1 = extractvalue { i1 } %b, 0
  %cmp_and_res = and i1 %value, %value1
  %.fca.0.insert.i = insertvalue { i1 } undef, i1 %cmp_and_res, 0
  ret { i1 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_||_S.bS.b"({ i1 } %a, { i1 } %b) #2 {
entry:
  %value = extractvalue { i1 } %a, 0
  %value1 = extractvalue { i1 } %b, 0
  %cmp_or_res = or i1 %value, %value1
  %.fca.0.insert.i = insertvalue { i1 } undef, i1 %cmp_or_res, 0
  ret { i1 } %.fca.0.insert.i
}

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #4

define i64 @main() {
entry:
  br label %loop

loop:                                             ; preds = %loop, %entry
  %i = phi i64 [ 0, %entry ], [ %nexti, %loop ]
  %nexti = add i64 1, %i
  call void @_print_i64(i64 %i)
  %looptest = icmp sle i64 %nexti, 10
  br i1 %looptest, label %loop, label %afterloop

afterloop:                                        ; preds = %loop
  %Int = call { i64 } @_Int_i64(i64 1)
  %0 = alloca { i64 }
  store { i64 } %Int, { i64 }* %0
  %Int1 = call { i64 } @_Int_i64(i64 3)
  %1 = alloca { i64 }
  store { i64 } %Int1, { i64 }* %1
  %a = load { i64 }* %0
  %b = load { i64 }* %1
  %">" = call { i1 } @"_>_S.i64S.i64"({ i64 } %a, { i64 } %b)
  %b2 = extractvalue { i1 } %">", 0
  br i1 %b2, label %then0, label %cont0

cont:                                             ; preds = %cont0, %then1, %then0
  %Int6 = call { i64 } @_Int_i64(i64 1)
  %2 = alloca { i64 }
  store { i64 } %Int6, { i64 }* %2
  %Int7 = call { i64 } @_Int_i64(i64 1)
  %3 = alloca { i64 }
  store { i64 } %Int7, { i64 }* %3
  %Int8 = call { i64 } @_Int_i64(i64 1000000000)
  %4 = alloca { i64 }
  store { i64 } %Int8, { i64 }* %4
  %x = load { i64 }* %2
  %h = load { i64 }* %4
  %"<11" = call { i1 } @"_<_S.i64S.i64"({ i64 } %x, { i64 } %h)
  %b12 = extractvalue { i1 } %"<11", 0
  br i1 %b12, label %loop9, label %afterloop10

cont0:                                            ; preds = %afterloop
  %a3 = load { i64 }* %0
  %b4 = load { i64 }* %1
  %"<" = call { i1 } @"_<_S.i64S.i64"({ i64 } %a3, { i64 } %b4)
  %b5 = extractvalue { i1 } %"<", 0
  br i1 %b5, label %then1, label %cont

then0:                                            ; preds = %afterloop
  call void @_print_i64(i64 1)
  br label %cont

then1:                                            ; preds = %cont0
  call void @_print_i64(i64 100)
  br label %cont

loop9:                                            ; preds = %loop9, %cont
  %y = load { i64 }* %3
  %5 = alloca { i64 }
  store { i64 } %y, { i64 }* %5
  %t = load { i64 }* %5
  %x13 = load { i64 }* %2
  %"+" = call { i64 } @"_+_S.i64S.i64"({ i64 } %t, { i64 } %x13)
  store { i64 } %"+", { i64 }* %3
  %t14 = load { i64 }* %5
  store { i64 } %t14, { i64 }* %2
  %x15 = load { i64 }* %2
  call void @_print_S.i64({ i64 } %x15)
  %x16 = load { i64 }* %2
  %h17 = load { i64 }* %4
  %"<18" = call { i1 } @"_<_S.i64S.i64"({ i64 } %x16, { i64 } %h17)
  %b19 = extractvalue { i1 } %"<18", 0
  br i1 %b19, label %loop9, label %afterloop10

afterloop10:                                      ; preds = %loop9, %cont
  ret i64 0
}

attributes #0 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline nounwind readnone }
attributes #3 = { alwaysinline nounwind }
attributes #4 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
