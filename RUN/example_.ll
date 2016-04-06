; ModuleID = 'example'
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
@.str5 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@0 = private unnamed_addr constant [5 x i8] c"meme\00"

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
define void @vist-Uprint_ti64(i64 %i) #3 {
entry:
  %i.addr = alloca i64, align 8
  store i64 %i, i64* %i.addr, align 8
  %0 = load i64* %i.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i64 %0)
  ret void
}

declare i32 @printf(i8*, ...) #2

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_ti32(i32 %i) #3 {
entry:
  %i.addr = alloca i32, align 4
  store i32 %i, i32* %i.addr, align 4
  %0 = load i32* %i.addr, align 4
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %0)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_tf64(double %d) #3 {
entry:
  %d.addr = alloca double, align 8
  store double %d, double* %d.addr, align 8
  %0 = load double* %d.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %0)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_tf32(float %d) #3 {
entry:
  %d.addr = alloca float, align 4
  store float %d, float* %d.addr, align 4
  %0 = load float* %d.addr, align 4
  %conv = fpext float %0 to double
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %conv)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_tb(i1 zeroext %b) #3 {
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
define void @vist-Uprint_top(i8* %str) #3 {
entry:
  %str.addr = alloca i8*, align 8
  store i8* %str, i8** %str.addr, align 8
  %0 = load i8** %str.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str5, i32 0, i32 0), i8* %0)
  ret void
}

define %Int @-T-O_tII(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = or i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define %Int @Int_ti64(i64 %"$0") {
entry:
  %self = alloca %Int
  %value = getelementptr inbounds %Int* %self, i32 0, i32 0
  store i64 %"$0", i64* %value
  %0 = load %Int* %self
  ret %Int %0
}

define %String @String_topi64b(i8* %ptr, i64 %count, i1 %isUTF8Encoded) {
entry:
  %self = alloca %String
  %base = getelementptr inbounds %String* %self, i32 0, i32 0
  %length = getelementptr inbounds %String* %self, i32 0, i32 1
  %capacityAndEncoding = getelementptr inbounds %String* %self, i32 0, i32 2
  %0 = trunc i64 %count to i32
  %mallocsize = mul i32 %0, ptrtoint (i8* getelementptr (i8* null, i32 1) to i32)
  %1 = tail call i8* bitcast (i8* (i64)* @malloc to i8* (i32)*)(i32 %mallocsize)
  %buffer = alloca i8*
  store i8* %1, i8** %buffer
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %1, i8* %ptr, i64 %count, i32 1, i1 false)
  store i8* %1, i8** %base
  %2 = call %Int @Int_ti64(i64 %count)
  store %Int %2, %Int* %length
  %3 = call %Bool @Bool_tb(i1 %isUTF8Encoded)
  %4 = extractvalue %Bool %3, 0
  br i1 %4, label %if.0, label %fail.0

if.0:                                             ; preds = %entry
  %5 = call %Int @Int_ti64(i64 %count)
  %6 = call %Int @-L-L_tII(%Int %5, %Int { i64 1 })
  %capacity = alloca %Int
  store %Int %6, %Int* %capacity
  %7 = call %Int @-T-O_tII(%Int %6, %Int { i64 1 })
  store %Int %7, %Int* %capacityAndEncoding
  br label %exit

fail.0:                                           ; preds = %entry
  br label %else.1

else.1:                                           ; preds = %fail.0
  %8 = call %Int @Int_ti64(i64 %count)
  %9 = call %Int @-A_tII(%Int %8, %Int { i64 2 })
  %10 = call %Int @-L-L_tII(%Int %9, %Int { i64 1 })
  store %Int %10, %Int* %capacityAndEncoding
  br label %exit

exit:                                             ; preds = %else.1, %if.0
  %11 = load %String* %self
  ret %String %11
}

define %Bool @Bool_tB(%Bool %val) {
entry:
  %self = alloca %Bool
  %value = getelementptr inbounds %Bool* %self, i32 0, i32 0
  %0 = extractvalue %Bool %val, 0
  store i1 %0, i1* %value
  %1 = load %Bool* %self
  ret %Bool %1
}

