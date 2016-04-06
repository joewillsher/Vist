; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%struct.RefcountedObject = type { i8*, i32 }
%Int = type { i64 }
%String = type { i8*, %Int, %Int }
%Bool = type { i1 }

@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str3 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str4 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1
@0 = private unnamed_addr constant [5 x i8] c"meme\00"

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
  store i8* %call, i8** %object2, align 8
  %refCount = getelementptr inbounds i8* %call1, i64 8
  %1 = bitcast i8* %refCount to i32*
  store i32 0, i32* %1, align 4
  ret %struct.RefcountedObject* %0
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_deallocObject(%struct.RefcountedObject* nocapture readonly %object) #0 {
entry:
  %object1 = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 0
  %0 = load i8** %object1, align 8
  tail call void @free(i8* %0)
  ret void
}

; Function Attrs: nounwind
declare void @free(i8* nocapture) #1

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_releaseObject(%struct.RefcountedObject* %object) #0 {
entry:
  %refCount = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4
  %cmp = icmp eq i32 %0, 1
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %object1.i = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 0
  %1 = load i8** %object1.i, align 8
  tail call void @free(i8* %1)
  br label %if.end

if.else:                                          ; preds = %entry
  %2 = atomicrmw sub i32* %refCount, i32 1 monotonic
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_retainObject(%struct.RefcountedObject* %object) #0 {
entry:
  %refCount.i = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = atomicrmw add i32* %refCount.i, i32 1 monotonic
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_releaseUnownedObject(%struct.RefcountedObject* %object) #0 {
entry:
  %refCount.i = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = atomicrmw sub i32* %refCount.i, i32 1 monotonic
  ret void
}

; Function Attrs: alwaysinline nounwind readonly ssp uwtable
define i32 @vist_getObjectRefcount(%struct.RefcountedObject* nocapture readonly %object) #2 {
entry:
  %refCount = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4
  ret i32 %0
}

; Function Attrs: alwaysinline nounwind readonly ssp uwtable
define zeroext i1 @vist_objectHasUniqueReference(%struct.RefcountedObject* nocapture readonly %object) #2 {
entry:
  %refCount = getelementptr inbounds %struct.RefcountedObject* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4
  %cmp = icmp eq i32 %0, 1
  ret i1 %cmp
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_ti64(i64 %i) #3 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i)
  ret void
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_ti32(i32 %i) #3 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), i32 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tf64(double %d) #3 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tf32(float %d) #3 {
entry:
  %conv = fpext float %d to double
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %conv)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tb(i1 zeroext %b) #3 {
entry:
  %cond = select i1 %b, i8* getelementptr inbounds ([6 x i8]* @.str3, i64 0, i64 0), i8* getelementptr inbounds ([7 x i8]* @.str4, i64 0, i64 0)
  %call = tail call i32 (i8*, ...)* @printf(i8* %cond)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_top(i8* nocapture readonly %str) #3 {
entry:
  %puts = tail call i32 @puts(i8* %str)
  ret void
}

; Function Attrs: nounwind readnone
define %Int @-T-O_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = or i64 %1, %0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Int @Int_ti64(i64 %"$0") #4 {
entry:
  %.fca.0.insert = insertvalue %Int undef, i64 %"$0", 0
  ret %Int %.fca.0.insert
}

define %String @String_topi64b(i8* nocapture readonly %ptr, i64 %count, i1 %isUTF8Encoded) {
entry:
  %0 = trunc i64 %count to i32
  %1 = tail call i8* bitcast (i8* (i64)* @malloc to i8* (i32)*)(i32 %0)
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %1, i8* %ptr, i64 %count, i32 1, i1 false)
  br i1 %isUTF8Encoded, label %if.0, label %else.1

if.0:                                             ; preds = %entry
  %2 = shl i64 %count, 1
  %3 = or i64 %2, 1
  br label %exit

else.1:                                           ; preds = %entry
  %4 = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %count, i64 2) #6
  %5 = extractvalue { i64, i1 } %4, 1
  br i1 %5, label %"*.trap.i", label %-A_tII.exit

"*.trap.i":                                       ; preds = %else.1
  tail call void @llvm.trap() #6
  unreachable

-A_tII.exit:                                      ; preds = %else.1
  %6 = extractvalue { i64, i1 } %4, 0
  %7 = shl i64 %6, 1
  br label %exit

