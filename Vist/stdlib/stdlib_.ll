; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%struct.RefcountedObject = type { i8*, i32 }
%Bool = type { i1 }
%Int = type { i64 }
%Double = type { double }
%Range = type { %Int, %Int }
%Int32 = type { i32 }
%String = type { i8*, i64 }

@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str3 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str4 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1
@.str5 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

; Function Attrs: nounwind ssp uwtable
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

; Function Attrs: nounwind ssp uwtable
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

; Function Attrs: noinline ssp uwtable
define { i8*, i32 } @vist_allocObject(i32 %size) #1 {
entry:
  %retval = alloca %struct.RefcountedObject, align 8
  %size.addr = alloca i32, align 4
  %object = alloca i8*, align 8
  %refCount = alloca i32, align 4
  store i32 %size, i32* %size.addr, align 4
  %0 = load i32* %size.addr, align 4
  %conv = zext i32 %0 to i64
  %call = call i8* @malloc(i64 %conv)
  store i8* %call, i8** %object, align 8
  store i32 1, i32* %refCount, align 4
  %object1 = getelementptr inbounds %struct.RefcountedObject* %retval, i32 0, i32 0
  %1 = load i8** %object, align 8
  store i8* %1, i8** %object1, align 8
  %refCount2 = getelementptr inbounds %struct.RefcountedObject* %retval, i32 0, i32 1
  %2 = load i32* %refCount, align 4
  store i32 %2, i32* %refCount2, align 4
  %3 = bitcast %struct.RefcountedObject* %retval to { i8*, i32 }*
  %4 = load { i8*, i32 }* %3, align 1
  ret { i8*, i32 } %4
}

declare i8* @malloc(i64) #2

; Function Attrs: noinline ssp uwtable
define void @vist_deallocObject(%struct.RefcountedObject* %object) #1 {
entry:
  %object.addr = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  %object1 = getelementptr inbounds %struct.RefcountedObject* %0, i32 0, i32 0
  %1 = load i8** %object1, align 8
  call void @free(i8* %1)
  %2 = load %struct.RefcountedObject** %object.addr, align 8
  %3 = bitcast %struct.RefcountedObject* %2 to i8*
  call void @free(i8* %3)
  ret void
}

declare void @free(i8*) #2

; Function Attrs: noinline ssp uwtable
define void @vist_releaseObject(%struct.RefcountedObject* %object, i32 %size) #1 {
entry:
  %object.addr = alloca %struct.RefcountedObject*, align 8
  %size.addr = alloca i32, align 4
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  store i32 %size, i32* %size.addr, align 4
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  %refCount = getelementptr inbounds %struct.RefcountedObject* %0, i32 0, i32 1
  %1 = load i32* %refCount, align 4
  %cmp = icmp eq i32 %1, 1
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %2 = load %struct.RefcountedObject** %object.addr, align 8
  call void @vist_deallocObject(%struct.RefcountedObject* %2)
  br label %if.end

if.else:                                          ; preds = %entry
  %3 = load %struct.RefcountedObject** %object.addr, align 8
  call void @_Z17decrementRefCountP16RefcountedObject(%struct.RefcountedObject* %3)
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist_retainObject(%struct.RefcountedObject* %object) #3 {
entry:
  %object.addr = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  call void @_Z17incrementRefCountP16RefcountedObject(%struct.RefcountedObject* %0)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define i32 @vist_getObjectRefcount(%struct.RefcountedObject* %object) #3 {
entry:
  %object.addr = alloca %struct.RefcountedObject*, align 8
  store %struct.RefcountedObject* %object, %struct.RefcountedObject** %object.addr, align 8
  %0 = load %struct.RefcountedObject** %object.addr, align 8
  %refCount = getelementptr inbounds %struct.RefcountedObject* %0, i32 0, i32 1
  %1 = load i32* %refCount, align 4
  ret i32 %1
}

; Function Attrs: noinline nounwind ssp uwtable
define zeroext i1 @vist_objectHasUniqueReference(%struct.RefcountedObject* %object) #3 {
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
define void @vist-Uprint_ti64(i64 %i) #1 {
entry:
  %i.addr = alloca i64, align 8
  store i64 %i, i64* %i.addr, align 8
  %0 = load i64* %i.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i64 %0)
  ret void
}

declare i32 @printf(i8*, ...) #2

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_ti32(i32 %i) #1 {
entry:
  %i.addr = alloca i32, align 4
  store i32 %i, i32* %i.addr, align 4
  %0 = load i32* %i.addr, align 4
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %0)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_tf64(double %d) #1 {
entry:
  %d.addr = alloca double, align 8
  store double %d, double* %d.addr, align 8
  %0 = load double* %d.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %0)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_tf32(float %d) #1 {
