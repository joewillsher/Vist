; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [10 x i8] c"sup meme\0A\00", align 1
@.str1 = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1

; Function Attrs: ssp uwtable
define void @print() #0 {
  %1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([10 x i8]* @.str, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: ssp uwtable
define void @printNum(i64 %i) #0 {
  %1 = alloca i64, align 8
  store i64 %i, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i32 0, i32 0), i64 %2)
  ret void
}

define i32 @main() {
entry:
  %0 = call i64 @bar()
  %c = alloca i64
  store i64 %0, i64* %c
  call void @printNum(i64 %0)
  ret i32 0
}

define i64 @foo(i64 %a) {
entry:
  ret i64 %a
}

define i64 @bar() {
entry:
  br i1 false, label %then0, label %cont0

cont0:                                            ; preds = %entry
  %0 = call i64 @foo(i64 1)
  %cmp_lt_res = icmp slt i64 %0, 0
  br i1 %cmp_lt_res, label %then1, label %cont1

then0:                                            ; preds = %entry
  ret i64 1

cont1:                                            ; preds = %cont0
  br label %else2

then1:                                            ; preds = %cont0
  ret i64 0

else2:                                            ; preds = %cont1
  ret i64 2
}

attributes #0 = { ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.0 (clang-700.1.76)"}
!1 = !{i32 1, !"PIC Level", i32 2}
