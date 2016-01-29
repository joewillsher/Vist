; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@str = private unnamed_addr constant [6 x i8] c"false\00"
@str1 = private unnamed_addr constant [5 x i8] c"true\00"

; Function Attrs: noinline nounwind ssp uwtable
define void @"_$print_i64"(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i64 %i)
  ret void
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: noinline nounwind ssp uwtable
define void @"_$print_i32"(i32 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @"_$print_f64"(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %d)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @"_$print_f32"(float %d) #0 {
  %1 = fpext float %d to double
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %1)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @"_$print_b"(i1 zeroext %b) #0 {
  br i1 %b, label %1, label %2

; <label>:1                                       ; preds = %0
  %puts1 = tail call i32 @puts(i8* getelementptr inbounds ([5 x i8]* @str1, i32 0, i32 0))
  br label %3

; <label>:2                                       ; preds = %0
  %puts = tail call i32 @puts(i8* getelementptr inbounds ([6 x i8]* @str, i32 0, i32 0))
  br label %3

; <label>:3                                       ; preds = %2, %1
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_Int_S.i64({ i64 } %o) #2 {
entry:
  %0 = alloca { i64 }
  %value = extractvalue { i64 } %o, 0
  %value_ptr = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %value, i64* %value_ptr
  %1 = load { i64 }* %0
  ret { i64 } %1
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_Int_i64(i64 %v) #2 {
entry:
  %0 = alloca { i64 }
  %value_ptr = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %v, i64* %value_ptr
  %1 = load { i64 }* %0
  ret { i64 } %1
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_Int_() #2 {
entry:
  %0 = alloca { i64 }
  %1 = alloca { i64 }
  %2 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %2)
  %value_ptr.i = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 0, i64* %value_ptr.i
  %3 = load { i64 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %2)
  %4 = alloca { i64 }
  store { i64 } %3, { i64 }* %4
  %value_ptr = getelementptr inbounds { i64 }* %4, i32 0, i32 0
  %value = load i64* %value_ptr
  %value_ptr1 = getelementptr inbounds { i64 }* %1, i32 0, i32 0
  store i64 %value, i64* %value_ptr1
  %5 = load { i64 }* %1
  ret { i64 } %5
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @_Bool_S.b({ i1 } %o) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { i1 } %o, 0
  %value_ptr = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %value, i1* %value_ptr
  %1 = load { i1 }* %0
  ret { i1 } %1
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @_Bool_b(i1 %v) #2 {
entry:
  %0 = alloca { i1 }
  %value_ptr = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %v, i1* %value_ptr
  %1 = load { i1 }* %0
  ret { i1 } %1
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @_Bool_() #2 {
entry:
  %0 = alloca { i1 }
  %1 = alloca { i1 }
  %2 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %2)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 false, i1* %value_ptr.i
  %3 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %2)
  %4 = alloca { i1 }
  store { i1 } %3, { i1 }* %4
  %value_ptr = getelementptr inbounds { i1 }* %4, i32 0, i32 0
  %value = load i1* %value_ptr
  %value_ptr1 = getelementptr inbounds { i1 }* %1, i32 0, i32 0
  store i1 %value, i1* %value_ptr1
  %5 = load { i1 }* %1
  ret { i1 } %5
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @_Double_S.f64({ double } %o) #2 {
entry:
  %0 = alloca { double }
  %value = extractvalue { double } %o, 0
  %value_ptr = getelementptr inbounds { double }* %0, i32 0, i32 0
  store double %value, double* %value_ptr
  %1 = load { double }* %0
  ret { double } %1
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @_Double_f64(double %v) #2 {
entry:
  %0 = alloca { double }
  %value_ptr = getelementptr inbounds { double }* %0, i32 0, i32 0
  store double %v, double* %value_ptr
  %1 = load { double }* %0
  ret { double } %1
}

