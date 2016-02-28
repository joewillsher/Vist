; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.st = type { %Foo.T.gen }
%Foo.T.gen = type { [0 x i32], i8* }

; Function Attrs: nounwind readnone
define void @main() #0 {
entry:
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Foo.st @Foo_T(%Foo.T.gen %"$0") #1 {
entry:
  %"$0.fca.1.extract" = extractvalue %Foo.T.gen %"$0", 1
  %Foo1.fca.0.1.insert = insertvalue %Foo.st undef, i8* %"$0.fca.1.extract", 0, 1
  ret %Foo.st %Foo1.fca.0.1.insert
}

attributes #0 = { nounwind readnone }
attributes #1 = { alwaysinline nounwind readnone }
