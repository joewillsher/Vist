; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define i64 @main() {
entry:
  tail call void @_print_S.i64({ i64 } { i64 1 })
  tail call void @_print_S.i64({ i64 } { i64 2 })
  tail call void @_print_S.i64({ i64 } { i64 3 })
  tail call void @_print_S.i64({ i64 } { i64 4 })
  tail call void @_print_S.i64({ i64 } { i64 5 })
  tail call void @_print_S.i64({ i64 } { i64 6 })
  tail call void @_print_S.i64({ i64 } { i64 7 })
  tail call void @_print_S.i64({ i64 } { i64 8 })
  tail call void @_print_S.i64({ i64 } { i64 9 })
  tail call void @_print_S.i64({ i64 } { i64 10 })
  tail call void @_print_S.i64({ i64 } { i64 11 })
  tail call void @_print_S.i64({ i64 } { i64 12 })
  tail call void @_print_S.i64({ i64 } { i64 13 })
  tail call void @_print_S.i64({ i64 } { i64 14 })
  tail call void @_print_S.i64({ i64 } { i64 15 })
  tail call void @_print_S.i64({ i64 } { i64 16 })
  tail call void @_print_S.i64({ i64 } { i64 17 })
  tail call void @_print_S.i64({ i64 } { i64 18 })
  tail call void @_print_S.i64({ i64 } { i64 19 })
  tail call void @_print_S.i64({ i64 } { i64 20 })
  ret i64 0
}

declare void @_print_S.i64({ i64 })
