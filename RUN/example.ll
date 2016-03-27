; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bool.st = type { i1 }
%Int.st = type { i64 }
%Int32.st = type { i32 }
%Range.st = type { %Int.st, %Int.st }
%Double.st = type { double }

; Function Attrs: nounwind readnone
define %Bool.st @Bool_() #0 {
entry:
  ret %Bool.st zeroinitializer
}

define void @print_Bool(%Bool.st %a) {
entry:
  %0 = extractvalue %Bool.st %a, 0
  tail call void @-Uprint_b(i1 %0)
  ret void
}

declare void @-Uprint_b(i1)

; Function Attrs: nounwind readnone
define void @condFail_b(i1 %cond) #0 {
entry:
  ret void
}

; Function Attrs: nounwind readnone
define %Bool.st @-E-E_Int_Int(%Int.st %a, %Int.st %b) #0 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp eq i64 %0, %1
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %2, 0
  ret %Bool.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @Bool_b(i1 %"$0") #0 {
entry:
  %.fca.0.insert = insertvalue %Bool.st undef, i1 %"$0", 0
  ret %Bool.st %.fca.0.insert
}

define void @print_Int32(%Int32.st %a) {
entry:
  %0 = extractvalue %Int32.st %a, 0
  tail call void @-Uprint_i32(i32 %0)
  ret void
}

; Function Attrs: nounwind
define %Int.st @-P_Int_Int(%Int.st %a, %Int.st %b) #1 {
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
define %Int.st @-M_Int_Int(%Int.st %a, %Int.st %b) #0 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = sub i64 %0, %1
  %.fca.0.insert = insertvalue %Int.st undef, i64 %2, 0
  ret %Int.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Range.st @Range_Int_Int(%Int.st %"$0", %Int.st %"$1") #0 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int.st %"$1", 0
  %.fca.0.0.insert = insertvalue %Range.st undef, i64 %"$0.fca.0.extract", 0, 0
  %.fca.1.0.insert = insertvalue %Range.st %.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret %Range.st %.fca.1.0.insert
}

; Function Attrs: nounwind readnone
define %Int.st @-A_Int_Int(%Int.st %a, %Int.st %b) #0 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = mul i64 %1, %0
  %.fca.0.insert = insertvalue %Int.st undef, i64 %2, 0
  ret %Int.st %.fca.0.insert
}

declare void @-Uprint_f64(double)

; Function Attrs: nounwind readnone
define %Int.st @Int_i64(i64 %"$0") #0 {
entry:
  %.fca.0.insert = insertvalue %Int.st undef, i64 %"$0", 0
  ret %Int.st %.fca.0.insert
}

declare void @-Uprint_i64(i64)

declare void @-Uprint_i32(i32)

define void @print_Double(%Double.st %a) {
entry:
  %0 = extractvalue %Double.st %a, 0
  tail call void @-Uprint_f64(double %0)
  ret void
}

; Function Attrs: nounwind readnone
define %Int32.st @Int32_i32(i32 %"$0") #0 {
entry:
  %.fca.0.insert = insertvalue %Int32.st undef, i32 %"$0", 0
  ret %Int32.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Int.st @Int_() #0 {
entry:
  ret %Int.st zeroinitializer
}

; Function Attrs: nounwind readnone
define %Double.st @Double_f64(double %"$0") #0 {
entry:
  %.fca.0.insert = insertvalue %Double.st undef, double %"$0", 0
  ret %Double.st %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool.st @-Uexpect_Bool_Bool(%Bool.st %val, %Bool.st %assume) #0 {
entry:
  ret %Bool.st %val
}

; Function Attrs: nounwind readnone
define void @fatalError_() #0 {
entry:
  ret void
}

; Function Attrs: nounwind readnone
define void @main() #0 {
entry:
  ret void
}

define void @print_Int(%Int.st %a) {
entry:
  %0 = extractvalue %Int.st %a, 0
  tail call void @-Uprint_i64(i64 %0)
  ret void
}

; Function Attrs: nounwind readnone
define void @assert_Bool(%Bool.st %"$0") #0 {
entry:
  ret void
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #0

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #2

attributes #0 = { nounwind readnone }
attributes #1 = { nounwind }
attributes #2 = { noreturn nounwind }
