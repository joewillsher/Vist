; ModuleID = 'example'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%String = type { i8*, %Int, %Int }
%Int = type { i64 }

@0 = private unnamed_addr constant [17 x i8] c"\F0\9F\A4\94\F0\9F\A4\94\F0\9F\A4\94\F0\9F\A4\94\00"

declare void @print_tString(%String)

define void @main() {
entry:
  %0 = call %String @String_topi64b(i8* getelementptr inbounds ([17 x i8]* @0, i32 0, i32 0), i64 17, i1 false), !stdlib.call.optim !0
  call void @print_tString(%String %0), !stdlib.call.optim !0
  ret void
}

declare %String @String_topi64b(i8*, i64, i1)

!0 = !{!"stdlib.call.optim"}
