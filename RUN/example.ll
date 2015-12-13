; ModuleID = 'vist_module'

declare void @print()

define i32 @main() {
entry:
  %0 = call i64 @bar()
  %b = alloca i64
  store i64 %0, i64* %b
  %cmp_lt_res = icmp slt i64 %0, 0
  br i1 %cmp_lt_res, label %then0, label %cont0

cont0:                                            ; preds = %entry, %then0
  br label %else1

then0:                                            ; preds = %entry
  call void @print()
  br label %cont0

cont1:                                            ; preds = %else1
  ret i32 0

else1:                                            ; preds = %cont0
  call void @foo()
  br label %cont1
}

define void @foo() {
entry:
  ret void
}

define i64 @bar() {
entry:
  ret i64 1
}
