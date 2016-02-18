; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Foo.st = type { %Int.st }
%Bar.st = type { %TestC.ex }
%TestC.ex = type { [1 x i32], i8* }

define void @main() {
entry:
  tail call void @-Uprint_i64(i64 1)
  %0 = tail call %Int.st @Int_i64(i64 1)
  %oldret1.i = extractvalue %Int.st %0, 0
  tail call void @-Uprint_i64(i64 %oldret1.i)
  %factorial_res2 = tail call fastcc i64 @factorial_Int(%Int.st { i64 10 })
  tail call void @-Uprint_i64(i64 %factorial_res2)
  %factorial_res3 = tail call fastcc i64 @factorial_Int(%Int.st { i64 4 })
  tail call void @-Uprint_i64(i64 %factorial_res3)
  %factorial_res5 = tail call fastcc i64 @factorial_Int(%Int.st { i64 4 })
  tail call void @-Uprint_i64(i64 %factorial_res5)
  %factorial_res7 = tail call fastcc i64 @factorial_Int(%Int.st { i64 3 })
  %oldret135 = insertvalue %Int.st undef, i64 %factorial_res7, 0
  %factorial_res8 = tail call fastcc i64 @factorial_Int(%Int.st %oldret135)
  tail call void @-Uprint_i64(i64 %factorial_res8)
  tail call void @-Uprint_i64(i64 41) #4
  tail call void @-Uprint_i64(i64 2)
  tail call void @-Uprint_i64(i64 100)
  tail call void @-Uprint_i64(i64 11)
  tail call void @-Uprint_i64(i64 20)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Foo.st @Foo_Int(%Int.st %"$0") #0 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %Foo1.fca.0.0.insert = insertvalue %Foo.st undef, i64 %"$0.fca.0.extract", 0, 0
  ret %Foo.st %Foo1.fca.0.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bar.st @Bar_TestC(%TestC.ex %"$0") #0 {
entry:
  %"$0.fca.0.0.extract" = extractvalue %TestC.ex %"$0", 0, 0
  %"$0.fca.1.extract" = extractvalue %TestC.ex %"$0", 1
  %Bar3.fca.0.0.0.insert = insertvalue %Bar.st undef, i32 %"$0.fca.0.0.extract", 0, 0, 0
  %Bar3.fca.0.1.insert = insertvalue %Bar.st %Bar3.fca.0.0.0.insert, i8* %"$0.fca.1.extract", 0, 1
  ret %Bar.st %Bar3.fca.0.1.insert
}

declare %Int.st @Int_i64(i64)

define internal fastcc i64 @factorial_Int(%Int.st %a) {
entry:
  %value = extractvalue %Int.st %a, 0
  %cmp_lte_res = icmp slt i64 %value, 2
  %0 = tail call %Int.st @Int_i64(i64 1)
  %oldret1 = extractvalue %Int.st %0, 0
  br i1 %cmp_lte_res, label %then.0, label %else.1

then.0:                                           ; preds = %entry
  ret i64 %oldret1

else.1:                                           ; preds = %entry
  %sub_res = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value, i64 %oldret1)
  %sub_res.fca.1.extract = extractvalue { i64, i1 } %sub_res, 1
  br i1 %sub_res.fca.1.extract, label %inlined.-M_Int_Int.then.0.i, label %inlined.-M_Int_Int.condFail_b.exit

inlined.-M_Int_Int.then.0.i:                      ; preds = %else.1
  tail call void @llvm.trap() #4
  unreachable

inlined.-M_Int_Int.condFail_b.exit:               ; preds = %else.1
  %sub_res.fca.0.extract = extractvalue { i64, i1 } %sub_res, 0
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %sub_res.fca.0.extract, 0
  %factorial_res = tail call fastcc i64 @factorial_Int(%Int.st %Int1.i.fca.0.insert)
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %value, i64 %factorial_res)
  %mul_res.fca.1.extract = extractvalue { i64, i1 } %mul_res, 1
  br i1 %mul_res.fca.1.extract, label %inlined.-A_Int_Int.then.0.i, label %inlined.-A_Int_Int.condFail_b.exit

inlined.-A_Int_Int.then.0.i:                      ; preds = %inlined.-M_Int_Int.condFail_b.exit
  tail call void @llvm.trap() #4
  unreachable

inlined.-A_Int_Int.condFail_b.exit:               ; preds = %inlined.-M_Int_Int.condFail_b.exit
  %mul_res.fca.0.extract = extractvalue { i64, i1 } %mul_res, 0
  ret i64 %mul_res.fca.0.extract
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @-Uprint_i64(i64) #1

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #2

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #3

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #3

attributes #0 = { alwaysinline nounwind readnone }
attributes #1 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind }
attributes #3 = { nounwind readnone }
attributes #4 = { nounwind }