exit:                                             ; preds = %-A_tII.exit, %if.0
  %.sink11 = phi i64 [ %3, %if.0 ], [ %7, %-A_tII.exit ]
  %.fca.0.insert = insertvalue %String undef, i8* %1, 0
  %.fca.1.0.insert = insertvalue %String %.fca.0.insert, i64 %count, 1, 0
  %.fca.2.0.insert = insertvalue %String %.fca.1.0.insert, i64 %.sink11, 2, 0
  ret %String %.fca.2.0.insert
}

; Function Attrs: nounwind readnone
define %Bool @Bool_tB(%Bool %val) #4 {
entry:
  ret %Bool %val
}

; Function Attrs: nounwind readnone
define %Bool @Bool_tb(i1 %"$0") #4 {
entry:
  %.fca.0.insert = insertvalue %Bool undef, i1 %"$0", 0
  ret %Bool %.fca.0.insert
}

; Function Attrs: nounwind readonly
define %Bool @isUTF8Encoded_mString(%String* nocapture readonly %self) #5 {
entry:
  %0 = getelementptr inbounds %String* %self, i64 0, i32 2, i32 0
  %1 = load i64* %0, align 8
  %2 = and i64 %1, 1
  %3 = icmp ne i64 %2, 0
  %.fca.0.insert.i.i1 = insertvalue %Bool undef, i1 %3, 0
  ret %Bool %.fca.0.insert.i.i1
}

; Function Attrs: nounwind readnone
define %Bool @Bool_t() #4 {
entry:
  ret %Bool zeroinitializer
}

; Function Attrs: nounwind
define %Int @-A_tII(%Int %a, %Int %b) #6 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %0, i64 %1)
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"*.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %4, 0
  ret %Int %.fca.0.insert.i

"*.trap":                                         ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: nounwind readnone
define %Int @Int_t() #4 {
entry:
  ret %Int zeroinitializer
}

; Function Attrs: nounwind readnone
define %Bool @-E-E_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp eq i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind
define void @print_tI(%Int %a) #6 {
entry:
  %0 = extractvalue %Int %a, 0
  tail call void @vist-Uprint_ti64(i64 %0)
  ret void
}

; Function Attrs: nounwind readnone
define %String @String_topII(i8* %"$0", %Int %"$1", %Int %"$2") #4 {
entry:
  %"$1.fca.0.extract" = extractvalue %Int %"$1", 0
  %"$2.fca.0.extract" = extractvalue %Int %"$2", 0
  %.fca.0.insert = insertvalue %String undef, i8* %"$0", 0
  %.fca.1.0.insert = insertvalue %String %.fca.0.insert, i64 %"$1.fca.0.extract", 1, 0
  %.fca.2.0.insert = insertvalue %String %.fca.1.0.insert, i64 %"$2.fca.0.extract", 2, 0
  ret %String %.fca.2.0.insert
}

; Function Attrs: nounwind readnone
define %Int @-L-L_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = shl i64 %0, %1
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Int @Int_tI(%Int %val) #4 {
entry:
  ret %Int %val
}

; Function Attrs: nounwind readnone
define %Int @-G-G_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = ashr i64 %0, %1
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind
define void @print_tB(%Bool %a) #6 {
entry:
  %0 = extractvalue %Bool %a, 0
  tail call void @vist-Uprint_tb(i1 %0)
  ret void
}

define void @main() {
entry:
  %0 = tail call i8* bitcast (i8* (i64)* @malloc to i8* (i32)*)(i32 5)
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %0, i8* getelementptr inbounds ([5 x i8]* @0, i64 0, i64 0), i64 5, i32 1, i1 false)
  tail call void @vist-Uprint_ti64(i64 11) #6
  tail call void @vist-Uprint_ti64(i64 5) #6
  tail call void @vist-Uprint_tb(i1 true) #6
  ret void
}

; Function Attrs: nounwind readnone
define %Int @-T-N_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = and i64 %1, %0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readonly
define %Int @bufferCapacity_mString(%String* nocapture readonly %self) #5 {
entry:
  %0 = getelementptr inbounds %String* %self, i64 0, i32 2, i32 0
  %1 = load i64* %0, align 8
  %2 = ashr i64 %1, 1
  %.fca.0.insert.i.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i.i
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #6

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #4

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #7

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #6

attributes #0 = { alwaysinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline nounwind readonly ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind readnone }
attributes #5 = { nounwind readonly }
attributes #6 = { nounwind }
attributes #7 = { noreturn nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
!1 = !{i32 1, !"PIC Level", i32 2}
