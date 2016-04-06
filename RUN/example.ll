; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int = type { i64 }
%String = type { i8*, %Int, %Int }
%Bool = type { i1 }

@0 = private unnamed_addr constant [9 x i8] c"aaaa\F0\9F\A4\94\00"

declare void @print_tI(%Int)

declare void @print_tString(%String)

declare %String @String_topi64b(i8*, i64, i1)

declare void @print_tB(%Bool)

declare %Bool @isUTF8Encoded_mString(%String*)

define void @main() {
entry:
  %0 = tail call %String @String_topi64b(i8* getelementptr inbounds ([9 x i8]* @0, i64 0, i64 0), i64 9, i1 false), !stdlib.call.optim !0
  %1 = extractvalue %String %0, 1
  tail call void @print_tI(%Int %1), !stdlib.call.optim !0
  %2 = alloca %String, align 8
  %.fca.0.extract1 = extractvalue %String %0, 0
  %.fca.0.gep2 = getelementptr inbounds %String* %2, i64 0, i32 0
  store i8* %.fca.0.extract1, i8** %.fca.0.gep2, align 8
  %.fca.1.0.extract3 = extractvalue %String %0, 1, 0
  %.fca.1.0.gep4 = getelementptr inbounds %String* %2, i64 0, i32 1, i32 0
  store i64 %.fca.1.0.extract3, i64* %.fca.1.0.gep4, align 8
  %.fca.2.0.extract5 = extractvalue %String %0, 2, 0
  %.fca.2.0.gep6 = getelementptr inbounds %String* %2, i64 0, i32 2, i32 0
  store i64 %.fca.2.0.extract5, i64* %.fca.2.0.gep6, align 8
  %3 = call %Int @bufferCapacity_mString(%String* %2)
  call void @print_tI(%Int %3), !stdlib.call.optim !0
  %4 = alloca %String, align 8
  %.fca.0.gep = getelementptr inbounds %String* %4, i64 0, i32 0
  store i8* %.fca.0.extract1, i8** %.fca.0.gep, align 8
  %.fca.1.0.gep = getelementptr inbounds %String* %4, i64 0, i32 1, i32 0
  store i64 %.fca.1.0.extract3, i64* %.fca.1.0.gep, align 8
  %.fca.2.0.gep = getelementptr inbounds %String* %4, i64 0, i32 2, i32 0
  store i64 %.fca.2.0.extract5, i64* %.fca.2.0.gep, align 8
  %5 = call %Bool @isUTF8Encoded_mString(%String* %4)
  call void @print_tB(%Bool %5), !stdlib.call.optim !0
  call void @print_tString(%String %0), !stdlib.call.optim !0
  ret void
}

declare %Int @bufferCapacity_mString(%String*)

!0 = !{!"stdlib.call.optim"}
