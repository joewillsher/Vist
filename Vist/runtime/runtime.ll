; ModuleID = 'runtime.cpp'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%struct.__sFILE = type { i8*, i32, i32, i16, i16, %struct.__sbuf, i32, i8*, i32 (i8*)*, i32 (i8*, i8*, i32)*, i64 (i8*, i64, i32)*, i32 (i8*, i8*, i32)*, %struct.__sbuf, %struct.__sFILEX*, i32, [3 x i8], [1 x i8], %struct.__sbuf, i32, i64 }
%struct.__sFILEX = type opaque
%struct.__sbuf = type { i8*, i32 }
%struct.RefcountedObject = type { i8*, i32 }

@.str = private unnamed_addr constant [17 x i8] c">alloc %i bytes\0A\00", align 1
@.str2 = private unnamed_addr constant [13 x i8] c">release %i\0A\00", align 1
@.str3 = private unnamed_addr constant [12 x i8] c">retain %i\0A\00", align 1
@.str4 = private unnamed_addr constant [21 x i8] c">release-unowned %i\0A\00", align 1
@.str5 = private unnamed_addr constant [21 x i8] c">dealloc-unowned %i\0A\00", align 1
@_ZL11yieldTarget = internal global [37 x i32] zeroinitializer, align 16
@.str6 = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str7 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str8 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str9 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str10 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1
@__stdoutp = external global %struct.__sFILE*
@str = private unnamed_addr constant [9 x i8] c">dealloc\00"

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @_Z17incrementRefCountP16RefcountedObject(%struct.RefcountedObject* %object) #0 {
entry:
  %refCount = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = atomicrmw add i32* %refCount, i32 1 monotonic
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @_Z17decrementRefCountP16RefcountedObject(%struct.RefcountedObject* %object) #0 {
entry:
  %refCount = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = atomicrmw sub i32* %refCount, i32 1 monotonic
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define noalias %struct.RefcountedObject* @vist_allocObject(i32 %size) #0 {
entry:
  %conv = zext i32 %size to i64
  %call = tail call i8* @malloc(i64 %conv)
  %call1 = tail call i8* @malloc(i64 16)
  %0 = bitcast i8* %call1 to %struct.RefcountedObject*
  %object2 = bitcast i8* %call1 to i8**
  store i8* %call, i8** %object2, align 8, !tbaa !2
  %refCount = getelementptr inbounds i8* %call1, i64 8
  %1 = bitcast i8* %refCount to i32*
  store i32 0, i32* %1, align 4, !tbaa !8
  %call3 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([17 x i8]* @.str, i64 0, i64 0), i32 %size)
  ret %struct.RefcountedObject* %0
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_deallocObject(%struct.RefcountedObject* nocapture readonly %object) #0 {
entry:
  %puts = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @str, i64 0, i64 0))
  %object1 = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 0
  %0 = load i8** %object1, align 8, !tbaa !2
  tail call void @free(i8* %0)
  ret void
}

; Function Attrs: nounwind
declare void @free(i8* nocapture) #1

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_releaseObject(%struct.RefcountedObject* %object) #0 {
entry:
  %refCount = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4, !tbaa !8
  %sub = add i32 %0, -1
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([13 x i8]* @.str2, i64 0, i64 0), i32 %sub)
  %1 = load i32* %refCount, align 4, !tbaa !8
  %cmp = icmp eq i32 %1, 1
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %puts.i = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @str, i64 0, i64 0)) #10
  %object1.i = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 0
  %2 = load i8** %object1.i, align 8, !tbaa !2
  tail call void @free(i8* %2) #10
  br label %if.end

if.else:                                          ; preds = %entry
  %3 = atomicrmw sub i32* %refCount, i32 1 monotonic
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_retainObject(%struct.RefcountedObject* %object) #0 {
entry:
  %refCount.i = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = atomicrmw add i32* %refCount.i, i32 1 monotonic
  %1 = load i32* %refCount.i, align 4, !tbaa !8
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([12 x i8]* @.str3, i64 0, i64 0), i32 %1)
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_releaseUnownedObject(%struct.RefcountedObject* %object) #0 {
entry:
  %refCount.i = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = atomicrmw sub i32* %refCount.i, i32 1 monotonic
  %1 = load i32* %refCount.i, align 4, !tbaa !8
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @.str4, i64 0, i64 0), i32 %1)
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_deallocUnownedObject(%struct.RefcountedObject* nocapture readonly %object) #0 {
entry:
  %refCount = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4, !tbaa !8
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @.str5, i64 0, i64 0), i32 %0)
  %1 = load i32* %refCount, align 4, !tbaa !8
  %cmp = icmp eq i32 %1, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %puts.i = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @str, i64 0, i64 0)) #10
  %object1.i = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 0
  %2 = load i8** %object1.i, align 8, !tbaa !2
  tail call void @free(i8* %2) #10
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  ret void
}

; Function Attrs: alwaysinline nounwind readonly ssp uwtable
define i32 @vist_getObjectRefcount(%struct.RefcountedObject* nocapture readonly %object) #2 {
entry:
  %refCount = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4, !tbaa !8
  ret i32 %0
}

; Function Attrs: alwaysinline nounwind readonly ssp uwtable
define zeroext i1 @vist_objectHasUniqueReference(%struct.RefcountedObject* nocapture readonly %object) #2 {
entry:
  %refCount = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4, !tbaa !8
  %cmp = icmp eq i32 %0, 1
  ret i1 %cmp
}

; Function Attrs: alwaysinline noreturn ssp uwtable
define void @vist_yieldUnwind() #3 {
entry:
  tail call void @longjmp(i32* getelementptr inbounds ([37 x i32]* @_ZL11yieldTarget, i64 0, i64 0), i32 1) #11
  unreachable
}

