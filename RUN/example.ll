; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.st = type { %Int.st }
%Int.st = type { i64 }

; Function Attrs: nounwind readnone
define %Foo.st @Foo_Int(%Int.st %"$0") #0 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %.fca.0.0.insert = insertvalue %Foo.st undef, i64 %"$0.fca.0.extract", 0, 0
  ret %Foo.st %.fca.0.0.insert
}

; Function Attrs: nounwind
define %Int.st @Foo.foo_Int(%Foo.st* nocapture readonly %self, %Int.st %u) #1 {
entry:
  %0 = getelementptr inbounds %Foo.st* %self, i64 0, i32 0, i32 0
  %1 = load i64* %0, align 8
  %a.value = extractvalue %Int.st %u, 0
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %a.value, i64 %1)
  %mul_res.fca.1.extract = extractvalue { i64, i1 } %mul_res, 1
  br i1 %mul_res.fca.1.extract, label %inlined.-A_Int_Int.then.0.i, label %inlined.-A_Int_Int.condFail_b.exit

inlined.-A_Int_Int.then.0.i:                      ; preds = %entry
  tail call void @llvm.trap() #1
  unreachable

inlined.-A_Int_Int.condFail_b.exit:               ; preds = %entry
  %mul_res.fca.0.extract = extractvalue { i64, i1 } %mul_res, 0
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %mul_res.fca.0.extract, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: nounwind
define void @main() #1 {
entry:
  tail call void @-Uprint_i64(i64 1)
  ret void
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #0

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #2

; Function Attrs: noinline nounwind ssp uwtable
declare void @-Uprint_i64(i64) #3

attributes #0 = { nounwind readnone }
attributes #1 = { nounwind }
attributes #2 = { noreturn nounwind }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