; Function Attrs: alwaysinline nounwind readnone
define { { i64 }, { i64 } } @_Range_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") #2 {
entry:
  %0 = alloca { { i64 }, { i64 } }
  %start_ptr = getelementptr inbounds { { i64 }, { i64 } }* %0, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %start_ptr
  %end_ptr = getelementptr inbounds { { i64 }, { i64 } }* %0, i32 0, i32 1
  store { i64 } %"$1", { i64 }* %end_ptr
  %1 = load { { i64 }, { i64 } }* %0
  ret { { i64 }, { i64 } } %1
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
  %value = extractvalue { i1 } %"$0", 0
  br i1 %value, label %then.0, label %else.1

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
  %0 = alloca { i64 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %add_res = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %value, i64 %value1)
  %1 = alloca { i64, i1 }
  store { i64, i1 } %add_res, { i64, i1 }* %1
  %"1_ptr" = getelementptr inbounds { i64, i1 }* %1, i32 0, i32 1
  %"1" = load i1* %"1_ptr"
  br i1 %"1", label %then.0.i, label %_condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_condFail_b.exit:                                 ; preds = %entry
  %"0_ptr" = getelementptr inbounds { i64, i1 }* %1, i32 0, i32 0
  %"0" = load i64* %"0_ptr"
  %2 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %2)
  %value_ptr.i = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %"0", i64* %value_ptr.i
  %3 = load { i64 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %2)
  ret { i64 } %3
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind
define { i64 } @_-_S.i64_S.i64({ i64 } %a, { i64 } %b) #3 {
entry:
  %0 = alloca { i64 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %sub_res = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value, i64 %value1)
  %1 = alloca { i64, i1 }
  store { i64, i1 } %sub_res, { i64, i1 }* %1
  %"1_ptr" = getelementptr inbounds { i64, i1 }* %1, i32 0, i32 1
  %"1" = load i1* %"1_ptr"
  br i1 %"1", label %then.0.i, label %_condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_condFail_b.exit:                                 ; preds = %entry
  %"0_ptr" = getelementptr inbounds { i64, i1 }* %1, i32 0, i32 0
  %"0" = load i64* %"0_ptr"
  %2 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %2)
  %value_ptr.i = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %"0", i64* %value_ptr.i
  %3 = load { i64 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %2)
  ret { i64 } %3
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind
define { i64 } @"_*_S.i64_S.i64"({ i64 } %a, { i64 } %b) #3 {
entry:
  %0 = alloca { i64 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %value, i64 %value1)
  %1 = alloca { i64, i1 }
  store { i64, i1 } %mul_res, { i64, i1 }* %1
  %"1_ptr" = getelementptr inbounds { i64, i1 }* %1, i32 0, i32 1
  %"1" = load i1* %"1_ptr"
  br i1 %"1", label %then.0.i, label %_condFail_b.exit

