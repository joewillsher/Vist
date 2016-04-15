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
define void @generate_mHalfOpenRangePtI(%HalfOpenRange %self, void (%Int)* nocapture %loop_thunk) #1 {
entry:
  %start = extractvalue %HalfOpenRange %self, 0
  %end = extractvalue %HalfOpenRange %self, 1
  %0 = tail call %Bool @-L_tII(%Int %start, %Int %end), !stdlib.call.optim !0
  %cond110 = extractvalue %Bool %0, 0
  br i1 %cond110, label %loop.preheader, label %loop.exit

loop.preheader:                                   ; preds = %entry
  br label %loop

loop:                                             ; preds = %loop.preheader, %loop
  %start.sink11 = phi %Int [ %1, %loop ], [ %start, %loop.preheader ]
  tail call void %loop_thunk(%Int %start.sink11)
  %1 = tail call %Int @-P_tII(%Int %start.sink11, %Int { i64 1 }), !stdlib.call.optim !0
  %2 = tail call %Bool @-L_tII(%Int %1, %Int %end), !stdlib.call.optim !0
  %cond1 = extractvalue %Bool %2, 0
  br i1 %cond1, label %loop, label %loop.exit.loopexit

loop.exit.loopexit:                               ; preds = %loop
  br label %loop.exit

loop.exit:                                        ; preds = %loop.exit.loopexit, %entry
  ret void
}

define void @main() {
entry:
  %0 = tail call %Bool @-L_tII(%Int { i64 1 }, %Int { i64 10 }), !stdlib.call.optim !0
  %cond110.i = extractvalue %Bool %0, 0
  br i1 %cond110.i, label %loop.i.preheader, label %generate_mHalfOpenRangePtI.exit

loop.i.preheader:                                 ; preds = %entry
  br label %loop.i

loop.i:                                           ; preds = %loop.i.preheader, %loop.i
  %start.sink11.i = phi %Int [ %1, %loop.i ], [ { i64 1 }, %loop.i.preheader ]
  tail call void @print_tI(%Int %start.sink11.i), !stdlib.call.optim !0
  %1 = tail call %Int @-P_tII(%Int %start.sink11.i, %Int { i64 1 }), !stdlib.call.optim !0
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
