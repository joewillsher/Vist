; ModuleID = 'stdlib.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@str = private unnamed_addr constant [6 x i8] c"false\00"
@str5 = private unnamed_addr constant [5 x i8] c"true\00"

; Function Attrs: noinline nounwind ssp uwtable
define void @"_$print_i64"(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i)
  ret void
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: noinline nounwind ssp uwtable
define void @"_$print_i32"(i32 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), i32 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @"_$print_f64"(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @"_$print_f32"(float %d) #0 {
  %1 = fpext float %d to double
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %1)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @"_$print_b"(i1 zeroext %b) #0 {
  br i1 %b, label %1, label %2

; <label>:1                                       ; preds = %0
  %puts1 = tail call i32 @puts(i8* getelementptr inbounds ([5 x i8]* @str5, i64 0, i64 0))
  br label %3

; <label>:2                                       ; preds = %0
  %puts = tail call i32 @puts(i8* getelementptr inbounds ([6 x i8]* @str, i64 0, i64 0))
  br label %3

; <label>:3                                       ; preds = %2, %1
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_Int_i64(i64 %v) #2 {
entry:
  %.fca.0.insert = insertvalue { i64 } undef, i64 %v, 0
  ret { i64 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_Int_() #2 {
entry:
  ret { i64 } zeroinitializer
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @_Bool_b(i1 %v) #2 {
entry:
  %.fca.0.insert = insertvalue { i1 } undef, i1 %v, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @_Bool_() #2 {
entry:
  ret { i1 } zeroinitializer
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @_Double_f64(double %v) #2 {
entry:
  %.fca.0.insert = insertvalue { double } undef, double %v, 0
  ret { double } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { { i64 }, { i64 } } @_Range_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") #2 {
entry:
  %"$0.fca.0.extract" = extractvalue { i64 } %"$0", 0
  %"$1.fca.0.extract" = extractvalue { i64 } %"$1", 0
  %.fca.0.0.insert = insertvalue { { i64 }, { i64 } } undef, i64 %"$0.fca.0.extract", 0, 0
  %.fca.1.0.insert = insertvalue { { i64 }, { i64 } } %.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret { { i64 }, { i64 } } %.fca.1.0.insert
}

; Function Attrs: alwaysinline nounwind
define void @_print_S.i64({ i64 } %a) #3 {
entry:
  %value = extractvalue { i64 } %a, 0
  tail call void @"_$print_i64"(i64 %value)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @_print_S.b({ i1 } %a) #3 {
entry:
  %value = extractvalue { i1 } %a, 0
  tail call void @"_$print_b"(i1 %value)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @_print_S.f64({ double } %a) #3 {
entry:
  %value = extractvalue { double } %a, 0
  tail call void @"_$print_f64"(double %value)
  ret void
}

; Function Attrs: alwaysinline noreturn nounwind
define void @_fatalError_() #4 {
entry:
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #5

; Function Attrs: alwaysinline nounwind
define void @_assert_S.b({ i1 } %"$0") #3 {
entry:
  %0 = extractvalue { i1 } %"$0", 0
  br i1 %0, label %then.0, label %else.1

then.0:                                           ; preds = %entry
  ret void

else.1:                                           ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline nounwind
define void @_condFail_b(i1 %"$0") #3 {
entry:
  br i1 %"$0", label %then.0, label %cont.stmt

cont.stmt:                                        ; preds = %entry
  ret void

then.0:                                           ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline nounwind
define { i64 } @"_+_S.i64_S.i64"({ i64 } %a, { i64 } %b) #3 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %add_res = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %value, i64 %value1)
  %add_res.fca.1.extract = extractvalue { i64, i1 } %add_res, 1
  br i1 %add_res.fca.1.extract, label %then.0.i, label %_condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_condFail_b.exit:                                 ; preds = %entry
  %add_res.fca.0.extract = extractvalue { i64, i1 } %add_res, 0
  %.fca.0.insert = insertvalue { i64 } undef, i64 %add_res.fca.0.extract, 0
  ret { i64 } %.fca.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind
define { i64 } @_-_S.i64_S.i64({ i64 } %a, { i64 } %b) #3 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %sub_res = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value, i64 %value1)
  %sub_res.fca.1.extract = extractvalue { i64, i1 } %sub_res, 1
  br i1 %sub_res.fca.1.extract, label %then.0.i, label %_condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_condFail_b.exit:                                 ; preds = %entry
  %sub_res.fca.0.extract = extractvalue { i64, i1 } %sub_res, 0
  %.fca.0.insert = insertvalue { i64 } undef, i64 %sub_res.fca.0.extract, 0
  ret { i64 } %.fca.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind
