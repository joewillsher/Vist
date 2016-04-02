; ModuleID = 'runtime.cpp'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%struct.RefcountedObject = type { i8*, i32 }

@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str.3 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str.4 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1
@.str.5 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

; Function Attrs: noinline ssp uwtable
define i8* @vist_allocObject(i32 %size) #0 {
  %1 = alloca i32, align 4
  store i32 %size, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = sext i32 %2 to i64
  %4 = call i8* @malloc(i64 %3)
  ret i8* %4
}

declare i8* @malloc(i64) #1

; Function Attrs: noinline ssp uwtable
define void @vist_deallocObject(%struct.RefcountedObject* %object) #0 {
  %1 = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %1, align 8
  %2 = load %struct.RefcountedObject*, %struct.RefcountedObject** %1, align 8
  %3 = bitcast %struct.RefcountedObject* %2 to i8*
  call void @free(i8* %3)
  ret void
}

declare void @free(i8*) #1

; Function Attrs: noinline ssp uwtable
define void @vist_retain(%struct.RefcountedObject* %object) #0 {
  %1 = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %1, align 8
  %2 = load %struct.RefcountedObject*, %struct.RefcountedObject** %1, align 8
  %3 = bitcast %struct.RefcountedObject* %2 to i8*
  call void @free(i8* %3)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @vist_release(%struct.RefcountedObject* %object) #0 {
  %1 = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %1, align 8
  %2 = load %struct.RefcountedObject*, %struct.RefcountedObject** %1, align 8
  %3 = bitcast %struct.RefcountedObject* %2 to i8*
  call void @free(i8* %3)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_ti64"(i64 %i) #0 {
  %1 = alloca i64, align 8
  store i64 %i, i64* %1, align 8
  %2 = load i64, i64* %1, align 8
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str, i32 0, i32 0), i64 %2)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_ti32"(i32 %i) #0 {
  %1 = alloca i32, align 4
  store i32 %i, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i32 %2)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_tf64"(double %d) #0 {
  %1 = alloca double, align 8
  store double %d, double* %1, align 8
  %2 = load double, double* %1, align 8
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.2, i32 0, i32 0), double %2)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_tf32"(float %d) #0 {
  %1 = alloca float, align 4
  store float %d, float* %1, align 4
  %2 = load float, float* %1, align 4
  %3 = fpext float %2 to double
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.2, i32 0, i32 0), double %3)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_tb"(i1 zeroext %b) #0 {
  %1 = alloca i8, align 1
  %2 = zext i1 %b to i8
  store i8 %2, i8* %1, align 1
  %3 = load i8, i8* %1, align 1
  %4 = trunc i8 %3 to i1
  %5 = select i1 %4, i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.4, i32 0, i32 0)
  %6 = call i32 (i8*, ...) @printf(i8* %5)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_top"(i8* %str) #0 {
  %1 = alloca i8*, align 8
  store i8* %str, i8** %1, align 8
  %2 = load i8*, i8** %1, align 8
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.5, i32 0, i32 0), i8* %2)
  ret void
}

attributes #0 = { noinline ssp uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"Apple LLVM version 7.3.0 (clang-703.0.29)"}
