; ModuleID = 'llvm-link'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [9 x i8] c"sup meme\00", align 1

; Function Attrs: ssp uwtable
define void @print() #0 {
  %1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([9 x i8]* @.str, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*, ...) #1

define i32 @main() {
entry:
  %0 = call i64 @bar()
  %b = alloca i64
  store i64 %0, i64* %b
  %cmp_lt_res = icmp slt i64 %0, 0
  br i1 %cmp_lt_res, label %then0, label %cont0

cont0:                                            ; preds = %then0, %entry
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

attributes #0 = { ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.0 (clang-700.1.76)"}
!1 = !{i32 1, !"PIC Level", i32 2}
