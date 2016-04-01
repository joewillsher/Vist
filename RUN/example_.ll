; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%String = type { i8*, i64 }
%Int = type { i64 }

@0 = private unnamed_addr constant [5 x i8] c"meme\00"

declare %String @String_topi64(i8*, i64)

declare %Int @-P_tIntInt(%Int, %Int)

define void @main() {
entry:
  %0 = call %Int @-P_tIntInt(%Int { i64 1 }, %Int { i64 1 }), !stdlib.call.optim !0
  %1 = call %String @String_topi64(i8* getelementptr inbounds ([5 x i8]* @0, i32 0, i32 0), i64 5), !stdlib.call.optim !0
  %u = alloca %String
  store %String %1, %String* %u
  call void @print_tString(%String %1), !stdlib.call.optim !0
  ret void
}

declare void @print_tString(%String)

!0 = !{!"stdlib.call.optim"}
