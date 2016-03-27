; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bool.st = type { i1 }
%Int.st = type { i64 }
%Int32.st = type { i32 }
%Range.st = type { %Int.st, %Int.st }
%Double.st = type { double }

define %Bool.st @Bool_() {
entry:
  %self = alloca %Bool.st
  %value = getelementptr inbounds %Bool.st* %self, i32 0, i32 0
  %b = alloca %Bool.st
  store %Bool.st zeroinitializer, %Bool.st* %b
  store i1 false, i1* %value
  %0 = load %Bool.st* %self
  ret %Bool.st %0
}

define void @print_Bool(%Bool.st %a) {
entry:
  %0 = extractvalue %Bool.st %a, 0
  call void @-Uprint_b(i1 %0)
  ret void
}

declare void @-Uprint_b(i1)

define void @condFail_b(i1 %cond) {
entry:
  %0 = call %Bool.st @Bool_b(i1 %cond)
  %1 = call %Bool.st @-Uexpect_Bool_Bool(%Bool.st %0, %Bool.st zeroinitializer)
  %2 = extractvalue %Bool.st %1, 0
  br i1 %2, label %if.0, label %exit

if.0:                                             ; preds = %entry
  br label %exit

exit:                                             ; preds = %if.0, %entry
  ret void
}

define %Bool.st @-E-E_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp eq i64 %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Bool.st @Bool_b(i1 %"$0") {
entry:
  %self = alloca %Bool.st
  %value = getelementptr inbounds %Bool.st* %self, i32 0, i32 0
  store i1 %"$0", i1* %value
  %0 = load %Bool.st* %self
  ret %Bool.st %0
}

define void @print_Int32(%Int32.st %a) {
entry:
  %0 = extractvalue %Int32.st %a, 0
  call void @-Uprint_i32(i32 %0)
  ret void
}

define %Int.st @-P_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"+.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int.st @Int_i64(i64 %4)
  ret %Int.st %5

"+.trap":                                         ; preds = %entry
  call void @llvm.trap()
  unreachable
}

define %Int.st @-M_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  call void @condFail_b(i1 %3)
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int.st @Int_i64(i64 %4)
  ret %Int.st %5
}

define %Range.st @Range_Int_Int(%Int.st %"$0", %Int.st %"$1") {
entry:
  %self = alloca %Range.st
  %start = getelementptr inbounds %Range.st* %self, i32 0, i32 0
  %end = getelementptr inbounds %Range.st* %self, i32 0, i32 1
  store %Int.st %"$0", %Int.st* %start
  store %Int.st %"$1", %Int.st* %end
  %0 = load %Range.st* %self
  ret %Range.st %0
}

define %Int.st @-A_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  call void @condFail_b(i1 %3)
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int.st @Int_i64(i64 %4)
  ret %Int.st %5
}

declare void @-Uprint_f64(double)

define %Int.st @Int_i64(i64 %"$0") {
entry:
  %self = alloca %Int.st
  %value = getelementptr inbounds %Int.st* %self, i32 0, i32 0
  store i64 %"$0", i64* %value
  %0 = load %Int.st* %self
  ret %Int.st %0
}

declare void @-Uprint_i64(i64)

declare void @-Uprint_i32(i32)

define void @print_Double(%Double.st %a) {
entry:
  %0 = extractvalue %Double.st %a, 0
  call void @-Uprint_f64(double %0)
  ret void
}

define %Int32.st @Int32_i32(i32 %"$0") {
entry:
  %self = alloca %Int32.st
  %value = getelementptr inbounds %Int32.st* %self, i32 0, i32 0
  store i32 %"$0", i32* %value
  %0 = load %Int32.st* %self
  ret %Int32.st %0
}

define %Int.st @Int_() {
entry:
  %self = alloca %Int.st
  %value = getelementptr inbounds %Int.st* %self, i32 0, i32 0
  %v = alloca %Int.st
  store %Int.st zeroinitializer, %Int.st* %v
  store i64 0, i64* %value
  %0 = load %Int.st* %self
  ret %Int.st %0
}

define %Double.st @Double_f64(double %"$0") {
entry:
  %self = alloca %Double.st
  %value = getelementptr inbounds %Double.st* %self, i32 0, i32 0
  store double %"$0", double* %value
  %0 = load %Double.st* %self
  ret %Double.st %0
}

define %Bool.st @-Uexpect_Bool_Bool(%Bool.st %val, %Bool.st %assume) {
entry:
  %0 = extractvalue %Bool.st %val, 0
  %1 = extractvalue %Bool.st %assume, 0
  %2 = call i1 @llvm.expect.i1(i1 %0, i1 %1)
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define void @fatalError_() {
entry:
  ret void
}

define void @main() {
entry:
  ret void
}

define void @print_Int(%Int.st %a) {
entry:
  %0 = extractvalue %Int.st %a, 0
  call void @-Uprint_i64(i64 %0)
  ret void
}

define void @assert_Bool(%Bool.st %"$0") {
entry:
  %0 = call %Bool.st @-Uexpect_Bool_Bool(%Bool.st %"$0", %Bool.st { i1 true })
  %1 = extractvalue %Bool.st %0, 0
  br i1 %1, label %if.0, label %fail.0

if.0:                                             ; preds = %entry
  br label %exit

fail.0:                                           ; preds = %entry
  br label %else.1

else.1:                                           ; preds = %fail.0
  br label %exit

exit:                                             ; preds = %else.1, %if.0
  ret void
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #0

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #1

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #0

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #0

; Function Attrs: nounwind readnone
declare i1 @llvm.expect.i1(i1, i1) #0

attributes #0 = { nounwind readnone }
attributes #1 = { noreturn nounwind }
