; ModuleID = 'example_.ll'

define i64 @main() {
entry:
  %0 = tail call { i64 } @_Int_i64(i64 1), !trivialInitialiser !0
  %1 = tail call { i64 } @_Int_i64(i64 2), !trivialInitialiser !0
  %"+.res" = tail call { i64 } @"_+_S.i64_S.i64"({ i64 } %0, { i64 } %1)
  tail call void @_print_S.i64({ i64 } %"+.res")
  ret i64 0
}

declare { i64 } @_Int_i64(i64)

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

declare void @_print_S.i64({ i64 })

!0 = !{!"trivialInitialiser"}
