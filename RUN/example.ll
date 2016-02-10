; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bar.ty = type { %Int.ty }
%Int.ty = type { i64 }

define void @main() {
entry:
  %Bar.i = alloca %Bar.ty
  %0 = call %Int.ty @_Int_i64(i64 1), !stdlib.call.optim !0
  %Bar.a.ptr.i = getelementptr inbounds %Bar.ty* %Bar.i, i32 0, i32 0
  store %Int.ty %0, %Int.ty* %Bar.a.ptr.i
  %Bar1.i = load %Bar.ty* %Bar.i
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
