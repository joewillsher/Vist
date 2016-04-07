; ModuleID = 'example'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int = type { i64 }
%String = type { i8*, %Int, %Int }
%Bool = type { i1 }

@0 = private unnamed_addr constant [15 x i8] c"\F0\9F\94\A5 test \F0\9F\94\A5\00"

declare void @print_tI(%Int)

declare void @print_tString(%String)

declare %String @String_topi64b(i8*, i64, i1)

declare void @print_tB(%Bool)

declare %Bool @isUTF8Encoded_mString(%String*)

define void @main() {
entry:
  %0 = call %String @String_topi64b(i8* getelementptr inbounds ([15 x i8]* @0, i32 0, i32 0), i64 15, i1 false), !stdlib.call.optim !0
  %b = alloca %String
  store %String %0, %String* %b
  %1 = extractvalue %String %0, 1
  call void @print_tI(%Int %1), !stdlib.call.optim !0
  %2 = alloca %String
  store %String %0, %String* %2
  %3 = call %Int @bufferCapacity_mString(%String* %2)
  call void @print_tI(%Int %3), !stdlib.call.optim !0
  %4 = alloca %String
  store %String %0, %String* %4
  %5 = call %Bool @isUTF8Encoded_mString(%String* %4)
  call void @print_tB(%Bool %5), !stdlib.call.optim !0
  call void @print_tString(%String %0), !stdlib.call.optim !0
  ret void
}

declare %Int @bufferCapacity_mString(%String*)

!0 = !{!"stdlib.call.optim"}