then.0.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_condFail_b.exit:                                 ; preds = %entry
  %"0_ptr" = getelementptr inbounds { i64, i1 }* %1, i32 0, i32 0
  %"0" = load i64* %"0_ptr"
  %2 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %2)
  %value_ptr.i = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %"0", i64* %value_ptr.i
  %3 = load { i64 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %2)
  ret { i64 } %3
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #6

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @"_/_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %0 = alloca { i64 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %div_res = udiv i64 %value, %value1
  %1 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %div_res, i64* %value_ptr.i
  %2 = load { i64 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i64 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @"_%_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %0 = alloca { i64 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %rem_res = urem i64 %value, %value1
  %1 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %rem_res, i64* %value_ptr.i
  %2 = load { i64 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i64 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_<_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_lt_res = icmp slt i64 %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_lt_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_<=_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_lte_res = icmp sle i64 %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_lte_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_>_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_gt_res = icmp sgt i64 %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_gt_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_>=_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_gte_res = icmp sge i64 %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_gte_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_==_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_eq_res = icmp eq i64 %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_eq_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_!=_S.i64_S.i64"({ i64 } %a, { i64 } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { i64 } %a, 0
  %value1 = extractvalue { i64 } %b, 0
  %cmp_neq_res = icmp ne i64 %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_neq_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_&&_S.b_S.b"({ i1 } %a, { i1 } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { i1 } %a, 0
  %value1 = extractvalue { i1 } %b, 0
  %cmp_and_res = and i1 %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_and_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_||_S.b_S.b"({ i1 } %a, { i1 } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { i1 } %a, 0
  %value1 = extractvalue { i1 } %b, 0
  %cmp_or_res = or i1 %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_or_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @"_+_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { double }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %add_res = fadd double %value, %value1
  %1 = bitcast { double }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { double }* %0, i32 0, i32 0
  store double %add_res, double* %value_ptr.i
  %2 = load { double }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { double } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @_-_S.f64_S.f64({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { double }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %sub_res = fsub double %value, %value1
  %1 = bitcast { double }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { double }* %0, i32 0, i32 0
  store double %sub_res, double* %value_ptr.i
  %2 = load { double }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { double } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @"_*_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { double }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %mul_res = fmul double %value, %value1
  %1 = bitcast { double }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { double }* %0, i32 0, i32 0
  store double %mul_res, double* %value_ptr.i
  %2 = load { double }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { double } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @"_/_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { double }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %div_res = fdiv double %value, %value1
  %1 = bitcast { double }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { double }* %0, i32 0, i32 0
  store double %div_res, double* %value_ptr.i
  %2 = load { double }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { double } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @"_%_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { double }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %rem_res = frem double %value, %value1
  %1 = bitcast { double }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { double }* %0, i32 0, i32 0
  store double %rem_res, double* %value_ptr.i
  %2 = load { double }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { double } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_<_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_lt_res = fcmp olt double %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_lt_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_<=_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_lte_res = fcmp ole double %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_lte_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_>_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_gt_res = fcmp ogt double %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_gt_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_>=_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_gte_res = fcmp oge double %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_gte_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_==_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_eq_res = fcmp oeq double %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_eq_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @"_!=_S.f64_S.f64"({ double } %a, { double } %b) #2 {
entry:
  %0 = alloca { i1 }
  %value = extractvalue { double } %a, 0
  %value1 = extractvalue { double } %b, 0
  %cmp_neq_res = fcmp one double %value, %value1
  %1 = bitcast { i1 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %value_ptr.i = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %cmp_neq_res, i1* %value_ptr.i
  %2 = load { i1 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { i1 } %2
}

; Function Attrs: alwaysinline nounwind readnone
define { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") #2 {
entry:
  %0 = alloca { { i64 }, { i64 } }
  %1 = bitcast { { i64 }, { i64 } }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %start_ptr.i = getelementptr inbounds { { i64 }, { i64 } }* %0, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %start_ptr.i
  %end_ptr.i = getelementptr inbounds { { i64 }, { i64 } }* %0, i32 0, i32 1
  store { i64 } %"$1", { i64 }* %end_ptr.i
  %2 = load { { i64 }, { i64 } }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  ret { { i64 }, { i64 } } %2
}

; Function Attrs: alwaysinline nounwind
define { { i64 }, { i64 } } @"_..<_S.i64_S.i64"({ i64 } %"$0", { i64 } %"$1") #3 {
entry:
  %0 = alloca { i64 }
  %1 = alloca { i64, i1 }
  %2 = alloca { { i64 }, { i64 } }
  %3 = bitcast { i64, i1 }* %1 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %3)
  %value.i = extractvalue { i64 } %"$1", 0
  %sub_res.i = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value.i, i64 1) #7
  store { i64, i1 } %sub_res.i, { i64, i1 }* %1
  %"1_ptr.i" = getelementptr inbounds { i64, i1 }* %1, i32 0, i32 1
  %"1.i" = load i1* %"1_ptr.i"
  br i1 %"1.i", label %then.0.i.i, label %_-_S.i64_S.i64.exit

then.0.i.i:                                       ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

_-_S.i64_S.i64.exit:                              ; preds = %entry
  %"0_ptr.i" = getelementptr inbounds { i64, i1 }* %1, i32 0, i32 0
  %"0.i" = load i64* %"0_ptr.i"
  %4 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %4) #7
  %value_ptr.i.i = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %"0.i", i64* %value_ptr.i.i
  %5 = load { i64 }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %4) #7
  call void @llvm.lifetime.end(i64 -1, i8* %3)
  %6 = bitcast { { i64 }, { i64 } }* %2 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %6)
  %start_ptr.i = getelementptr inbounds { { i64 }, { i64 } }* %2, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %start_ptr.i
  %end_ptr.i = getelementptr inbounds { { i64 }, { i64 } }* %2, i32 0, i32 1
  store { i64 } %5, { i64 }* %end_ptr.i
  %7 = load { { i64 }, { i64 } }* %2
  call void @llvm.lifetime.end(i64 -1, i8* %6)
  ret { { i64 }, { i64 } } %7
}

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #7

; Function Attrs: nounwind
declare void @llvm.lifetime.start(i64, i8* nocapture) #7

; Function Attrs: nounwind
declare void @llvm.lifetime.end(i64, i8* nocapture) #7

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
