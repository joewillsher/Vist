; ModuleID = 'stdlib.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.ty = type { i64 }
%Int32.ty = type { i32 }
%Bool.ty = type { i1 }
%Double.ty = type { double }
%Range.ty = type { %Int.ty, %Int.ty }

@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@str = private unnamed_addr constant [6 x i8] c"false\00"
@str6 = private unnamed_addr constant [5 x i8] c"true\00"

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
  %puts1 = tail call i32 @puts(i8* getelementptr inbounds ([5 x i8]* @str6, i64 0, i64 0))
  br label %3

; <label>:2                                       ; preds = %0
  %puts = tail call i32 @puts(i8* getelementptr inbounds ([6 x i8]* @str, i64 0, i64 0))
  br label %3

; <label>:3                                       ; preds = %2, %1
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Int.ty @_Int_i64(i64 %v) #2 {
entry:
  %Int1.fca.0.insert = insertvalue %Int.ty undef, i64 %v, 0
  ret %Int.ty %Int1.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Int.ty @_Int_() #2 {
entry:
  ret %Int.ty zeroinitializer
}

; Function Attrs: alwaysinline nounwind readnone
define %Int32.ty @_Int32_i32(i32 %v) #2 {
entry:
  %Int321.fca.0.insert = insertvalue %Int32.ty undef, i32 %v, 0
  ret %Int32.ty %Int321.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @_Bool_b(i1 %v) #2 {
entry:
  %Bool1.fca.0.insert = insertvalue %Bool.ty undef, i1 %v, 0
  ret %Bool.ty %Bool1.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @_Bool_() #2 {
entry:
  ret %Bool.ty zeroinitializer
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.ty @_Double_f64(double %v) #2 {
entry:
  %Double1.fca.0.insert = insertvalue %Double.ty undef, double %v, 0
  ret %Double.ty %Double1.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Range.ty @_Range_Int_Int(%Int.ty %"$0", %Int.ty %"$1") #2 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.ty %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int.ty %"$1", 0
  %Range1.fca.0.0.insert = insertvalue %Range.ty undef, i64 %"$0.fca.0.extract", 0, 0
  %Range1.fca.1.0.insert = insertvalue %Range.ty %Range1.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret %Range.ty %Range1.fca.1.0.insert
}

; Function Attrs: alwaysinline nounwind
define void @_print_Int(%Int.ty %a) #3 {
entry:
  %value = extractvalue %Int.ty %a, 0
  tail call void @"_$print_i64"(i64 %value)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @_print_Int32(%Int32.ty %a) #3 {
entry:
  %value = extractvalue %Int32.ty %a, 0
  tail call void @"_$print_i32"(i32 %value)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @_print_Bool(%Bool.ty %a) #3 {
entry:
  %value = extractvalue %Bool.ty %a, 0
  tail call void @"_$print_b"(i1 %value)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @_print_Double(%Double.ty %a) #3 {
entry:
  %value = extractvalue %Double.ty %a, 0
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
define void @_assert_Bool(%Bool.ty %"$0") #3 {
entry:
  %0 = extractvalue %Bool.ty %"$0", 0
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
define %Int.ty @"_+_Int_Int"(%Int.ty %a, %Int.ty %b) #3 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %add_res = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %value, i64 %value1)
  %add_res.fca.1.extract = extractvalue { i64, i1 } %add_res, 1
  br i1 %add_res.fca.1.extract, label %then.0.i, label %_condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_condFail_b.exit:                                 ; preds = %entry
  %add_res.fca.0.extract = extractvalue { i64, i1 } %add_res, 0
  %Int1.i.fca.0.insert = insertvalue %Int.ty undef, i64 %add_res.fca.0.extract, 0
  ret %Int.ty %Int1.i.fca.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind
define %Int.ty @_-_Int_Int(%Int.ty %a, %Int.ty %b) #3 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %sub_res = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value, i64 %value1)
  %sub_res.fca.1.extract = extractvalue { i64, i1 } %sub_res, 1
  br i1 %sub_res.fca.1.extract, label %then.0.i, label %_condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_condFail_b.exit:                                 ; preds = %entry
  %sub_res.fca.0.extract = extractvalue { i64, i1 } %sub_res, 0
  %Int1.i.fca.0.insert = insertvalue %Int.ty undef, i64 %sub_res.fca.0.extract, 0
  ret %Int.ty %Int1.i.fca.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind
define %Int.ty @"_*_Int_Int"(%Int.ty %a, %Int.ty %b) #3 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %value, i64 %value1)
  %mul_res.fca.1.extract = extractvalue { i64, i1 } %mul_res, 1
  br i1 %mul_res.fca.1.extract, label %then.0.i, label %_condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_condFail_b.exit:                                 ; preds = %entry
  %mul_res.fca.0.extract = extractvalue { i64, i1 } %mul_res, 0
  %Int1.i.fca.0.insert = insertvalue %Int.ty undef, i64 %mul_res.fca.0.extract, 0
  ret %Int.ty %Int1.i.fca.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind readnone
define %Int.ty @"_/_Int_Int"(%Int.ty %a, %Int.ty %b) #2 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %div_res = udiv i64 %value, %value1
  %Int1.i.fca.0.insert = insertvalue %Int.ty undef, i64 %div_res, 0
  ret %Int.ty %Int1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Int.ty @"_%_Int_Int"(%Int.ty %a, %Int.ty %b) #2 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %rem_res = urem i64 %value, %value1
  %Int1.i.fca.0.insert = insertvalue %Int.ty undef, i64 %rem_res, 0
  ret %Int.ty %Int1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_<_Int_Int"(%Int.ty %a, %Int.ty %b) #2 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %cmp_lt_res = icmp slt i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_lt_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_<=_Int_Int"(%Int.ty %a, %Int.ty %b) #2 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %cmp_lte_res = icmp sle i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_lte_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_>_Int_Int"(%Int.ty %a, %Int.ty %b) #2 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %cmp_gt_res = icmp sgt i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_gt_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_>=_Int_Int"(%Int.ty %a, %Int.ty %b) #2 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %cmp_gte_res = icmp sge i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_gte_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_==_Int_Int"(%Int.ty %a, %Int.ty %b) #2 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %cmp_eq_res = icmp eq i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_eq_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_!=_Int_Int"(%Int.ty %a, %Int.ty %b) #2 {
entry:
  %value = extractvalue %Int.ty %a, 0
  %value1 = extractvalue %Int.ty %b, 0
  %cmp_neq_res = icmp ne i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_neq_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_&&_Bool_Bool"(%Bool.ty %a, %Bool.ty %b) #2 {
entry:
  %value = extractvalue %Bool.ty %a, 0
  %value1 = extractvalue %Bool.ty %b, 0
  %cmp_and_res = and i1 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_and_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_||_Bool_Bool"(%Bool.ty %a, %Bool.ty %b) #2 {
