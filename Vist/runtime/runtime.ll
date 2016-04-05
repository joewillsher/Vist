; ModuleID = 'runtime.cpp'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%struct.RefcountedObject = type { i8*, i32 }

@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str3 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str4 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1
@.str5 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @_Z17incrementRefCountP16RefcountedObject(%struct.RefcountedObject* %object) #0 {
entry:
  %object.addr = alloca %struct.RefcountedObject*, align 8
  %.atomictmp = alloca i32, align 4
  %.atomicdst = alloca i32, align 4
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  %refCount = getelementptr inbounds %struct.RefcountedObject* %0, i32 0, i32 1
  store i32 1, i32* %.atomictmp
  %1 = load i32* %.atomictmp, align 4
  %2 = atomicrmw add i32* %refCount, i32 %1 monotonic
  store i32 %2, i32* %.atomicdst, align 4
  %3 = load i32* %.atomicdst, align 4
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @_Z17decrementRefCountP16RefcountedObject(%struct.RefcountedObject* %object) #0 {
entry:
  %object.addr = alloca %struct.RefcountedObject*, align 8
  %.atomictmp = alloca i32, align 4
  %.atomicdst = alloca i32, align 4
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  %refCount = getelementptr inbounds %struct.RefcountedObject* %0, i32 0, i32 1
  store i32 1, i32* %.atomictmp
  %1 = load i32* %.atomictmp, align 4
  %2 = atomicrmw sub i32* %refCount, i32 %1 monotonic
  store i32 %2, i32* %.atomicdst, align 4
  %3 = load i32* %.atomicdst, align 4
  ret void
}

; Function Attrs: alwaysinline ssp uwtable
define %struct.RefcountedObject* @vist_allocObject(i32 %size) #1 {
entry:
  %size.addr = alloca i32, align 4
  %object = alloca i8*, align 8
  %refCountedObject = alloca %struct.RefcountedObject*, align 8
  store i32 %size, i32* %size.addr, align 4
  %0 = load i32* %size.addr, align 4
  %conv = zext i32 %0 to i64
  %call = call i8* @malloc(i64 %conv)
  store i8* %call, i8** %object, align 8
  %call1 = call i8* @malloc(i64 16)
  %1 = bitcast i8* %call1 to %struct.RefcountedObject*
  store %struct.RefcountedObject* %1, %struct.RefcountedObject** %refCountedObject, align 8
  %2 = load i8** %object, align 8
  %3 = load %struct.RefcountedObject** %refCountedObject, align 8
  %object2 = getelementptr inbounds %struct.RefcountedObject* %3, i32 0, i32 0
  store i8* %2, i8** %object2, align 8
  %4 = load %struct.RefcountedObject** %refCountedObject, align 8
  %refCount = getelementptr inbounds %struct.RefcountedObject* %4, i32 0, i32 1
  store i32 0, i32* %refCount, align 4
  %5 = load %struct.RefcountedObject** %refCountedObject, align 8
  ret %struct.RefcountedObject* %5
}

declare i8* @malloc(i64) #2

; Function Attrs: alwaysinline ssp uwtable
define void @vist_deallocObject(%struct.RefcountedObject* %object) #1 {
entry:
  %object.addr = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  %object1 = getelementptr inbounds %struct.RefcountedObject* %0, i32 0, i32 0
  %1 = load i8** %object1, align 8
  call void @free(i8* %1)
  ret void
}

declare void @free(i8*) #2

; Function Attrs: alwaysinline ssp uwtable
define void @vist_releaseObject(%struct.RefcountedObject* %object) #1 {
entry:
  %object.addr.i1 = alloca %struct.RefcountedObject*, align 8
  %.atomictmp.i = alloca i32, align 4
  %.atomicdst.i = alloca i32, align 4
  %object.addr.i = alloca %struct.RefcountedObject*, align 8
  %object.addr = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  %refCount = getelementptr inbounds %struct.RefcountedObject* %0, i32 0, i32 1
  %1 = load i32* %refCount, align 4
  %cmp = icmp eq i32 %1, 1
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %2 = load %struct.RefcountedObject** %object.addr, align 8
  store %struct.RefcountedObject* %2, %struct.RefcountedObject** %object.addr.i, align 8
  %3 = load %struct.RefcountedObject** %object.addr.i, align 8
  %object1.i = getelementptr inbounds %struct.RefcountedObject* %3, i32 0, i32 0
  %4 = load i8** %object1.i, align 8
  call void @free(i8* %4)
  br label %if.end

