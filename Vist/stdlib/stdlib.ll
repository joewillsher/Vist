; ModuleID = 'stdlib.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Range.st = type { %Int.st, %Int.st }
%Int.st = type { i64 }
%Bool.st = type { i1 }
%Double.st = type { double }
%Int32.st = type { i32 }

@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str3 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str4 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_i64(i64 %i) #0 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i)
  ret void
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_i32(i32 %i) #0 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), i32 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_f64(double %d) #0 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_f32(float %d) #0 {
entry:
  %conv = fpext float %d to double
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %conv)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_b(i1 zeroext %b) #0 {
entry:
  %cond = select i1 %b, i8* getelementptr inbounds ([6 x i8]* @.str3, i64 0, i64 0), i8* getelementptr inbounds ([7 x i8]* @.str4, i64 0, i64 0)
  %call = tail call i32 (i8*, ...)* @printf(i8* %cond)
  ret void
}

; Function Attrs: nounwind
define %Range.st @..-L_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %0 = extractvalue %Int.st %b, 0
  %1 = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 1) #2
  %2 = extractvalue { i64, i1 } %1, 1
  br i1 %2, label %-.trap.i, label %-M_Int_Int.exit

-.trap.i:                                         ; preds = %entry
  tail call void @llvm.trap() #2
  unreachable

-M_Int_Int.exit:                                  ; preds = %entry
  %3 = extractvalue { i64, i1 } %1, 0
  %a.fca.0.extract = extractvalue %Int.st %a, 0
  %.fca.0.0.insert = insertvalue %Range.st undef, i64 %a.fca.0.extract, 0, 0
  %.fca.1.0.insert = insertvalue %Range.st %.fca.0.0.insert, i64 %3, 1, 0
  ret %Range.st %.fca.1.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @-L-E_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp sle i64 %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind
define %Int.st @-P_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %0, i64 %1)
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"+.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %.fca.0.insert = insertvalue %Int.st undef, i64 %4, 0
  ret %Int.st %.fca.0.insert

"+.trap":                                         ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: nounwind readnone
define %Int.st @-T-N_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = and i64 %1, %0
  %.fca.0.insert = insertvalue %Int.st undef, i64 %2, 0
  ret %Int.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @-G-E_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp sge i64 %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind
define %Int.st @-A_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %0, i64 %1)
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"*.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %.fca.0.insert = insertvalue %Int.st undef, i64 %4, 0
  ret %Int.st %.fca.0.insert

"*.trap":                                         ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: nounwind readnone
define %Bool.st @-L_Double_Double(%Double.st %a, %Double.st %b) #3 {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp olt double %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @-G_Double_Double(%Double.st %a, %Double.st %b) #3 {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp ogt double %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @"!-E_Double_Double"(%Double.st %a, %Double.st %b) #3 {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp one double %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Int.st @-L-L_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = shl i64 %0, %1
  %.fca.0.insert = insertvalue %Int.st undef, i64 %2, 0
  ret %Int.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @-G_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp sgt i64 %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @-L_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp slt i64 %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Double.st @-D_Double_Double(%Double.st %a, %Double.st %b) #3 {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fdiv double %0, %1
  %.fca.0.insert = insertvalue %Double.st undef, double %2, 0
  ret %Double.st %.fca.0.insert
}

; Function Attrs: nounwind
define %Int.st @-M_Int_Int(%Int.st %a, %Int.st %b) #2 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 %1)
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %-.trap, label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %.fca.0.insert = insertvalue %Int.st undef, i64 %4, 0
  ret %Int.st %.fca.0.insert

-.trap:                                           ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: nounwind readnone
define %Int.st @"%_Int_Int"(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = srem i64 %0, %1
  %.fca.0.insert = insertvalue %Int.st undef, i64 %2, 0
  ret %Int.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @-E-E_Double_Double(%Double.st %a, %Double.st %b) #3 {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp oeq double %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind
define void @print_Double(%Double.st %a) #2 {
entry:
  %0 = extractvalue %Double.st %a, 0
  tail call void @vist-Uprint_f64(double %0)
  ret void
}

; Function Attrs: nounwind readnone
define %Double.st @-M_Double_Double(%Double.st %a, %Double.st %b) #3 {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fadd double %0, %1
  %.fca.0.insert = insertvalue %Double.st undef, double %2, 0
  ret %Double.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define void @assert_Bool(%Bool.st %"$0") #3 {
entry:
  ret void
}

; Function Attrs: nounwind readnone
define %Bool.st @-Uexpect_Bool_Bool(%Bool.st %val, %Bool.st %assume) #3 {
entry:
  ret %Bool.st %val
}

; Function Attrs: nounwind readnone
define %Bool.st @Bool_() #3 {
entry:
  ret %Bool.st zeroinitializer
}

; Function Attrs: nounwind
define void @print_Bool(%Bool.st %a) #2 {
entry:
  %0 = extractvalue %Bool.st %a, 0
  tail call void @vist-Uprint_b(i1 %0)
  ret void
}