entry:
  %value = extractvalue %Bool.ty %a, 0
  %value1 = extractvalue %Bool.ty %b, 0
  %cmp_or_res = or i1 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_or_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.ty @"_+_Double_Double"(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %add_res = fadd double %value, %value1
  %Double1.i.fca.0.insert = insertvalue %Double.ty undef, double %add_res, 0
  ret %Double.ty %Double1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.ty @_-_Double_Double(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %sub_res = fsub double %value, %value1
  %Double1.i.fca.0.insert = insertvalue %Double.ty undef, double %sub_res, 0
  ret %Double.ty %Double1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.ty @"_*_Double_Double"(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %mul_res = fmul double %value, %value1
  %Double1.i.fca.0.insert = insertvalue %Double.ty undef, double %mul_res, 0
  ret %Double.ty %Double1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.ty @"_/_Double_Double"(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %div_res = fdiv double %value, %value1
  %Double1.i.fca.0.insert = insertvalue %Double.ty undef, double %div_res, 0
  ret %Double.ty %Double1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.ty @"_%_Double_Double"(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %rem_res = frem double %value, %value1
  %Double1.i.fca.0.insert = insertvalue %Double.ty undef, double %rem_res, 0
  ret %Double.ty %Double1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_<_Double_Double"(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %cmp_lt_res = fcmp olt double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_lt_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_<=_Double_Double"(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %cmp_lte_res = fcmp ole double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_lte_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_>_Double_Double"(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %cmp_gt_res = fcmp ogt double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_gt_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_>=_Double_Double"(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %cmp_gte_res = fcmp oge double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_gte_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_==_Double_Double"(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %cmp_eq_res = fcmp oeq double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_eq_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @"_!=_Double_Double"(%Double.ty %a, %Double.ty %b) #2 {
entry:
  %value = extractvalue %Double.ty %a, 0
  %value1 = extractvalue %Double.ty %b, 0
  %cmp_neq_res = fcmp one double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.ty undef, i1 %cmp_neq_res, 0
  ret %Bool.ty %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Range.ty @_..._Int_Int(%Int.ty %a, %Int.ty %b) #2 {
entry:
  %a.fca.0.extract = extractvalue %Int.ty %a, 0
  %b.fca.0.extract = extractvalue %Int.ty %b, 0
  %Range1.i.fca.0.0.insert = insertvalue %Range.ty undef, i64 %a.fca.0.extract, 0, 0
  %Range1.i.fca.1.0.insert = insertvalue %Range.ty %Range1.i.fca.0.0.insert, i64 %b.fca.0.extract, 1, 0
  ret %Range.ty %Range1.i.fca.1.0.insert
}

; Function Attrs: alwaysinline nounwind
define %Range.ty @"_..<_Int_Int"(%Int.ty %a, %Int.ty %b) #3 {
entry:
  %value.i = extractvalue %Int.ty %b, 0
  %sub_res.i = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value.i, i64 1) #7
  %sub_res.i.fca.1.extract = extractvalue { i64, i1 } %sub_res.i, 1
  br i1 %sub_res.i.fca.1.extract, label %then.0.i.i, label %_-_Int_Int.exit

then.0.i.i:                                       ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_-_Int_Int.exit:                                  ; preds = %entry
  %sub_res.i.fca.0.extract = extractvalue { i64, i1 } %sub_res.i, 0
  %a.fca.0.extract = extractvalue %Int.ty %a, 0
  %Range1.i.fca.0.0.insert = insertvalue %Range.ty undef, i64 %a.fca.0.extract, 0, 0
  %Range1.i.fca.1.0.insert = insertvalue %Range.ty %Range1.i.fca.0.0.insert, i64 %sub_res.i.fca.0.extract, 1, 0
  ret %Range.ty %Range1.i.fca.1.0.insert
}

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #7

; Function Attrs: alwaysinline nounwind readnone
define %Int.ty @_Int_i641(i64) #2 {
  %Int1.fca.0.insert.i = insertvalue %Int.ty undef, i64 %0, 0
  ret %Int.ty %Int1.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Int32.ty @_Int32_i322(i32) #2 {
  %Int321.fca.0.insert.i = insertvalue %Int32.ty undef, i32 %0, 0
  ret %Int32.ty %Int321.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.ty @_Bool_b3(i1) #2 {
  %Bool1.fca.0.insert.i = insertvalue %Bool.ty undef, i1 %0, 0
  ret %Bool.ty %Bool1.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.ty @_Double_f644(double) #2 {
  %Double1.fca.0.insert.i = insertvalue %Double.ty undef, double %0, 0
  ret %Double.ty %Double1.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Range.ty @_Range_Int_Int5(%Int.ty, %Int.ty) #2 {
  %"$0.fca.0.extract.i" = extractvalue %Int.ty %0, 0
  %"$1.fca.0.extract.i" = extractvalue %Int.ty %1, 0
  %Range1.fca.0.0.insert.i = insertvalue %Range.ty undef, i64 %"$0.fca.0.extract.i", 0, 0
  %Range1.fca.1.0.insert.i = insertvalue %Range.ty %Range1.fca.0.0.insert.i, i64 %"$1.fca.0.extract.i", 1, 0
  ret %Range.ty %Range1.fca.1.0.insert.i
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
