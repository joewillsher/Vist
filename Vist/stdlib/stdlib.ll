; ModuleID = 'stdlib.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Int32.st = type { i32 }
%Bool.st = type { i1 }
%Double.st = type { double }
%Range.st = type { %Int.st, %Int.st }

@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@str = private unnamed_addr constant [6 x i8] c"false\00"
@str6 = private unnamed_addr constant [5 x i8] c"true\00"

; Function Attrs: noinline nounwind ssp uwtable
define void @-Uprint_i64(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i)
  ret void
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: noinline nounwind ssp uwtable
define void @-Uprint_i32(i32 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), i32 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @-Uprint_f64(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @-Uprint_f32(float %d) #0 {
  %1 = fpext float %d to double
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %1)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @-Uprint_b(i1 zeroext %b) #0 {
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
define %Int.st @Int_i64(i64 %v) #2 {
entry:
  %Int1.fca.0.insert = insertvalue %Int.st undef, i64 %v, 0
  ret %Int.st %Int1.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Int.st @Int_() #2 {
entry:
  ret %Int.st zeroinitializer
}

; Function Attrs: alwaysinline nounwind readnone
define %Int32.st @Int32_i32(i32 %v) #2 {
entry:
  %Int321.fca.0.insert = insertvalue %Int32.st undef, i32 %v, 0
  ret %Int32.st %Int321.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @Bool_b(i1 %v) #2 {
entry:
  %Bool1.fca.0.insert = insertvalue %Bool.st undef, i1 %v, 0
  ret %Bool.st %Bool1.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @Bool_() #2 {
entry:
  ret %Bool.st zeroinitializer
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.st @Double_f64(double %v) #2 {
entry:
  %Double1.fca.0.insert = insertvalue %Double.st undef, double %v, 0
  ret %Double.st %Double1.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Range.st @Range_Int_Int(%Int.st %"$0", %Int.st %"$1") #2 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int.st %"$1", 0
  %Range1.fca.0.0.insert = insertvalue %Range.st undef, i64 %"$0.fca.0.extract", 0, 0
  %Range1.fca.1.0.insert = insertvalue %Range.st %Range1.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret %Range.st %Range1.fca.1.0.insert
}

; Function Attrs: alwaysinline nounwind
define void @print_Int(%Int.st %a) #3 {
entry:
  %value = extractvalue %Int.st %a, 0
  tail call void @-Uprint_i64(i64 %value)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @print_Int32(%Int32.st %a) #3 {
entry:
  %value = extractvalue %Int32.st %a, 0
  tail call void @-Uprint_i32(i32 %value)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @print_Bool(%Bool.st %a) #3 {
entry:
  %value = extractvalue %Bool.st %a, 0
  tail call void @-Uprint_b(i1 %value)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @print_Double(%Double.st %a) #3 {
entry:
  %value = extractvalue %Double.st %a, 0
  tail call void @-Uprint_f64(double %value)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-Uexpect_Bool_Bool(%Bool.st %val, %Bool.st %assume) #2 {
entry:
  ret %Bool.st %val
}

; Function Attrs: alwaysinline noreturn nounwind
define void @fatalError_() #4 {
entry:
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #5

; Function Attrs: alwaysinline nounwind
define void @assert_Bool(%Bool.st %"$0") #3 {
entry:
  %value.i = extractvalue %Bool.st %"$0", 0
  br i1 %value.i, label %then.0, label %else.1

then.0:                                           ; preds = %entry
  ret void

else.1:                                           ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline nounwind
define void @condFail_b(i1 %cond) #3 {
entry:
  br i1 %cond, label %then.0, label %cont.stmt

cont.stmt:                                        ; preds = %entry
  ret void

then.0:                                           ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline nounwind
define %Int.st @-P_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %add_res = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %value, i64 %value1)
  %add_res.fca.1.extract = extractvalue { i64, i1 } %add_res, 1
  br i1 %add_res.fca.1.extract, label %then.0.i, label %condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

