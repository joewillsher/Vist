; ModuleID = 'example'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Gen = type { %Int }
%Int = type { i64 }

declare void @generate(%Gen*, void (%Int)*)

define %Gen @Gen_tI(%Int %"$0") {
entry:
  %self = alloca %Gen
  %num = getelementptr inbounds %Gen* %self, i32 0, i32 0
  store %Int %"$0", %Int* %num
  %0 = load %Gen* %self
  ret %Gen %0
}

define void @generate_mGenPtI(%Gen* %self, void (%Int)* %loop_thunk) {
entry:
  %num = getelementptr inbounds %Gen* %self, i32 0, i32 0
  %0 = load %Int* %num
  call void %loop_thunk(%Int %0)
  ret void
}

define void @loop_thunk(%Int %a) {
entry:
  call void @print_tI(%Int %a), !stdlib.call.optim !0
  ret void
}

define void @main() {
entry:
  %0 = call %Gen @Gen_tI(%Int { i64 1 })
  %gen = alloca %Gen
  store %Gen %0, %Gen* %gen
  %1 = alloca %Gen
  store %Gen %0, %Gen* %1
  call void @generate_mGenPtI(%Gen* %1, void (%Int)* @loop_thunk)
  ret void
}

declare void @print_tI(%Int)

!0 = !{!"stdlib.call.optim"}