define { i64 } @"_*_S.i64_S.i64"({ i64 } %a, { i64 } %b) #3 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %value, i64 %value1)
  %mul_res.fca.1.extract = extractvalue { i64, i1 } %mul_res, 1
  br i1 %mul_res.fca.1.extract, label %then.0.i, label %_condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_condFail_b.exit:                                 ; preds = %entry
  %mul_res.fca.0.extract = extractvalue { i64, i1 } %mul_res, 0
  %.fca.0.insert = insertvalue { i64 } undef, i64 %mul_res.fca.0.extract, 0
  ret { i64 } %.fca.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @"_/_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %div_res = udiv i64 %value, %value1
  %.fca.0.insert = insertvalue { i64 } undef, i64 %div_res, 0
  ret { i64 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @"_%_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %rem_res = urem i64 %value, %value1
  %.fca.0.insert = insertvalue { i64 } undef, i64 %rem_res, 0
  ret { i64 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_<_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_lt_res = icmp slt i64 %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_lt_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_<=_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_lte_res = icmp sle i64 %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_lte_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_>_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_gt_res = icmp sgt i64 %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_gt_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_>=_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_gte_res = icmp sge i64 %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_gte_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_==_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_eq_res = icmp eq i64 %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_eq_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_!=_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_neq_res = icmp ne i64 %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_neq_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_&&_S.b_S.b"({ i1 } %a, { i1 } %b) #2 {
entry:
  %value = extractvalue { i1 } %a, 0
  %value1 = extractvalue { i1 } %b, 0
  %cmp_and_res = and i1 %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_and_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_||_S.b_S.b"({ i1 } %a, { i1 } %b) #2 {
entry:
  %value = extractvalue { i1 } %a, 0
  %value1 = extractvalue { i1 } %b, 0
  %cmp_or_res = or i1 %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_or_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @"_+_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %add_res = fadd double %value, %value1
  %.fca.0.insert = insertvalue { double } undef, double %add_res, 0
  ret { double } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @_-_S.f64_S.f64({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %sub_res = fsub double %value, %value1
  %.fca.0.insert = insertvalue { double } undef, double %sub_res, 0
  ret { double } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @"_*_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %mul_res = fmul double %value, %value1
  %.fca.0.insert = insertvalue { double } undef, double %mul_res, 0
  ret { double } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @"_/_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %div_res = fdiv double %value, %value1
  %.fca.0.insert = insertvalue { double } undef, double %div_res, 0
  ret { double } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @"_%_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %rem_res = frem double %value, %value1
  %.fca.0.insert = insertvalue { double } undef, double %rem_res, 0
  ret { double } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_<_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_lt_res = fcmp olt double %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_lt_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_<=_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_lte_res = fcmp ole double %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_lte_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_>_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_gt_res = fcmp ogt double %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_gt_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_>=_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_gte_res = fcmp oge double %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_gte_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_==_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_eq_res = fcmp oeq double %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_eq_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_!=_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_neq_res = fcmp one double %value, %value1
  %.fca.0.insert = insertvalue { i1 } undef, i1 %cmp_neq_res, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 } %a, { i64 } %b) #2 {
entry:
  %a.fca.0.extract = extractvalue { i64 } %a, 0
  %b.fca.0.extract = extractvalue { i64 } %b, 0
  %.fca.0.0.insert = insertvalue { { i64 }, { i64 } } undef, i64 %a.fca.0.extract, 0, 0
  %.fca.1.0.insert = insertvalue { { i64 }, { i64 } } %.fca.0.0.insert, i64 %b.fca.0.extract, 1, 0
  ret { { i64 }, { i64 } } %.fca.1.0.insert
}

; Function Attrs: alwaysinline nounwind
define { { i64 }, { i64 } } @"_..<_S.i64_S.i64"({ i64 } %a, { i64 } %b) #3 {
entry:
  %value.i = extractvalue { i64 } %b, 0
  %sub_res.i = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value.i, i64 1) #7
  %sub_res.i.fca.1.extract = extractvalue { i64, i1 } %sub_res.i, 1
  br i1 %sub_res.i.fca.1.extract, label %then.0.i.i, label %_-_S.i64_S.i64.exit

then.0.i.i:                                       ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_-_S.i64_S.i64.exit:                              ; preds = %entry
  %sub_res.i.fca.0.extract = extractvalue { i64, i1 } %sub_res.i, 0
  %a.fca.0.extract = extractvalue { i64 } %a, 0
  %.fca.0.0.insert = insertvalue { { i64 }, { i64 } } undef, i64 %a.fca.0.extract, 0, 0
  %.fca.1.0.insert = insertvalue { { i64 }, { i64 } } %.fca.0.0.insert, i64 %sub_res.i.fca.0.extract, 1, 0
  ret { { i64 }, { i64 } } %.fca.1.0.insert
}

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #7

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_Int_i641(i64) #2 {
  %.fca.0.insert.i = insertvalue { i64 } undef, i64 %0, 0
  ret { i64 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @_Bool_b2(i1) #2 {
  %.fca.0.insert.i = insertvalue { i1 } undef, i1 %0, 0
  ret { i1 } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @_Double_f643(double) #2 {
  %.fca.0.insert.i = insertvalue { double } undef, double %0, 0
  ret { double } %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define { { i64 }, { i64 } } @_Range_S.i64_S.i644({ i64 }, { i64 }) #2 {
  %"$0.fca.0.extract.i" = extractvalue { i64 } %0, 0
  %"$1.fca.0.extract.i" = extractvalue { i64 } %1, 0
  %.fca.0.0.insert.i = insertvalue { { i64 }, { i64 } } undef, i64 %"$0.fca.0.extract.i", 0, 0
  %.fca.1.0.insert.i = insertvalue { { i64 }, { i64 } } %.fca.0.0.insert.i, i64 %"$1.fca.0.extract.i", 1, 0
  ret { { i64 }, { i64 } } %.fca.1.0.insert.i
}

attributes #0 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline nounwind readnone }
attributes #3 = { alwaysinline nounwind }
attributes #4 = { alwaysinline noreturn nounwind }
attributes #5 = { noreturn nounwind }
attributes #6 = { nounwind readnone }
attributes #7 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