; Function Attrs: nounwind readnone
define %Int.st @-T-R_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = xor i64 %1, %0
  %.fca.0.insert = insertvalue %Int.st undef, i64 %2, 0
  ret %Int.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Int.st @-T-O_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = or i64 %1, %0
  %.fca.0.insert = insertvalue %Int.st undef, i64 %2, 0
  ret %Int.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @Bool_b(i1 %"$0") #3 {
entry:
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %"$0", 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @-G-E_Double_Double(%Double.st %a, %Double.st %b) #3 {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp oge double %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Double.st @-A_Double_Double(%Double.st %a, %Double.st %b) #3 {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fmul double %0, %1
  %.fca.0.insert = insertvalue %Double.st undef, double %2, 0
  ret %Double.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Int.st @Int_i64(i64 %"$0") #3 {
entry:
  %.fca.0.insert = insertvalue %Int.st undef, i64 %"$0", 0
  ret %Int.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @"!-E_Int_Int"(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp ne i64 %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Int32.st @Int32_i32(i32 %"$0") #3 {
entry:
  %.fca.0.insert = insertvalue %Int32.st undef, i32 %"$0", 0
  ret %Int32.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Int.st @Int_() #3 {
entry:
  ret %Int.st zeroinitializer
}

; Function Attrs: nounwind readnone
define void @fatalError_() #3 {
entry:
  ret void
}

; Function Attrs: nounwind
define void @print_Int(%Int.st %a) #2 {
entry:
  %0 = extractvalue %Int.st %a, 0
  tail call void @vist-Uprint_i64(i64 %0)
  ret void
}

; Function Attrs: nounwind readnone
define %Bool.st @-N-N_Bool_Bool(%Bool.st %a, %Bool.st %b) #3 {
entry:
  %0 = extractvalue %Bool.st %a, 0
  %1 = extractvalue %Bool.st %b, 0
  %2 = and i1 %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Int.st @-G-G_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = ashr i64 %0, %1
  %.fca.0.insert = insertvalue %Int.st undef, i64 %2, 0
  ret %Int.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @-L-E_Double_Double(%Double.st %a, %Double.st %b) #3 {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp ole double %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind
define void @print_Int32(%Int32.st %a) #2 {
entry:
  %0 = extractvalue %Int32.st %a, 0
  tail call void @vist-Uprint_i32(i32 %0)
  ret void
}

; Function Attrs: nounwind readnone
define %Range.st @Range_Int_Int(%Int.st %"$0", %Int.st %"$1") #3 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int.st %"$1", 0
  %.fca.0.0.insert = insertvalue %Range.st undef, i64 %"$0.fca.0.extract", 0, 0
  %.fca.1.0.insert = insertvalue %Range.st %.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret %Range.st %.fca.1.0.insert
}

; Function Attrs: nounwind readnone
define %Range.st @..._Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %a.fca.0.extract = extractvalue %Int.st %a, 0
  %b.fca.0.extract = extractvalue %Int.st %b, 0
  %.fca.0.0.insert = insertvalue %Range.st undef, i64 %a.fca.0.extract, 0, 0
  %.fca.1.0.insert = insertvalue %Range.st %.fca.0.0.insert, i64 %b.fca.0.extract, 1, 0
  ret %Range.st %.fca.1.0.insert
}

; Function Attrs: nounwind readnone
define %Int.st @-D_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %b, 0
  %1 = extractvalue %Int.st %a, 0
  %2 = sdiv i64 %1, %0
  %.fca.0.insert = insertvalue %Int.st undef, i64 %2, 0
  ret %Int.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Double.st @Double_f64(double %"$0") #3 {
entry:
  %.fca.0.insert = insertvalue %Double.st undef, double %"$0", 0
  ret %Double.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Double.st @"%_Double_Double"(%Double.st %a, %Double.st %b) #3 {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = frem double %0, %1
  %.fca.0.insert = insertvalue %Double.st undef, double %2, 0
  ret %Double.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @-E-E_Int_Int(%Int.st %a, %Int.st %b) #3 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp eq i64 %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #3

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #4

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #3

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #3

; Function Attrs: nounwind readnone
define %Bool.st @-O-O_Bool_Bool(%Bool.st, %Bool.st) #3 {
  %3 = extractvalue %Bool.st %0, 0
  %4 = extractvalue %Bool.st %1, 0
  %5 = and i1 %3, %4
  %.fca.0.insert.i = insertvalue %Bool.st undef, i1 %5, 0
  ret %Bool.st %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Double.st @-P_Double_Double(%Double.st, %Double.st) #3 {
  %3 = extractvalue %Double.st %0, 0
  %4 = extractvalue %Double.st %1, 0
  %5 = fadd double %3, %4
  %.fca.0.insert.i = insertvalue %Double.st undef, double %5, 0
  ret %Double.st %.fca.0.insert.i
}

attributes #0 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }
attributes #3 = { nounwind readnone }
attributes #4 = { noreturn nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
!1 = !{i32 1, !"PIC Level", i32 2}
