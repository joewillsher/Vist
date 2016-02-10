; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.ty = type { i64 }
%Bar.ty = type { %Int.ty }

define void @main() {
entry:
  %0 = call %Int.ty @_Int_i64(i64 1), !stdlib.call.optim !0
  %Bar_res = call %Bar.ty @_Bar_S.i64(%Int.ty %0)
  %bar = alloca %Bar.ty
  store %Bar.ty %Bar_res, %Bar.ty* %bar
  ret void
}

; Function Attrs: alwaysinline
define %Bar.ty @_Bar_S.i64(%Int.ty %"$0") #0 {
entry:
  %Bar = alloca %Bar.ty
  %Bar.a.ptr = getelementptr inbounds %Bar.ty* %Bar, i32 0, i32 0
  store %Int.ty %"$0", %Int.ty* %Bar.a.ptr
  %Bar1 = load %Bar.ty* %Bar
  ret %Bar.ty %Bar1
}

declare %Int.ty @_Int_i64(i64)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