entry:
  %d.addr = alloca float, align 4
  store float %d, float* %d.addr, align 4
  %0 = load float* %d.addr, align 4
  %conv = fpext float %0 to double
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %conv)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_tb(i1 zeroext %b) #1 {
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
define void @vist-Uprint_top(i8* %str) #1 {
entry:
  %str.addr = alloca i8*, align 8
  store i8* %str, i8** %str.addr, align 8
  %0 = load i8** %str.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str5, i32 0, i32 0), i8* %0)
  ret void
}

define %Bool @-L_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp slt i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Bool @-E-E_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp eq i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Bool @-Uexpect_tBoolBool(%Bool %val, %Bool %assume) {
entry:
  %0 = extractvalue %Bool %val, 0
  %1 = extractvalue %Bool %assume, 0
  %2 = call i1 @llvm.expect.i1(i1 %0, i1 %1)
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Int @Int_ti64(i64 %"$0") {
entry:
  %self = alloca %Int
  %value = getelementptr inbounds %Int* %self, i32 0, i32 0
  store i64 %"$0", i64* %value
  %0 = load %Int* %self
  ret %Int %0
}

define %Double @-P_tDoubleDouble(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fadd double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

define %Int @-G-G_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = ashr i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define %Double @Double_tf64(double %"$0") {
entry:
  %self = alloca %Double
  %value = getelementptr inbounds %Double* %self, i32 0, i32 0
  store double %"$0", double* %value
  %0 = load %Double* %self
  ret %Double %0
}

define %Double @Double_tDouble(%Double %val) {
entry:
  %self = alloca %Double
  %value = getelementptr inbounds %Double* %self, i32 0, i32 0
  %0 = extractvalue %Double %val, 0
  store double %0, double* %value
  %1 = load %Double* %self
  ret %Double %1
}

define %Bool @-N-N_tBoolBool(%Bool %a, %Bool %b) {
entry:
  %0 = extractvalue %Bool %a, 0
  %1 = extractvalue %Bool %b, 0
  %2 = and i1 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Int @-T-O_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = or i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define %Int @-C_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = srem i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define %Range @Range_tRange(%Range %val) {
entry:
  %self = alloca %Range
  %start = getelementptr inbounds %Range* %self, i32 0, i32 0
  %end = getelementptr inbounds %Range* %self, i32 0, i32 1
  %0 = extractvalue %Range %val, 0
  store %Int %0, %Int* %start
  %1 = extractvalue %Range %val, 1
  store %Int %1, %Int* %end
  %2 = load %Range* %self
  ret %Range %2
}

define %Bool @Bool_tBool(%Bool %val) {
entry:
  %self = alloca %Bool
  %value = getelementptr inbounds %Bool* %self, i32 0, i32 0
  %0 = extractvalue %Bool %val, 0
  store i1 %0, i1* %value
  %1 = load %Bool* %self
  ret %Bool %1
}

define void @print_tDouble(%Double %a) {
entry:
  %0 = extractvalue %Double %a, 0
  call void @vist-Uprint_tf64(double %0)
  ret void
}

define %Bool @-E-E_tDoubleDouble(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp oeq double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define void @fatalError_t() {
entry:
  call void @llvm.trap()
  ret void
}

define %Range @-D-D-D_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = call %Range @Range_tIntInt(%Int %a, %Int %b)
  ret %Range %0
}

define %Int32 @Int32_ti32(i32 %"$0") {
entry:
  %self = alloca %Int32
  %value = getelementptr inbounds %Int32* %self, i32 0, i32 0
  store i32 %"$0", i32* %value
  %0 = load %Int32* %self
  ret %Int32 %0
}

define %Int @-M_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %-.trap, label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int @Int_ti64(i64 %4)
  ret %Int %5

-.trap:                                           ; preds = %entry
  call void @llvm.trap()
  unreachable
}

define %Bool @"!-E_tDoubleDouble"(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp one double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Double @-M_tDoubleDouble(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fadd double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

define %Double @-C_tDoubleDouble(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = frem double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

define %Int @-T-N_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = and i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define %Bool @-L-E_tDoubleDouble(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ole double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Bool @-O-O_tBoolBool(%Bool %a, %Bool %b) {
entry:
  %0 = extractvalue %Bool %a, 0
  %1 = extractvalue %Bool %b, 0
  %2 = and i1 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Double @-D_tDoubleDouble(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fdiv double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

define %Bool @Bool_tb(i1 %"$0") {
entry:
  %self = alloca %Bool
  %value = getelementptr inbounds %Bool* %self, i32 0, i32 0
  store i1 %"$0", i1* %value
  %0 = load %Bool* %self
  ret %Bool %0
}

define %Bool @-L-E_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sle i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Range @-D-D-L_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = call %Int @-M_tIntInt(%Int %b, %Int { i64 1 })
  %1 = call %Range @Range_tIntInt(%Int %a, %Int %0)
  ret %Range %1
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

define void @print_tBool(%Bool %a) {
entry:
  %0 = extractvalue %Bool %a, 0
  call void @vist-Uprint_tb(i1 %0)
  ret void
}

define %Double @-A_tDoubleDouble(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fmul double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

define void @print_tString(%String %a) {
entry:
  %0 = extractvalue %String %a, 0
  call void @vist-Uprint_top(i8* %0)
  ret void
}

define void @print_tInt(%Int %a) {
entry:
  %0 = extractvalue %Int %a, 0
  call void @vist-Uprint_ti64(i64 %0)
  ret void
}

define %Int @-A_tIntInt(%Int %a, %Int %b) {
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

define %Bool @-G-E_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sge i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Int @-L-L_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = shl i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define %String @String_topi64(i8* %ptr, i64 %count) {
entry:
  %self = alloca %String
  %base = getelementptr inbounds %String* %self, i32 0, i32 0
  %length = getelementptr inbounds %String* %self, i32 0, i32 1
  %0 = trunc i64 %count to i32
  %mallocsize = mul i32 %0, ptrtoint (i8* getelementptr (i8* null, i32 1) to i32)
  %1 = tail call i8* bitcast (i8* (i64)* @malloc to i8* (i32)*)(i32 %mallocsize)
  %buffer = alloca i8*
  store i8* %1, i8** %buffer
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %1, i8* %ptr, i64 %count, i32 1, i1 false)
  store i8* %1, i8** %base
  store i64 %count, i64* %length
  %2 = load %String* %self
  ret %String %2
}

define void @assert_tBool(%Bool %"$0") {
entry:
  %0 = call %Bool @-Uexpect_tBoolBool(%Bool %"$0", %Bool { i1 true })
  %1 = extractvalue %Bool %0, 0
  br i1 %1, label %if.0, label %fail.0

if.0:                                             ; preds = %entry
  br label %exit

fail.0:                                           ; preds = %entry
  br label %else.1

else.1:                                           ; preds = %fail.0
  call void @llvm.trap()
  br label %exit

exit:                                             ; preds = %else.1, %if.0
  ret void
}

define %Int @-T-R_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = xor i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define %Int @Int_tInt(%Int %val) {
entry:
  %self = alloca %Int
  %value = getelementptr inbounds %Int* %self, i32 0, i32 0
  %0 = extractvalue %Int %val, 0
  store i64 %0, i64* %value
  %1 = load %Int* %self
  ret %Int %1
}

define %Bool @-G_tDoubleDouble(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ogt double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Int32 @Int32_tInt32(%Int32 %val) {
entry:
  %self = alloca %Int32
  %value = getelementptr inbounds %Int32* %self, i32 0, i32 0
  %0 = extractvalue %Int32 %val, 0
  store i32 %0, i32* %value
  %1 = load %Int32* %self
  ret %Int32 %1
}

define void @print_tInt32(%Int32 %a) {
entry:
  %0 = extractvalue %Int32 %a, 0
  call void @vist-Uprint_ti32(i32 %0)
  ret void
}

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

define %Bool @-G_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sgt i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Range @Range_tIntInt(%Int %"$0", %Int %"$1") {
entry:
  %self = alloca %Range
  %start = getelementptr inbounds %Range* %self, i32 0, i32 0
  %end = getelementptr inbounds %Range* %self, i32 0, i32 1
  store %Int %"$0", %Int* %start
  store %Int %"$1", %Int* %end
  %0 = load %Range* %self
  ret %Range %0
}

define %Bool @"!-E_tIntInt"(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp ne i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Int @-D_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = call %Bool @"!-E_tIntInt"(%Int %b, %Int zeroinitializer)
  call void @assert_tBool(%Bool %0)
  %1 = extractvalue %Int %a, 0
  %2 = extractvalue %Int %b, 0
  %3 = sdiv i64 %1, %2
  %4 = call %Int @Int_ti64(i64 %3)
  ret %Int %4
}

define %Bool @-G-E_tDoubleDouble(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp oge double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define %Int @-P_tIntInt(%Int %a, %Int %b) {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"+.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int @Int_ti64(i64 %4)
  ret %Int %5

"+.trap":                                         ; preds = %entry
  call void @llvm.trap()
  unreachable
}

define %Bool @-L_tDoubleDouble(%Double %a, %Double %b) {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp olt double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: nounwind readnone
declare i1 @llvm.expect.i1(i1, i1) #4

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #5

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #4

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #4

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #6

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #4

attributes #0 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind readnone }
attributes #5 = { noreturn nounwind }
attributes #6 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
!1 = !{i32 1, !"PIC Level", i32 2}