if.else:                                          ; preds = %entry
  %5 = load %struct.RefcountedObject** %object.addr, align 8
  store %struct.RefcountedObject* %5, %struct.RefcountedObject** %object.addr.i1, align 8
  %6 = load %struct.RefcountedObject** %object.addr.i1, align 8
  %refCount.i = getelementptr inbounds %struct.RefcountedObject* %6, i32 0, i32 1
  store i32 1, i32* %.atomictmp.i
  %7 = load i32* %.atomictmp.i, align 4
  %8 = atomicrmw sub i32* %refCount.i, i32 %7 monotonic
  store i32 %8, i32* %.atomicdst.i, align 4
  %9 = load i32* %.atomicdst.i, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_retainObject(%struct.RefcountedObject* %object) #0 {
entry:
  %object.addr.i = alloca %struct.RefcountedObject*, align 8
  %.atomictmp.i = alloca i32, align 4
  %.atomicdst.i = alloca i32, align 4
  %object.addr = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  store %struct.RefcountedObject* %0, %struct.RefcountedObject** %object.addr.i, align 8
  %1 = load %struct.RefcountedObject** %object.addr.i, align 8
  %refCount.i = getelementptr inbounds %struct.RefcountedObject* %1, i32 0, i32 1
  store i32 1, i32* %.atomictmp.i
  %2 = load i32* %.atomictmp.i, align 4
  %3 = atomicrmw add i32* %refCount.i, i32 %2 monotonic
  store i32 %3, i32* %.atomicdst.i, align 4
  %4 = load i32* %.atomicdst.i, align 4
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_releaseUnownedObject(%struct.RefcountedObject* %object) #0 {
entry:
  %object.addr.i = alloca %struct.RefcountedObject*, align 8
  %.atomictmp.i = alloca i32, align 4
  %.atomicdst.i = alloca i32, align 4
  %object.addr = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  store %struct.RefcountedObject* %0, %struct.RefcountedObject** %object.addr.i, align 8
  %1 = load %struct.RefcountedObject** %object.addr.i, align 8
  %refCount.i = getelementptr inbounds %struct.RefcountedObject* %1, i32 0, i32 1
  store i32 1, i32* %.atomictmp.i
  %2 = load i32* %.atomictmp.i, align 4
  %3 = atomicrmw sub i32* %refCount.i, i32 %2 monotonic
  store i32 %3, i32* %.atomicdst.i, align 4
  %4 = load i32* %.atomicdst.i, align 4
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define i32 @vist_getObjectRefcount(%struct.RefcountedObject* %object) #0 {
entry:
  %object.addr = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  %refCount = getelementptr inbounds %struct.RefcountedObject* %0, i32 0, i32 1
  %1 = load i32* %refCount, align 4
  ret i32 %1
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define zeroext i1 @vist_objectHasUniqueReference(%struct.RefcountedObject* %object) #0 {
entry:
  %object.addr = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  %refCount = getelementptr inbounds %struct.RefcountedObject* %0, i32 0, i32 1
  %1 = load i32* %refCount, align 4
  %cmp = icmp eq i32 %1, 1
  ret i1 %cmp
}

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_ti64"(i64 %i) #3 {
entry:
  %i.addr = alloca i64, align 8
  store i64 %i, i64* %i.addr, align 8
  %0 = load i64* %i.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i64 %0)
  ret void
}

declare i32 @printf(i8*, ...) #2

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_ti32"(i32 %i) #3 {
entry:
  %i.addr = alloca i32, align 4
  store i32 %i, i32* %i.addr, align 4
  %0 = load i32* %i.addr, align 4
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %0)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_tf64"(double %d) #3 {
entry:
  %d.addr = alloca double, align 8
  store double %d, double* %d.addr, align 8
  %0 = load double* %d.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %0)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_tf32"(float %d) #3 {
entry:
  %d.addr = alloca float, align 4
  store float %d, float* %d.addr, align 4
  %0 = load float* %d.addr, align 4
  %conv = fpext float %0 to double
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %conv)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_tb"(i1 zeroext %b) #3 {
entry:
  %b.addr = alloca i8, align 1
  %frombool = zext i1 %b to i8
  store i8 %frombool, i8* %b.addr, align 1
  %0 = load i8* %b.addr, align 1
  %tobool = trunc i8 %0 to i1
  %cond = select i1 %tobool, i8* getelementptr inbounds ([6 x i8]* @.str3, i32 0, i32 0), i8* getelementptr inbounds ([7 x i8]* @.str4, i32 0, i32 0)
  %call = call i32 (i8*, ...)* @printf(i8* %cond)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"vist$Uprint_top"(i8* %str) #3 {
entry:
  %str.addr = alloca i8*, align 8
  store i8* %str, i8** %str.addr, align 8
  %0 = load i8** %str.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str5, i32 0, i32 0), i8* %0)
  ret void
}

attributes #0 = { alwaysinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { alwaysinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
