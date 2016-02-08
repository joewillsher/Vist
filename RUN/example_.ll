; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  ret void
}

; Function Attrs: alwaysinline
define { { i64 } } @_TwoType_S.i64({ i64 } %"$0") #0 {
entry:
  %TwoType = alloca { { i64 } }
  %TwoType.i.ptr = getelementptr inbounds { { i64 } }* %TwoType, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %TwoType.i.ptr
  %TwoType1 = load { { i64 } }* %TwoType
  ret { { i64 } } %TwoType1
}

attributes #0 = { alwaysinline }
