; ModuleID = 'vist_module'

declare void @_Z5printv()

define i32 @main() {
entry:
  %a = alloca i64
  store i64 2, i64* %a
  call void @foo()
  %0 = call i64 @bar()
  %b = alloca i64
  store i64 %0, i64* %b
  call void @_Z5printv()
  ret i32 0
}

define void @foo() {
entry:
  ret void
}

define i64 @bar() {
entry:
  ret i64 1
}
