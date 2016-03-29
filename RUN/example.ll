; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bar.st = type { %Int.st, %Int.st, %Bool.st }
%Int.st = type { i64 }
%Bool.st = type { i1 }
%Foo.ex = type { [2 x i32], [0 x i8*], i8* }

; Function Attrs: nounwind readnone
define %Bar.st @Bar_Int_Int_Bool(%Int.st %"$0", %Int.st %"$1", %Bool.st %"$2") #0 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int.st %"$1", 0
  %"$2.fca.0.extract" = extractvalue %Bool.st %"$2", 0
  %.fca.0.0.insert = insertvalue %Bar.st undef, i64 %"$0.fca.0.extract", 0, 0
  %.fca.1.0.insert = insertvalue %Bar.st %.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  %.fca.2.0.insert = insertvalue %Bar.st %.fca.1.0.insert, i1 %"$2.fca.0.extract", 2, 0
  ret %Bar.st %.fca.2.0.insert
}

; Function Attrs: nounwind readonly
define %Bool.st @unbox2_Foo(%Foo.ex %box) #1 {
entry:
  %box.fca.0.1.extract = extractvalue %Foo.ex %box, 0, 1
  %box.fca.2.extract = extractvalue %Foo.ex %box, 2
  %0 = sext i32 %box.fca.0.1.extract to i64
  %1 = getelementptr i8* %box.fca.2.extract, i64 %0
  %nil.ptr = bitcast i8* %1 to %Bool.st*
  %2 = load %Bool.st* %nil.ptr, align 1
  ret %Bool.st %2
}

; Function Attrs: nounwind
define void @main() #2 {
entry:
  tail call void @vist-Uprint_i64(i64 2)
  tail call void @vist-Uprint_b(i1 false)
  ret void
}

; Function Attrs: nounwind readonly
define %Int.st @unbox_Foo(%Foo.ex %box) #1 {
entry:
  %box.fca.0.0.extract = extractvalue %Foo.ex %box, 0, 0
  %box.fca.2.extract = extractvalue %Foo.ex %box, 2
  %0 = sext i32 %box.fca.0.0.extract to i64
  %1 = getelementptr i8* %box.fca.2.extract, i64 %0
  %nil.ptr = bitcast i8* %1 to %Int.st*
  %2 = load %Int.st* %nil.ptr, align 8
  ret %Int.st %2
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @vist-Uprint_i64(i64) #3

; Function Attrs: noinline nounwind ssp uwtable
declare void @vist-Uprint_b(i1 zeroext) #3

attributes #0 = { nounwind readnone }
attributes #1 = { nounwind readonly }
attributes #2 = { nounwind }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
