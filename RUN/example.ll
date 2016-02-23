; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bar.st = type { %Bool.st, %Int.st, %Int.st }
%Bool.st = type { i1 }
%Int.st = type { i64 }
%Eq.ex = type { [2 x i32], [1 x i8*], i8* }
%Baz.st = type { %Int.st, %Int.st }

define void @main() {
foo_Eq_Int.exit131:
  tail call void @-Uprint_i64(i64 17)
  %0 = alloca %Bar.st, align 8
  %1 = alloca %Eq.ex, align 8
  %.prop_metadata5 = getelementptr inbounds %Eq.ex* %1, i64 0, i32 0
  %.method_metadata6 = getelementptr inbounds %Eq.ex* %1, i64 0, i32 1
  %.opaque7 = getelementptr inbounds %Eq.ex* %1, i64 0, i32 2
  %metadata8 = alloca [2 x i32], align 4
  %2 = getelementptr inbounds [2 x i32]* %metadata8, i64 0, i64 0
  store i32 16, i32* %2, align 4
  %el.110 = getelementptr [2 x i32]* %metadata8, i64 0, i64 1
  store i32 8, i32* %el.110, align 4
  %3 = load [2 x i32]* %metadata8, align 4
  store [2 x i32] %3, [2 x i32]* %.prop_metadata5, align 8
  %metadata11 = alloca [1 x i8*], align 8
  %4 = getelementptr inbounds [1 x i8*]* %metadata11, i64 0, i64 0
  store i8* bitcast (%Int.st (%Bar.st*)* @Bar.sum_ to i8*), i8** %4, align 8
  %5 = load [1 x i8*]* %metadata11, align 8
  store [1 x i8*] %5, [1 x i8*]* %.method_metadata6, align 8
  store %Bar.st { %Bool.st { i1 true }, %Int.st { i64 11 }, %Int.st { i64 4 } }, %Bar.st* %0, align 8
  %6 = bitcast i8** %.opaque7 to %Bar.st**
  store %Bar.st* %0, %Bar.st** %6, align 8
  %7 = load %Eq.ex* %1, align 8
  %.fca.0.0.extract23 = extractvalue %Eq.ex %7, 0, 0
  %.fca.0.1.extract24 = extractvalue %Eq.ex %7, 0, 1
  %.fca.2.extract26 = extractvalue %Eq.ex %7, 2
  %8 = sext i32 %.fca.0.0.extract23 to i64
  %9 = getelementptr i8* %.fca.2.extract26, i64 %8
  %10 = bitcast i8* %9 to i64*
  %11 = load i64* %10, align 8
  %12 = sext i32 %.fca.0.1.extract24 to i64
  %13 = getelementptr i8* %.fca.2.extract26, i64 %12
  %14 = bitcast i8* %13 to i64*
  %15 = load i64* %14, align 8
  %mul_res.i = call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %15, i64 2) #1
  %mul_res.fca.1.extract.i = extractvalue { i64, i1 } %mul_res.i, 1
  br i1 %mul_res.fca.1.extract.i, label %inlined.-A_Int_Int.then.0.i.i, label %inlined.-A_Int_Int.condFail_b.exit.i

inlined.-A_Int_Int.then.0.i.i:                    ; preds = %foo_Eq_Int.exit131
  call void @llvm.trap() #1
  unreachable

inlined.-A_Int_Int.condFail_b.exit.i:             ; preds = %foo_Eq_Int.exit131
  %mul_res.fca.0.extract.i = extractvalue { i64, i1 } %mul_res.i, 0
  %add_res.i116 = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %mul_res.fca.0.extract.i, i64 2) #1
  %add_res.fca.1.extract.i117 = extractvalue { i64, i1 } %add_res.i116, 1
  br i1 %add_res.fca.1.extract.i117, label %inlined.-P_Int_Int.then.0.i.i118, label %inlined.-P_Int_Int.condFail_b.exit.i

inlined.-P_Int_Int.then.0.i.i118:                 ; preds = %inlined.-A_Int_Int.condFail_b.exit.i
  call void @llvm.trap() #1
  unreachable

inlined.-P_Int_Int.condFail_b.exit.i:             ; preds = %inlined.-A_Int_Int.condFail_b.exit.i
  %add_res.fca.0.extract.i119 = extractvalue { i64, i1 } %add_res.i116, 0
  %add_res17.i = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %11, i64 %add_res.fca.0.extract.i119) #1
  %add_res.fca.1.extract19.i = extractvalue { i64, i1 } %add_res17.i, 1
  br i1 %add_res.fca.1.extract19.i, label %inlined.-P_Int_Int.then.0.i20.i, label %foo2_Eq_Int.exit

inlined.-P_Int_Int.then.0.i20.i:                  ; preds = %inlined.-P_Int_Int.condFail_b.exit.i
  call void @llvm.trap() #1
  unreachable

