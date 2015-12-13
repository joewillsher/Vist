; ModuleID = 'vist_module'

declare void @print()

define i32 @main() {
entry:
  %a = alloca i64
  store i64 2, i64* %a
  call void @foo()
  %0 = call i64 @bar()
  %b = alloca i64
  store i64 %0, i64* %b
  call void @print()
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
