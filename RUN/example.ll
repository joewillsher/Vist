; ModuleID = 'example_.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

; Function Attrs: noinline ssp uwtable
define void @_print_i64(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline ssp uwtable
define void @_print_i32(i32 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), i32 %i)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @_print_FP64(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @_print_FP32(float %d) #0 {
  %1 = fpext float %d to double
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %1)
  ret void
}

define i64 @main() {
entry:
  %0 = alloca { i64 }, align 8
  %ptra.i = alloca { i64 }, align 8
  %ptrb.i = alloca { i64 }, align 8
  %ptro.i = alloca { i64 }, align 8
  %1 = alloca { i64 }, align 8
  %2 = alloca { i64 }, align 8
  %3 = bitcast { i64 }* %2 to i8*
  call void @llvm.lifetime.start(i64 8, i8* %3)
  %value_ptr.i = getelementptr inbounds { i64 }* %2, i64 0, i32 0
  store i64 3, i64* %value_ptr.i, align 8
  %4 = load { i64 }* %2, align 8
  %5 = bitcast { i64 }* %2 to i8*
  call void @llvm.lifetime.end(i64 8, i8* %5)
  %6 = bitcast { i64 }* %ptro.i to i8*
  call void @llvm.lifetime.start(i64 8, i8* %6)
  %7 = bitcast { i64 }* %1 to i8*
  call void @llvm.lifetime.start(i64 8, i8* %7)
  store { i64 } %4, { i64 }* %ptro.i, align 8
  %value_ptr.i1 = getelementptr inbounds { i64 }* %ptro.i, i64 0, i32 0
  %value.i = load i64* %value_ptr.i1, align 8
  %value_ptr1.i = getelementptr inbounds { i64 }* %1, i64 0, i32 0
  store i64 %value.i, i64* %value_ptr1.i, align 8
  %8 = load { i64 }* %1, align 8
  %9 = bitcast { i64 }* %ptro.i to i8*
  call void @llvm.lifetime.end(i64 8, i8* %9)
  %10 = bitcast { i64 }* %1 to i8*
  call void @llvm.lifetime.end(i64 8, i8* %10)
  %11 = bitcast { i64 }* %ptra.i to i8*
  call void @llvm.lifetime.start(i64 8, i8* %11)
  %12 = bitcast { i64 }* %ptrb.i to i8*
  call void @llvm.lifetime.start(i64 8, i8* %12)
  store { i64 } %4, { i64 }* %ptra.i, align 8
  store { i64 } %8, { i64 }* %ptrb.i, align 8
  %value_ptr.i2 = getelementptr inbounds { i64 }* %ptra.i, i64 0, i32 0
  %value.i3 = load i64* %value_ptr.i2, align 8
  %value_ptr1.i4 = getelementptr inbounds { i64 }* %ptrb.i, i64 0, i32 0
  %value2.i = load i64* %value_ptr1.i4, align 8
  %add_res.i = add i64 %value.i3, %value2.i
  %13 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 8, i8* %13)
  %value_ptr.i.i = getelementptr inbounds { i64 }* %0, i64 0, i32 0
  store i64 %add_res.i, i64* %value_ptr.i.i, align 8
  %14 = load { i64 }* %0, align 8
  %15 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.end(i64 8, i8* %15)
  %16 = bitcast { i64 }* %ptra.i to i8*
  call void @llvm.lifetime.end(i64 8, i8* %16)
  %17 = bitcast { i64 }* %ptrb.i to i8*
  call void @llvm.lifetime.end(i64 8, i8* %17)
  %18 = alloca { i64 }, align 8
  store { i64 } %14, { i64 }* %18, align 8
  %value_ptr = getelementptr inbounds { i64 }* %18, i64 0, i32 0
  %value = load i64* %value_ptr, align 8
  tail call void @_print_i64(i64 %value)
  ret i64 0
}

; Function Attrs: alwaysinline
define { i64 } @_Int_S.i64_RS.i64({ i64 } %o) #2 {
entry:
  %ptro = alloca { i64 }, align 8
  store { i64 } %o, { i64 }* %ptro, align 8
  %0 = alloca { i64 }, align 8
  %value_ptr = getelementptr inbounds { i64 }* %ptro, i64 0, i32 0
  %value = load i64* %value_ptr, align 8
  %value_ptr1 = getelementptr inbounds { i64 }* %0, i64 0, i32 0
  store i64 %value, i64* %value_ptr1, align 8
  %1 = load { i64 }* %0, align 8
  ret { i64 } %1
}

; Function Attrs: alwaysinline
define { i64 } @_Int_i64_RS.i64(i64 %v) #2 {
entry:
  %0 = alloca { i64 }, align 8
  %value_ptr = getelementptr inbounds { i64 }* %0, i64 0, i32 0
  store i64 %v, i64* %value_ptr, align 8
  %1 = load { i64 }* %0, align 8
  ret { i64 } %1
}

define { i64 } @_foo_S.i64S.i64_RS.i64({ i64 } %a, { i64 } %b) {
entry:
  %0 = alloca { i64 }, align 8
  %ptra = alloca { i64 }, align 8
  store { i64 } %a, { i64 }* %ptra, align 8
  %ptrb = alloca { i64 }, align 8
  store { i64 } %b, { i64 }* %ptrb, align 8
  %value_ptr = getelementptr inbounds { i64 }* %ptra, i64 0, i32 0
  %value = load i64* %value_ptr, align 8
  %value_ptr1 = getelementptr inbounds { i64 }* %ptrb, i64 0, i32 0
  %value2 = load i64* %value_ptr1, align 8
  %add_res = add i64 %value, %value2
  %1 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 8, i8* %1)
  %value_ptr.i = getelementptr inbounds { i64 }* %0, i64 0, i32 0
  store i64 %add_res, i64* %value_ptr.i, align 8
  %2 = load { i64 }* %0, align 8
  %3 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.end(i64 8, i8* %3)
  ret { i64 } %2
}

; Function Attrs: nounwind
declare void @llvm.lifetime.start(i64, i8* nocapture) #3

; Function Attrs: nounwind
declare void @llvm.lifetime.end(i64, i8* nocapture) #3

attributes #0 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline }
attributes #3 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
