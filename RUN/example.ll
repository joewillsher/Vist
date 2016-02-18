; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%I.st = type { %Int.st }
%Int.st = type { i64 }
%A.st = type { %I.st }
%B.st = type { %X.ex }
%X.ex = type { [1 x i32], i8* }

; Function Attrs: nounwind
define void @main() #0 {
entry:
  tail call void @-Uprint_i64(i64 2)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %I.st @I_Int(%Int.st %"$0") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %I1.fca.0.0.insert = insertvalue %I.st undef, i64 %"$0.fca.0.extract", 0, 0
  ret %I.st %I1.fca.0.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %A.st @A_I(%I.st %"$0") #1 {
entry:
  %"$0.fca.0.0.extract" = extractvalue %I.st %"$0", 0, 0
  %A1.fca.0.0.0.insert = insertvalue %A.st undef, i64 %"$0.fca.0.0.extract", 0, 0, 0
  ret %A.st %A1.fca.0.0.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %B.st @B_X(%X.ex %"$0") #1 {
entry:
  %"$0.fca.0.0.extract" = extractvalue %X.ex %"$0", 0, 0
  %"$0.fca.1.extract" = extractvalue %X.ex %"$0", 1
  %B2.fca.0.0.0.insert = insertvalue %B.st undef, i32 %"$0.fca.0.0.extract", 0, 0, 0
  %B2.fca.0.1.insert = insertvalue %B.st %B2.fca.0.0.0.insert, i8* %"$0.fca.1.extract", 0, 1
  ret %B.st %B2.fca.0.1.insert
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @-Uprint_i64(i64) #2

attributes #0 = { nounwind }
attributes #1 = { alwaysinline nounwind readnone }
attributes #2 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
