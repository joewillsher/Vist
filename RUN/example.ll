; ModuleID = 'vist_module'

define i32 @main(i32) {
entry:
  %bar = call i64 @bar(i64 2)
  %a = alloca i64
  store i64 %bar, i64* %a
  %cmp_lt_res = icmp slt i64 %bar, 3
  %cmp_eq_res = icmp eq i64 %bar, 1
  %and_res = and i1 %cmp_lt_res, %cmp_eq_res
  br i1 %and_res, label %then0, label %cont0

cont0:                                            ; preds = %entry, %then0
  br label %else1

then0:                                            ; preds = %entry
  %b = alloca i64
  store i64 2, i64* %b
  br label %cont0

cont1:                                            ; preds = %else1
  ret i32 0

else1:                                            ; preds = %cont0
  %b1 = alloca i64
  store i64 3, i64* %b1
  br label %cont1
}

declare void @foo()

define i64 @bar(i64 %"$0") {
entry:
  ret i64 %"$0"
}