; Function Attrs: noreturn
declare void @longjmp(i32*, i32) #4

; Function Attrs: alwaysinline ssp uwtable
define zeroext i1 @vist_setYieldTarget() #5 {
entry:
  %call = call i32 @setjmp(i32* getelementptr inbounds ([37 x i32]* @_ZL11yieldTarget, i64 0, i64 0)) #12
  %tobool = icmp ne i32 %call, 0
  ret i1 %tobool
}

; Function Attrs: returns_twice
declare i32 @setjmp(i32*) #6

; Function Attrs: noinline nounwind ssp uwtable
define void @"vist$Uprint_ti64"(i64 %i) #7 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str6, i64 0, i64 0), i64 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @"vist$Uprint_ti32"(i32 %i) #7 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str7, i64 0, i64 0), i32 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @"vist$Uprint_tf64"(double %d) #7 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str8, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @"vist$Uprint_tf32"(float %d) #7 {
entry:
  %conv = fpext float %d to double
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str8, i64 0, i64 0), double %conv)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @"vist$Uprint_tb"(i1 zeroext %b) #7 {
entry:
  %cond = select i1 %b, i8* getelementptr inbounds ([6 x i8]* @.str9, i64 0, i64 0), i8* getelementptr inbounds ([7 x i8]* @.str10, i64 0, i64 0)
  %call = tail call i32 (i8*, ...)* @printf(i8* %cond)
  ret void
}

; Function Attrs: alwaysinline ssp uwtable
define void @"vist$Ucshim$Uwrite_topi64"(i8* %str, i64 %size) #5 {
entry:
  %0 = load %struct.__sFILE** @__stdoutp, align 8, !tbaa !9
  %call = tail call i64 @"\01_fwrite"(i8* %str, i64 %size, i64 1, %struct.__sFILE* %0)
  ret void
}

declare i64 @"\01_fwrite"(i8*, i64, i64, %struct.__sFILE*) #8

; Function Attrs: noinline ssp uwtable
define void @"vist$Ucshim$Uputchar_ti8"(i8 signext %c) #9 {
entry:
  %conv = sext i8 %c to i32
  %0 = load %struct.__sFILE** @__stdoutp, align 8, !tbaa !9
  %_w.i = getelementptr inbounds %struct.__sFILE* %0, i64 0, i32 2
  %1 = load i32* %_w.i, align 4, !tbaa !10
  %dec.i = add nsw i32 %1, -1
  store i32 %dec.i, i32* %_w.i, align 4, !tbaa !10
  %cmp.i = icmp sgt i32 %1, 0
  br i1 %cmp.i, label %if.then.i, label %lor.lhs.false.i

lor.lhs.false.i:                                  ; preds = %entry
  %_lbfsize.i = getelementptr inbounds %struct.__sFILE* %0, i64 0, i32 6
  %2 = load i32* %_lbfsize.i, align 4, !tbaa !15
  %cmp2.i = icmp sle i32 %1, %2
  %sext.mask.i = and i32 %conv, 255
  %cmp4.i = icmp eq i32 %sext.mask.i, 10
  %or.cond.i = or i1 %cmp4.i, %cmp2.i
  br i1 %or.cond.i, label %if.else.i, label %if.then.i

if.then.i:                                        ; preds = %entry, %lor.lhs.false.i
  %_p6.i = getelementptr inbounds %struct.__sFILE* %0, i64 0, i32 0
  %3 = load i8** %_p6.i, align 8, !tbaa !16
  %incdec.ptr.i = getelementptr inbounds i8* %3, i64 1
  store i8* %incdec.ptr.i, i8** %_p6.i, align 8, !tbaa !16
  store i8 %c, i8* %3, align 1, !tbaa !17
  br label %_Z7__sputciP7__sFILE.exit

if.else.i:                                        ; preds = %lor.lhs.false.i
  %call.i = tail call i32 @__swbuf(i32 %conv, %struct.__sFILE* %0)
  br label %_Z7__sputciP7__sFILE.exit

_Z7__sputciP7__sFILE.exit:                        ; preds = %if.then.i, %if.else.i
  ret void
}

declare i32 @__swbuf(i32, %struct.__sFILE*) #8

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #10

attributes #0 = { alwaysinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline nounwind readonly ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { alwaysinline noreturn ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { noreturn "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { alwaysinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { returns_twice "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #8 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #9 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #10 = { nounwind }
attributes #11 = { noreturn }
attributes #12 = { returns_twice }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
!2 = !{!3, !4, i64 0}
!3 = !{!"_ZTS16RefcountedObject", !4, i64 0, !7, i64 8}
!4 = !{!"any pointer", !5, i64 0}
!5 = !{!"omnipotent char", !6, i64 0}
!6 = !{!"Simple C/C++ TBAA"}
!7 = !{!"int", !5, i64 0}
!8 = !{!3, !7, i64 8}
!9 = !{!4, !4, i64 0}
!10 = !{!11, !7, i64 12}
!11 = !{!"_ZTS7__sFILE", !4, i64 0, !7, i64 8, !7, i64 12, !12, i64 16, !12, i64 18, !13, i64 24, !7, i64 40, !4, i64 48, !4, i64 56, !4, i64 64, !4, i64 72, !4, i64 80, !13, i64 88, !4, i64 104, !7, i64 112, !5, i64 116, !5, i64 119, !13, i64 120, !7, i64 136, !14, i64 144}
!12 = !{!"short", !5, i64 0}
!13 = !{!"_ZTS6__sbuf", !4, i64 0, !7, i64 8}
!14 = !{!"long long", !5, i64 0}
!15 = !{!11, !7, i64 40}
!16 = !{!11, !4, i64 0}
!17 = !{!5, !5, i64 0}