condFail_b.exit:                                  ; preds = %entry
  %add_res.fca.0.extract = extractvalue { i64, i1 } %add_res, 0
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %add_res.fca.0.extract, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind
define %Int.st @-M_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %sub_res = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value, i64 %value1)
  %sub_res.fca.1.extract = extractvalue { i64, i1 } %sub_res, 1
  br i1 %sub_res.fca.1.extract, label %then.0.i, label %condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

condFail_b.exit:                                  ; preds = %entry
  %sub_res.fca.0.extract = extractvalue { i64, i1 } %sub_res, 0
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %sub_res.fca.0.extract, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind
define %Int.st @-A_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %value, i64 %value1)
  %mul_res.fca.1.extract = extractvalue { i64, i1 } %mul_res, 1
  br i1 %mul_res.fca.1.extract, label %then.0.i, label %condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

condFail_b.exit:                                  ; preds = %entry
  %mul_res.fca.0.extract = extractvalue { i64, i1 } %mul_res, 0
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %mul_res.fca.0.extract, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-E-E_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %cmp_eq_res = icmp eq i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_eq_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @"!-E_Int_Int"(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %cmp_neq_res = icmp ne i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_neq_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind
define %Int.st @-D_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %value.i = extractvalue %Int.st %b, 0
  %cmp_neq_res.i = icmp eq i64 %value.i, 0
  br i1 %cmp_neq_res.i, label %else.1.i, label %assert_Bool.exit

else.1.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

assert_Bool.exit:                                 ; preds = %entry
  %value = extractvalue %Int.st %a, 0
  %div_res = udiv i64 %value, %value.i
  %Int1.i4.fca.0.insert = insertvalue %Int.st undef, i64 %div_res, 0
  ret %Int.st %Int1.i4.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Int.st @"%_Int_Int"(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %rem_res = urem i64 %value, %value1
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %rem_res, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-L_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %cmp_lt_res = icmp slt i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_lt_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-L-E_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %cmp_lte_res = icmp sle i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_lte_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-G_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %cmp_gt_res = icmp sgt i64 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_gt_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Int.st @-L-L_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %shl_res = shl i64 %value, %value1
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %shl_res, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Int.st @-G-G_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %shr_res = ashr i64 %value, %value1
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %shr_res, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Int.st @-T-N_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %and_res = and i64 %value1, %value
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %and_res, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Int.st @-T-O_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %or_res = or i64 %value1, %value
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %or_res, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Int.st @-T-R_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %value = extractvalue %Int.st %a, 0
  %value1 = extractvalue %Int.st %b, 0
  %xor_res = xor i64 %value1, %value
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %xor_res, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-N-N_Bool_Bool(%Bool.st %a, %Bool.st %b) #2 {
entry:
  %value = extractvalue %Bool.st %a, 0
  %value1 = extractvalue %Bool.st %b, 0
  %cmp_and_res = and i1 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_and_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-O-O_Bool_Bool(%Bool.st %a, %Bool.st %b) #2 {
entry:
  %value = extractvalue %Bool.st %a, 0
  %value1 = extractvalue %Bool.st %b, 0
  %cmp_or_res = or i1 %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_or_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.st @-P_Double_Double(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %add_res = fadd double %value, %value1
  %Double1.i.fca.0.insert = insertvalue %Double.st undef, double %add_res, 0
  ret %Double.st %Double1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.st @-M_Double_Double(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %sub_res = fsub double %value, %value1
  %Double1.i.fca.0.insert = insertvalue %Double.st undef, double %sub_res, 0
  ret %Double.st %Double1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.st @-A_Double_Double(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %mul_res = fmul double %value, %value1
  %Double1.i.fca.0.insert = insertvalue %Double.st undef, double %mul_res, 0
  ret %Double.st %Double1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.st @-D_Double_Double(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %div_res = fdiv double %value, %value1
  %Double1.i.fca.0.insert = insertvalue %Double.st undef, double %div_res, 0
  ret %Double.st %Double1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.st @"%_Double_Double"(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %rem_res = frem double %value, %value1
  %Double1.i.fca.0.insert = insertvalue %Double.st undef, double %rem_res, 0
  ret %Double.st %Double1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-L_Double_Double(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %cmp_lt_res = fcmp olt double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_lt_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-L-E_Double_Double(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %cmp_lte_res = fcmp ole double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_lte_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-G_Double_Double(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %cmp_gt_res = fcmp ogt double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_gt_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-G-E_Double_Double(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %cmp_gte_res = fcmp oge double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_gte_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @-E-E_Double_Double(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %cmp_eq_res = fcmp oeq double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_eq_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @"!-E_Double_Double"(%Double.st %a, %Double.st %b) #2 {
entry:
  %value = extractvalue %Double.st %a, 0
  %value1 = extractvalue %Double.st %b, 0
  %cmp_neq_res = fcmp one double %value, %value1
  %Bool1.i.fca.0.insert = insertvalue %Bool.st undef, i1 %cmp_neq_res, 0
  ret %Bool.st %Bool1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Range.st @..._Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %a.fca.0.extract = extractvalue %Int.st %a, 0
  %b.fca.0.extract = extractvalue %Int.st %b, 0
  %Range1.i.fca.0.0.insert = insertvalue %Range.st undef, i64 %a.fca.0.extract, 0, 0
  %Range1.i.fca.1.0.insert = insertvalue %Range.st %Range1.i.fca.0.0.insert, i64 %b.fca.0.extract, 1, 0
  ret %Range.st %Range1.i.fca.1.0.insert
}

; Function Attrs: alwaysinline nounwind
define %Range.st @..-L_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %value.i = extractvalue %Int.st %b, 0
  %sub_res.i = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value.i, i64 1) #7
  %sub_res.i.fca.1.extract = extractvalue { i64, i1 } %sub_res.i, 1
  br i1 %sub_res.i.fca.1.extract, label %then.0.i.i, label %-M_Int_Int.exit

then.0.i.i:                                       ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

-M_Int_Int.exit:                                  ; preds = %entry
  %sub_res.i.fca.0.extract = extractvalue { i64, i1 } %sub_res.i, 0
  %a.fca.0.extract = extractvalue %Int.st %a, 0
  %Range1.i.fca.0.0.insert = insertvalue %Range.st undef, i64 %a.fca.0.extract, 0, 0
  %Range1.i.fca.1.0.insert = insertvalue %Range.st %Range1.i.fca.0.0.insert, i64 %sub_res.i.fca.0.extract, 1, 0
  ret %Range.st %Range1.i.fca.1.0.insert
}

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #7

; Function Attrs: alwaysinline nounwind readnone
define %Int.st @Int_i641(i64) #2 {
  %Int1.fca.0.insert.i = insertvalue %Int.st undef, i64 %0, 0
  ret %Int.st %Int1.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Int32.st @Int32_i322(i32) #2 {
  %Int321.fca.0.insert.i = insertvalue %Int32.st undef, i32 %0, 0
  ret %Int32.st %Int321.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool.st @Bool_b3(i1) #2 {
  %Bool1.fca.0.insert.i = insertvalue %Bool.st undef, i1 %0, 0
  ret %Bool.st %Bool1.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Double.st @Double_f644(double) #2 {
  %Double1.fca.0.insert.i = insertvalue %Double.st undef, double %0, 0
  ret %Double.st %Double1.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Range.st @Range_Int_Int5(%Int.st, %Int.st) #2 {
  %"$0.fca.0.extract.i" = extractvalue %Int.st %0, 0
  %"$1.fca.0.extract.i" = extractvalue %Int.st %1, 0
  %Range1.fca.0.0.insert.i = insertvalue %Range.st undef, i64 %"$0.fca.0.extract.i", 0, 0
  %Range1.fca.1.0.insert.i = insertvalue %Range.st %Range1.fca.0.0.insert.i, i64 %"$1.fca.0.extract.i", 1, 0
  ret %Range.st %Range1.fca.1.0.insert.i
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
