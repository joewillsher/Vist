; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.st = type { %Int.st }
%Int.st = type { i64 }
%Bar.st = type { %TestC.ex }
%TestC.ex = type { [1 x i32], i8* }

; Function Attrs: nounwind
define void @main() #0 {
entry:
  tail call void @"_$print_i64"(i64 1)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Foo.st @_Foo_Int(%Int.st %"$0") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %Foo1.fca.0.0.insert = insertvalue %Foo.st undef, i64 %"$0.fca.0.extract", 0, 0
  ret %Foo.st %Foo1.fca.0.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bar.st @_Bar_TestC(%TestC.ex %"$0") #1 {
entry:
  %"$0.fca.0.0.extract" = extractvalue %TestC.ex %"$0", 0, 0
  %"$0.fca.1.extract" = extractvalue %TestC.ex %"$0", 1
  %Bar3.fca.0.0.0.insert = insertvalue %Bar.st undef, i32 %"$0.fca.0.0.extract", 0, 0, 0
  %Bar3.fca.0.1.insert = insertvalue %Bar.st %Bar3.fca.0.0.0.insert, i8* %"$0.fca.1.extract", 0, 1
  ret %Bar.st %Bar3.fca.0.1.insert
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @"_$print_i64"(i64) #2

attributes #0 = { nounwind }
attributes #1 = { alwaysinline nounwind readnone }
attributes #2 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
