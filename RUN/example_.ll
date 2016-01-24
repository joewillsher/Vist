; ModuleID = 'vist_module'

define i64 @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 1)
  %1 = call { i64 } @_Int_i64(i64 2)
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %0, { i64 } %1)
  %2 = alloca { i64 }
  store { i64 } %"+.res", { i64 }* %2
  %a = load { i64 }* %2
  call void @_print_S.i64({ i64 } %a)
  ret i64 0
}

declare { i64 } @_Int_i64(i64)

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

declare void @_print_S.i64({ i64 })