foo2_Eq_Int.exit:                                 ; preds = %inlined.-P_Int_Int.condFail_b.exit.i
  %add_res.fca.0.extract23.i = extractvalue { i64, i1 } %add_res17.i, 0
  tail call void @-Uprint_i64(i64 %add_res.fca.0.extract23.i)
  %16 = alloca %Baz.st, align 8
  %17 = alloca %Eq.ex, align 8
  %.prop_metadata14 = getelementptr inbounds %Eq.ex* %17, i64 0, i32 0
  %.method_metadata15 = getelementptr inbounds %Eq.ex* %17, i64 0, i32 1
  %.opaque16 = getelementptr inbounds %Eq.ex* %17, i64 0, i32 2
  %metadata17 = alloca [2 x i32], align 4
  %18 = getelementptr inbounds [2 x i32]* %metadata17, i64 0, i64 0
  store i32 0, i32* %18, align 4
  %el.119 = getelementptr [2 x i32]* %metadata17, i64 0, i64 1
  store i32 8, i32* %el.119, align 4
  %19 = load [2 x i32]* %metadata17, align 4
  store [2 x i32] %19, [2 x i32]* %.prop_metadata14, align 8
  %metadata20 = alloca [1 x i8*], align 8
  %20 = getelementptr inbounds [1 x i8*]* %metadata20, i64 0, i64 0
  store i8* bitcast (%Int.st (%Baz.st*)* @Baz.sum_ to i8*), i8** %20, align 8
  %21 = load [1 x i8*]* %metadata20, align 8
  store [1 x i8*] %21, [1 x i8*]* %.method_metadata15, align 8
  store %Baz.st { %Int.st { i64 2 }, %Int.st { i64 3 } }, %Baz.st* %16, align 8
  %22 = bitcast i8** %.opaque16 to %Baz.st**
  store %Baz.st* %16, %Baz.st** %22, align 8
  %23 = load %Eq.ex* %17, align 8
  %.fca.1.0.extract = extractvalue %Eq.ex %23, 1, 0
  %.fca.2.extract = extractvalue %Eq.ex %23, 2
  %24 = bitcast i8* %.fca.1.0.extract to %Int.st (i8*)*
  %sum.res.i = call %Int.st %24(i8* %.fca.2.extract)
  %value.i = extractvalue %Int.st %sum.res.i, 0
  %add_res.i = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %value.i, i64 2)
  %add_res.fca.1.extract.i = extractvalue { i64, i1 } %add_res.i, 1
  br i1 %add_res.fca.1.extract.i, label %inlined.-P_Int_Int.then.0.i.i, label %foo_Eq_Int.exit

inlined.-P_Int_Int.then.0.i.i:                    ; preds = %foo2_Eq_Int.exit
  call void @llvm.trap() #1
  unreachable

foo_Eq_Int.exit:                                  ; preds = %foo2_Eq_Int.exit
  %add_res.fca.0.extract.i = extractvalue { i64, i1 } %add_res.i, 0
  tail call void @-Uprint_i64(i64 %add_res.fca.0.extract.i)
  tail call void @-Uprint_i64(i64 4)
  tail call void @-Uprint_i64(i64 1)
  tail call void @-Uprint_i64(i64 4)
  tail call void @-Uprint_i64(i64 7)
  tail call void @-Uprint_i64(i64 6)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Bar.st @Bar_Bool_Int_Int(%Bool.st %"$0", %Int.st %"$1", %Int.st %"$2") #0 {
entry:
  %"$0.fca.0.extract" = extractvalue %Bool.st %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int.st %"$1", 0
  %"$2.fca.0.extract" = extractvalue %Int.st %"$2", 0
  %Bar1.fca.0.0.insert = insertvalue %Bar.st undef, i1 %"$0.fca.0.extract", 0, 0
  %Bar1.fca.1.0.insert = insertvalue %Bar.st %Bar1.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  %Bar1.fca.2.0.insert = insertvalue %Bar.st %Bar1.fca.1.0.insert, i64 %"$2.fca.0.extract", 2, 0
  ret %Bar.st %Bar1.fca.2.0.insert
}

; Function Attrs: nounwind
define internal %Int.st @Bar.sum_(%Bar.st* nocapture readonly %self) #1 {
entry:
  %0 = getelementptr inbounds %Bar.st* %self, i64 0, i32 2, i32 0
  %1 = load i64* %0, align 8
  %2 = getelementptr inbounds %Bar.st* %self, i64 0, i32 1, i32 0
  %3 = load i64* %2, align 8
  %add_res = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %1, i64 %3)
  %add_res.fca.1.extract = extractvalue { i64, i1 } %add_res, 1
  br i1 %add_res.fca.1.extract, label %inlined.-P_Int_Int.then.0.i, label %inlined.-P_Int_Int.condFail_b.exit

inlined.-P_Int_Int.then.0.i:                      ; preds = %entry
  tail call void @llvm.trap() #1
  unreachable

inlined.-P_Int_Int.condFail_b.exit:               ; preds = %entry
  %add_res.fca.0.extract = extractvalue { i64, i1 } %add_res, 0
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %add_res.fca.0.extract, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Baz.st @Baz_Int_Int(%Int.st %"$0", %Int.st %"$1") #0 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int.st %"$1", 0
  %Baz1.fca.0.0.insert = insertvalue %Baz.st undef, i64 %"$0.fca.0.extract", 0, 0
  %Baz1.fca.1.0.insert = insertvalue %Baz.st %Baz1.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret %Baz.st %Baz1.fca.1.0.insert
}

; Function Attrs: nounwind readnone
define internal %Int.st @Baz.sum_(%Baz.st* nocapture readnone %self) #2 {
entry:
  ret %Int.st { i64 1 }
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @-Uprint_i64(i64) #3

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #2

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #4

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #2

attributes #0 = { alwaysinline nounwind readnone }
attributes #1 = { nounwind }
attributes #2 = { nounwind readnone }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { noreturn nounwind }