define %Bool @Bool_tb(i1 %"$0") {
entry:
  %self = alloca %Bool
  %value = getelementptr inbounds %Bool* %self, i32 0, i32 0
  store i1 %"$0", i1* %value
  %0 = load %Bool* %self
  ret %Bool %0
}

define %Bool @isUTF8Encoded_mString(%String* %self) {
entry:
  %capacityAndEncoding = getelementptr inbounds %String* %self, i32 0, i32 2
  %0 = load %Int* %capacityAndEncoding
  %1 = call %Int @-T-N_tII(%Int %0, %Int { i64 1 })
  %2 = call %Bool @-E-E_tII(%Int %1, %Int { i64 1 })
  ret %Bool %2
}

define %Bool @Bool_t() {
entry:
  %self = alloca %Bool
  %value = getelementptr inbounds %Bool* %self, i32 0, i32 0
  %b = alloca %Bool
  store %Bool zeroinitializer, %Bool* %b
  store i1 false, i1* %value
  %0 = load %Bool* %self
  ret %Bool %0
}

define %Int @-A_tII(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"*.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int @Int_ti64(i64 %4)
  ret %Int %5

"*.trap":                                         ; preds = %entry
  call void @llvm.trap()
  unreachable
}

declare %Bool @isUTF8Encoded(%String*)

define %Int @Int_t() {
entry:
  %self = alloca %Int
  %value = getelementptr inbounds %Int* %self, i32 0, i32 0
  %v = alloca %Int
  store %Int zeroinitializer, %Int* %v
  store i64 0, i64* %value
  %0 = load %Int* %self
  ret %Int %0
}

define %Bool @-E-E_tII(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp eq i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define void @print_tI(%Int %a) {
entry:
  %0 = extractvalue %Int %a, 0
  call void @vist-Uprint_ti64(i64 %0)
  ret void
}

define %String @String_topII(i8* %"$0", %Int %"$1", %Int %"$2") {
entry:
  %self = alloca %String
  %base = getelementptr inbounds %String* %self, i32 0, i32 0
  %length = getelementptr inbounds %String* %self, i32 0, i32 1
  %capacityAndEncoding = getelementptr inbounds %String* %self, i32 0, i32 2
  store i8* %"$0", i8** %base
  store %Int %"$1", %Int* %length
  store %Int %"$2", %Int* %capacityAndEncoding
  %0 = load %String* %self
  ret %String %0
}

declare %Int @bufferCapacity(%String*)

define %Int @-L-L_tII(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = shl i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define %Int @Int_tI(%Int %val) {
entry:
  %self = alloca %Int
  %value = getelementptr inbounds %Int* %self, i32 0, i32 0
  %0 = extractvalue %Int %val, 0
  store i64 %0, i64* %value
  %1 = load %Int* %self
  ret %Int %1
}

define %Int @-G-G_tII(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = ashr i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define void @print_tB(%Bool %a) {
entry:
  %0 = extractvalue %Bool %a, 0
  call void @vist-Uprint_tb(i1 %0)
  ret void
}

define void @main() {
entry:
  %0 = call %String @String_topi64b(i8* getelementptr inbounds ([5 x i8]* @0, i32 0, i32 0), i64 5, i1 true)
  %a = alloca %String
  store %String %0, %String* %a
  %1 = extractvalue %String %0, 2
  call void @print_tI(%Int %1)
  %2 = alloca %String
  store %String %0, %String* %2
  %3 = call %Int @bufferCapacity_mString(%String* %2)
  call void @print_tI(%Int %3)
  %4 = alloca %String
  store %String %0, %String* %4
  %5 = call %Bool @isUTF8Encoded_mString(%String* %4)
  call void @print_tB(%Bool %5)
  ret void
}

define %Int @-T-N_tII(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = and i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define %Int @bufferCapacity_mString(%String* %self) {
entry:
  %capacityAndEncoding = getelementptr inbounds %String* %self, i32 0, i32 2
  %0 = load %Int* %capacityAndEncoding
  %1 = call %Int @-G-G_tII(%Int %0, %Int { i64 1 })
  ret %Int %1
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #4

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #5

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #6

attributes #0 = { alwaysinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { alwaysinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }
attributes #5 = { nounwind readnone }
attributes #6 = { noreturn nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
!1 = !{i32 1, !"PIC Level", i32 2}
