; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int = type { i64 }
%String = type { i8*, %Int, %Int }

@0 = private unnamed_addr constant [6 x i8] c"memes\00"
@1 = private unnamed_addr constant [14 x i8] c"\F0\9F\98\8E\F0\9F\98\97memes\00"

declare void @print_tI(%Int)

declare void @print_tString(%String)

define void @main() {
entry:
  tail call void @print_tI(%Int { i64 1 }), !stdlib.call.optim !0
  %0 = tail call %String @String_topi64b(i8* getelementptr inbounds ([6 x i8]* @0, i64 0, i64 0), i64 6, i1 true), !stdlib.call.optim !0
  tail call void @print_tString(%String %0), !stdlib.call.optim !0
  %1 = tail call %String @String_topi64b(i8* getelementptr inbounds ([14 x i8]* @1, i64 0, i64 0), i64 14, i1 false), !stdlib.call.optim !0
  tail call void @print_tString(%String %1), !stdlib.call.optim !0
  ret void
}

define void @foo_tI(%Int %"$0") {
entry:
  tail call void @print_tI(%Int %"$0"), !stdlib.call.optim !0
  ret void
}

declare %String @String_topi64b(i8*, i64, i1)

!0 = !{!"stdlib.call.optim"}
