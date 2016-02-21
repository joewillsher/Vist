; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bar.st = type { %Bool.st, %Int.st, %Int.st }
%Bool.st = type { i1 }
%Int.st = type { i64 }

; Function Attrs: nounwind
define void @main() #0 {
entry:
  tail call void @-Uprint_i64(i64 6)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Bar.st @Bar_Bool_Int_Int(%Bool.st %"$0", %Int.st %"$1", %Int.st %"$2") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue %Bool.st %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int.st %"$1", 0
  %"$2.fca.0.extract" = extractvalue %Int.st %"$2", 0
  %Bar1.fca.0.0.insert = insertvalue %Bar.st undef, i1 %"$0.fca.0.extract", 0, 0
  %Bar1.fca.1.0.insert = insertvalue %Bar.st %Bar1.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  %Bar1.fca.2.0.insert = insertvalue %Bar.st %Bar1.fca.1.0.insert, i64 %"$2.fca.0.extract", 2, 0
  ret %Bar.st %Bar1.fca.2.0.insert
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @-Uprint_i64(i64) #2

attributes #0 = { nounwind }
attributes #1 = { alwaysinline nounwind readnone }
attributes #2 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
