; ModuleID = 'example'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%HalfOpenRange = type { %Int, %Int }
%Int = type { i64 }
%Bool = type { i1 }

; Function Attrs: alwaysinline
define %HalfOpenRange @HalfOpenRange_tII(%Int %"$0", %Int %"$1") #0 {
entry:
  %self = alloca %HalfOpenRange
  %start = getelementptr inbounds %HalfOpenRange* %self, i32 0, i32 0
  %end = getelementptr inbounds %HalfOpenRange* %self, i32 0, i32 1
  store %Int %"$0", %Int* %start
  store %Int %"$1", %Int* %end
  %0 = load %HalfOpenRange* %self
  ret %HalfOpenRange %0
}

declare %Bool @-L_tII(%Int, %Int)

; Function Attrs: alwaysinline
define void @generate_mHalfOpenRangePtI.loop_thunk(%Int %a) #0 {
entry:
  call void @print_tI(%Int %a), !stdlib.call.optim !0
  ret void
}

declare void @print_tI(%Int)

declare %Int @-P_tII(%Int, %Int)

; Function Attrs: alwaysinline
define void @generate_mHalfOpenRangePtI(%HalfOpenRange %self, void (%Int)* %loop_thunk) #0 {
entry:
  %start = extractvalue %HalfOpenRange %self, 0
  %0 = alloca %Int
  store %Int %start, %Int* %0
  br label %cond

cond:                                             ; preds = %loop, %entry
  %1 = load %Int* %0
  %end = extractvalue %HalfOpenRange %self, 1
  %2 = call %Bool @-L_tII(%Int %1, %Int %end), !stdlib.call.optim !0
  %cond1 = extractvalue %Bool %2, 0
  br i1 %cond1, label %loop, label %loop.exit

loop:                                             ; preds = %cond
  %3 = load %Int* %0
  call void %loop_thunk(%Int %3)
  %4 = load %Int* %0
  %5 = call %Int @-P_tII(%Int %4, %Int { i64 1 }), !stdlib.call.optim !0
  store %Int %5, %Int* %0
  br label %cond

loop.exit:                                        ; preds = %cond
  ret void
}

define void @main() {
entry:
  %0 = call %HalfOpenRange @HalfOpenRange_tII(%Int { i64 1 }, %Int { i64 10 })
  %range = alloca %HalfOpenRange
  store %HalfOpenRange %0, %HalfOpenRange* %range
  call void @generate_mHalfOpenRangePtI(%HalfOpenRange %0, void (%Int)* @generate_mHalfOpenRangePtI.loop_thunk)
  ret void
}

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
