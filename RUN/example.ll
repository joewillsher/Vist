; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int = type { i64 }
%Range = type { %Int, %Int }

@a.globlstorage = unnamed_addr global %Int* null

declare %Range @-D-D-D_tII(%Int, %Int)

declare void @print_tI(%Int)

declare void @generate_mRPtI(%Range, void (%Int)*)

; Function Attrs: alwaysinline
define void @main.loop_thunk(%Int %x) #0 {
entry:
  %0 = load %Int** @a.globlstorage, align 8
  %1 = load %Int* %0, align 8
  %2 = tail call %Int @-A_tII(%Int %x, %Int %1), !stdlib.call.optim !0
  store %Int %2, %Int* %0, align 8
  tail call void @print_tI(%Int %2), !stdlib.call.optim !0
  ret void
}

define void @main() {
entry:
  %0 = alloca %Int, align 8
  %.fca.0.gep = getelementptr inbounds %Int* %0, i64 0, i32 0
  store i64 1, i64* %.fca.0.gep, align 8
  store %Int* %0, %Int** @a.globlstorage, align 8
  %1 = call %Range @-D-D-D_tII(%Int { i64 1 }, %Int { i64 10 }), !stdlib.call.optim !0
  call void @generate_mRPtI(%Range %1, void (%Int)* @main.loop_thunk)
  %.fca.0.load = load i64* %.fca.0.gep, align 8
  %.fca.0.insert = insertvalue %Int undef, i64 %.fca.0.load, 0
  call void @print_tI(%Int %.fca.0.insert), !stdlib.call.optim !0
  ret void
}

declare %Int @-A_tII(%Int, %Int)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
