; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%HalfOpenRange = type { %Int, %Int }
%Int = type { i64 }
%Bool = type { i1 }

; Function Attrs: alwaysinline nounwind readnone
define %HalfOpenRange @HalfOpenRange_tII(%Int %"$0", %Int %"$1") #0 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int %"$1", 0
  %.fca.0.0.insert = insertvalue %HalfOpenRange undef, i64 %"$0.fca.0.extract", 0, 0
  %.fca.1.0.insert = insertvalue %HalfOpenRange %.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret %HalfOpenRange %.fca.1.0.insert
}

declare %Bool @-L_tII(%Int, %Int)

; Function Attrs: alwaysinline
define void @loop_thunk(%Int %a) #1 {
entry:
  tail call void @print_tI(%Int %a), !stdlib.call.optim !0
  ret void
}

declare void @print_tI(%Int)

declare %Int @-P_tII(%Int, %Int)

; Function Attrs: alwaysinline
define void @generate_mHalfOpenRangePtI(%HalfOpenRange* nocapture readonly %self, void (%Int)* nocapture %loop_thunk) #1 {
entry:
  %0 = getelementptr inbounds %HalfOpenRange* %self, i64 0, i32 0, i32 0
  %1 = load i64* %0, align 8
  %.fca.0.insert12 = insertvalue %Int undef, i64 %1, 0
  %end = getelementptr inbounds %HalfOpenRange* %self, i64 0, i32 1
  %2 = load %Int* %end, align 8
  %3 = tail call %Bool @-L_tII(%Int %.fca.0.insert12, %Int %2), !stdlib.call.optim !0
  %cond113 = extractvalue %Bool %3, 0
  br i1 %cond113, label %loop.preheader, label %loop.exit

loop.preheader:                                   ; preds = %entry
  br label %loop

loop:                                             ; preds = %loop.preheader, %loop
  %.fca.0.insert14 = phi %Int [ %4, %loop ], [ %.fca.0.insert12, %loop.preheader ]
  tail call void %loop_thunk(%Int %.fca.0.insert14)
  %4 = tail call %Int @-P_tII(%Int %.fca.0.insert14, %Int { i64 1 }), !stdlib.call.optim !0
  %5 = load %Int* %end, align 8
  %6 = tail call %Bool @-L_tII(%Int %4, %Int %5), !stdlib.call.optim !0
  %cond1 = extractvalue %Bool %6, 0
  br i1 %cond1, label %loop, label %loop.exit.loopexit

loop.exit.loopexit:                               ; preds = %loop
  br label %loop.exit

loop.exit:                                        ; preds = %loop.exit.loopexit, %entry
  ret void
}

define void @main() {
entry:
  %0 = tail call %Bool @-L_tII(%Int { i64 1 }, %Int { i64 10 }), !stdlib.call.optim !0
  %cond113.i = extractvalue %Bool %0, 0
  br i1 %cond113.i, label %loop.i.preheader, label %generate_mHalfOpenRangePtI.exit

loop.i.preheader:                                 ; preds = %entry
  br label %loop.i

loop.i:                                           ; preds = %loop.i.preheader, %loop.i
  %.fca.0.insert14.i = phi %Int [ %1, %loop.i ], [ { i64 1 }, %loop.i.preheader ]
  tail call void @print_tI(%Int %.fca.0.insert14.i), !stdlib.call.optim !0
  %1 = tail call %Int @-P_tII(%Int %.fca.0.insert14.i, %Int { i64 1 }), !stdlib.call.optim !0
  %2 = tail call %Bool @-L_tII(%Int %1, %Int { i64 10 }), !stdlib.call.optim !0
  %cond1.i = extractvalue %Bool %2, 0
  br i1 %cond1.i, label %loop.i, label %generate_mHalfOpenRangePtI.exit.loopexit

generate_mHalfOpenRangePtI.exit.loopexit:         ; preds = %loop.i
  br label %generate_mHalfOpenRangePtI.exit

generate_mHalfOpenRangePtI.exit:                  ; preds = %generate_mHalfOpenRangePtI.exit.loopexit, %entry
  ret void
}

attributes #0 = { alwaysinline nounwind readnone }
attributes #1 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
