; ModuleID = 'example_.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@str = private unnamed_addr constant [6 x i8] c"false\00"
@str1 = private unnamed_addr constant [5 x i8] c"true\00"

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

; Function Attrs: nounwind
define i64 @main() #2 {
entry:
  tail call void @_print_i64(i64 6) #2
  tail call void @_print_b(i1 true) #2
  tail call void @_print_FP64(double 3.000000e+00) #2
  ret i64 0
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_Int_S.i64({ i64 } %o) #3 {
entry:
  ret { i64 } %o
}

; Function Attrs: alwaysinline nounwind readnone
define { i64 } @_Int_i64(i64 %v) #3 {
entry:
  %.fca.0.insert = insertvalue { i64 } undef, i64 %v, 0
  ret { i64 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @_Bool_S.b({ i1 } %o) #3 {
entry:
  ret { i1 } %o
}

; Function Attrs: alwaysinline nounwind readnone
define { i1 } @_Bool_b(i1 %v) #3 {
entry:
  %.fca.0.insert = insertvalue { i1 } undef, i1 %v, 0
  ret { i1 } %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @_Double_S.FP64({ double } %o) #3 {
entry:
  ret { double } %o
}

; Function Attrs: alwaysinline nounwind readnone
define { double } @_Double_FP64(double %v) #3 {
entry:
  %.fca.0.insert = insertvalue { double } undef, double %v, 0
  ret { double } %.fca.0.insert
}

; Function Attrs: nounwind
define void @_print_S.i64({ i64 } %a) #2 {
entry:
  %a.fca.0.extract = extractvalue { i64 } %a, 0
  tail call void @_print_i64(i64 %a.fca.0.extract)
  ret void
}

; Function Attrs: nounwind
define void @_print_S.b({ i1 } %a) #2 {
entry:
  %a.fca.0.extract = extractvalue { i1 } %a, 0
  tail call void @_print_b(i1 %a.fca.0.extract)
  ret void
}

; Function Attrs: nounwind
define void @_print_S.FP64({ double } %a) #2 {
entry:
  %a.fca.0.extract = extractvalue { double } %a, 0
  tail call void @_print_FP64(double %a.fca.0.extract)
  ret void
}

; Function Attrs: nounwind readnone
define { i64 } @_foo_S.i64S.i64({ i64 } %a, { i64 } %b) #4 {
entry:
  %a.fca.0.extract = extractvalue { i64 } %a, 0
  %b.fca.0.extract = extractvalue { i64 } %b, 0
  %add_res = add i64 %b.fca.0.extract, %a.fca.0.extract
  %.fca.0.insert.i = insertvalue { i64 } undef, i64 %add_res, 0
  ret { i64 } %.fca.0.insert.i
}

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #2

attributes #0 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }
attributes #3 = { alwaysinline nounwind readnone }
attributes #4 = { nounwind readnone }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
