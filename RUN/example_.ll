; ModuleID = 'example'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

<<<<<<< HEAD
=======
%Int = type { i64 }
%Range = type { %Int, %Int }
%HalfOpenRange = type { %Int, %Int }
%Bool = type { i1 }
>>>>>>> parent of 0bc95a6... Started working on LLVM wrapper
%String = type { i8*, %Int, %Int }
%Int = type { i64 }

<<<<<<< HEAD
@0 = private unnamed_addr constant [17 x i8] c"\F0\9F\A4\94\F0\9F\A4\94\F0\9F\A4\94\F0\9F\A4\94\00"
=======
@a.globlstorage = unnamed_addr global %Int* null
@0 = private unnamed_addr constant [4 x i8] c"out\00"

declare %Range @-D-D-D_tII(%Int, %Int)

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

declare void @generate_mRPtI(%Range, void (%Int)*)

declare %Bool @-L_tII(%Int, %Int)

; Function Attrs: alwaysinline
define void @main.loop_thunk(%Int %x) #0 {
entry:
  %0 = load %Int** @a.globlstorage
  %1 = load %Int* %0
  %2 = call %Int @-A_tII(%Int %x, %Int %1), !stdlib.call.optim !0
  store %Int %2, %Int* %0
  %3 = load %Int* %0
  call void @print_tI(%Int %3), !stdlib.call.optim !0
  ret void
}

declare void @print_tI(%Int)

declare %String @String_topi64b(i8*, i64, i1)
>>>>>>> parent of 0bc95a6... Started working on LLVM wrapper

declare void @print_tString(%String)

declare %Int @-P_tII(%Int, %Int)

define void @generate_mHalfOpenRangePtI(%HalfOpenRange %self, void (%Int)* %loop_thunk) {
entry:
<<<<<<< HEAD
  %0 = call %String @String_topi64b(i8* getelementptr inbounds ([17 x i8]* @0, i32 0, i32 0), i64 17, i1 false), !stdlib.call.optim !0
  call void @print_tString(%String %0), !stdlib.call.optim !0
=======
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
  %1 = alloca %Int
  store %Int { i64 1 }, %Int* %1
  store %Int* %1, %Int** @a.globlstorage
  %2 = call %Range @-D-D-D_tII(%Int { i64 1 }, %Int { i64 10 }), !stdlib.call.optim !0
  call void @generate_mRPtI(%Range %2, void (%Int)* @main.loop_thunk)
  %3 = call %String @String_topi64b(i8* getelementptr inbounds ([4 x i8]* @0, i32 0, i32 0), i64 4, i1 true), !stdlib.call.optim !0
  call void @print_tString(%String %3), !stdlib.call.optim !0
  %4 = load %Int* %1
  call void @print_tI(%Int %4), !stdlib.call.optim !0
>>>>>>> parent of 0bc95a6... Started working on LLVM wrapper
  ret void
}

declare %String @String_topi64b(i8*, i64, i1)

!0 = !{!"stdlib.call.optim"}
