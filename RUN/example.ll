; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Eq.ex = type { [2 x i32], [1 x i8*], i8* }
%Int = type { i64 }
%Bar = type { %Bool, %Int, %Int }
%Bool = type { i1 }
%Baz = type { %Int, %Int }

define %Int @foo_tEqInt(%Eq.ex %a, %Int %b) {
entry:
  %a.fca.1.0.extract = extractvalue %Eq.ex %a, 1, 0
  %a.fca.2.extract = extractvalue %Eq.ex %a, 2
  %0 = bitcast i8* %a.fca.1.0.extract to %Int (i8*)*
  %1 = tail call %Int %0(i8* %a.fca.2.extract)
  %2 = extractvalue %Int %1, 0
  %3 = extractvalue %Int %b, 0
  %4 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %2, i64 %3)
  %5 = extractvalue { i64, i1 } %4, 1
  br i1 %5, label %"i.-P_tIntInt.+.trap", label %i.-P_tIntInt.entry.cont

i.-P_tIntInt.entry.cont:                          ; preds = %entry
  %6 = extractvalue { i64, i1 } %4, 0
  %.fca.0.insert = insertvalue %Int undef, i64 %6, 0
  ret %Int %.fca.0.insert

"i.-P_tIntInt.+.trap":                            ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: nounwind
define %Int @foo2_tEqInt(%Eq.ex %a, %Int %b) #0 {
entry:
  %a.fca.0.0.extract1 = extractvalue %Eq.ex %a, 0, 0
  %a.fca.2.extract4 = extractvalue %Eq.ex %a, 2
  %0 = sext i32 %a.fca.0.0.extract1 to i64
  %1 = getelementptr i8* %a.fca.2.extract4, i64 %0
  %2 = bitcast i8* %1 to i64*
  %3 = load i64* %2, align 8
  %a.fca.0.1.extract = extractvalue %Eq.ex %a, 0, 1
  %4 = sext i32 %a.fca.0.1.extract to i64
  %5 = getelementptr i8* %a.fca.2.extract4, i64 %4
  %6 = bitcast i8* %5 to i64*
  %7 = load i64* %6, align 8
  %8 = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %7, i64 2)
  %9 = extractvalue { i64, i1 } %8, 1
  br i1 %9, label %"i.-A_tIntInt.*.trap", label %i.-A_tIntInt.entry.cont

i.-A_tIntInt.entry.cont:                          ; preds = %entry
  %10 = extractvalue { i64, i1 } %8, 0
  %11 = extractvalue %Int %b, 0
  %12 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %10, i64 %11)
  %13 = extractvalue { i64, i1 } %12, 1
  br i1 %13, label %"i.-P_tIntInt.+.trap", label %i.-P_tIntInt.entry.cont

i.-P_tIntInt.entry.cont:                          ; preds = %i.-A_tIntInt.entry.cont
  %14 = extractvalue { i64, i1 } %12, 0
  %15 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %3, i64 %14)
  %16 = extractvalue { i64, i1 } %15, 1
  br i1 %16, label %"i.-P_tIntInt.+.trap12", label %i.-P_tIntInt.entry.cont9

i.-P_tIntInt.entry.cont9:                         ; preds = %i.-P_tIntInt.entry.cont
  %17 = extractvalue { i64, i1 } %15, 0
  %.fca.0.insert11 = insertvalue %Int undef, i64 %17, 0
  ret %Int %.fca.0.insert11

"i.-P_tIntInt.+.trap12":                          ; preds = %i.-P_tIntInt.entry.cont
  tail call void @llvm.trap()
  unreachable

"i.-P_tIntInt.+.trap":                            ; preds = %i.-A_tIntInt.entry.cont
  tail call void @llvm.trap()
  unreachable

"i.-A_tIntInt.*.trap":                            ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: nounwind readnone
define %Bar @Bar_tBoolIntInt(%Bool %"$0", %Int %"$1", %Int %"$2") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue %Bool %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int %"$1", 0
  %"$2.fca.0.extract" = extractvalue %Int %"$2", 0
  %.fca.0.0.insert = insertvalue %Bar undef, i1 %"$0.fca.0.extract", 0, 0
  %.fca.1.0.insert = insertvalue %Bar %.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  %.fca.2.0.insert = insertvalue %Bar %.fca.1.0.insert, i64 %"$2.fca.0.extract", 2, 0
  ret %Bar %.fca.2.0.insert
}

; Function Attrs: nounwind readnone
define %Baz @Baz_tIntInt(%Int %"$0", %Int %"$1") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int %"$1", 0
  %.fca.0.0.insert = insertvalue %Baz undef, i64 %"$0.fca.0.extract", 0, 0
  %.fca.1.0.insert = insertvalue %Baz %.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret %Baz %.fca.1.0.insert
}

; Function Attrs: nounwind
define %Int @sum_mBar(%Bar* nocapture readonly %self) #0 {
entry:
  %0 = getelementptr inbounds %Bar* %self, i64 0, i32 2, i32 0
  %1 = load i64* %0, align 8
  %2 = getelementptr inbounds %Bar* %self, i64 0, i32 1, i32 0
  %3 = load i64* %2, align 8
  %4 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %1, i64 %3)
  %5 = extractvalue { i64, i1 } %4, 1
  br i1 %5, label %"i.-P_tIntInt.+.trap", label %i.-P_tIntInt.entry.cont

i.-P_tIntInt.entry.cont:                          ; preds = %entry
  %6 = extractvalue { i64, i1 } %4, 0
  %.fca.0.insert = insertvalue %Int undef, i64 %6, 0
  ret %Int %.fca.0.insert

"i.-P_tIntInt.+.trap":                            ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

define void @main() {
foo_tEqInt.exit27:
  tail call void @vist-Uprint_ti64(i64 17)
  %0 = alloca %Bar, align 8
  %1 = alloca %Eq.ex, align 8
  %nilprop_metadata2 = getelementptr inbounds %Eq.ex* %1, i64 0, i32 0
  %nilmethod_metadata3 = getelementptr inbounds %Eq.ex* %1, i64 0, i32 1
  %nilopaque4 = getelementptr inbounds %Eq.ex* %1, i64 0, i32 2
  %metadata5 = alloca [2 x i32], align 4
  %2 = getelementptr inbounds [2 x i32]* %metadata5, i64 0, i64 0
  store i32 16, i32* %2, align 4
  %el.17 = getelementptr [2 x i32]* %metadata5, i64 0, i64 1
  store i32 8, i32* %el.17, align 4
  %3 = load [2 x i32]* %metadata5, align 4
  store [2 x i32] %3, [2 x i32]* %nilprop_metadata2, align 8
  %witness_table8 = alloca [1 x i8*], align 8
  %4 = getelementptr inbounds [1 x i8*]* %witness_table8, i64 0, i64 0
  store i8* bitcast (%Int (%Bar*)* @sum_mBar to i8*), i8** %4, align 8
  %5 = load [1 x i8*]* %witness_table8, align 8
  store [1 x i8*] %5, [1 x i8*]* %nilmethod_metadata3, align 8
  store %Bar { %Bool { i1 true }, %Int { i64 11 }, %Int { i64 4 } }, %Bar* %0, align 8
  %6 = bitcast i8** %nilopaque4 to %Bar**
  store %Bar* %0, %Bar** %6, align 8
  %7 = load %Eq.ex* %1, align 8
  %.fca.0.0.extract49 = extractvalue %Eq.ex %7, 0, 0
  %.fca.2.extract54 = extractvalue %Eq.ex %7, 2
  %8 = sext i32 %.fca.0.0.extract49 to i64
  %9 = getelementptr i8* %.fca.2.extract54, i64 %8
  %10 = bitcast i8* %9 to i64*
  %11 = load i64* %10, align 8
  %.fca.0.1.extract38 = extractvalue %Eq.ex %7, 0, 1
  %12 = sext i32 %.fca.0.1.extract38 to i64
  %13 = getelementptr i8* %.fca.2.extract54, i64 %12
  %14 = bitcast i8* %13 to i64*
  %15 = load i64* %14, align 8
  %16 = call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %15, i64 2) #0
  %17 = extractvalue { i64, i1 } %16, 1
  br i1 %17, label %"i.-A_tIntInt.*.trap.i", label %i.-A_tIntInt.entry.cont.i

i.-A_tIntInt.entry.cont.i:                        ; preds = %foo_tEqInt.exit27
  %18 = extractvalue { i64, i1 } %16, 0
  %19 = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %18, i64 2) #0
  %20 = extractvalue { i64, i1 } %19, 1
  br i1 %20, label %"i.-P_tIntInt.+.trap.i21", label %i.-P_tIntInt.entry.cont.i

i.-P_tIntInt.entry.cont.i:                        ; preds = %i.-A_tIntInt.entry.cont.i
  %21 = extractvalue { i64, i1 } %19, 0
  %22 = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %11, i64 %21) #0
  %23 = extractvalue { i64, i1 } %22, 1
  br i1 %23, label %"i.-P_tIntInt.+.trap12.i", label %foo2_tEqInt.exit

"i.-P_tIntInt.+.trap12.i":                        ; preds = %i.-P_tIntInt.entry.cont.i
  call void @llvm.trap() #0
  unreachable

"i.-P_tIntInt.+.trap.i21":                        ; preds = %i.-A_tIntInt.entry.cont.i
  call void @llvm.trap() #0
  unreachable

"i.-A_tIntInt.*.trap.i":                          ; preds = %foo_tEqInt.exit27
  call void @llvm.trap() #0
  unreachable

foo2_tEqInt.exit:                                 ; preds = %i.-P_tIntInt.entry.cont.i
  %24 = extractvalue { i64, i1 } %22, 0
  tail call void @vist-Uprint_ti64(i64 %24)
  %25 = alloca %Baz, align 8
  %26 = alloca %Eq.ex, align 8
  %nilprop_metadata10 = getelementptr inbounds %Eq.ex* %26, i64 0, i32 0
  %nilmethod_metadata11 = getelementptr inbounds %Eq.ex* %26, i64 0, i32 1
  %nilopaque12 = getelementptr inbounds %Eq.ex* %26, i64 0, i32 2
  %metadata13 = alloca [2 x i32], align 4
  %27 = getelementptr inbounds [2 x i32]* %metadata13, i64 0, i64 0
  store i32 0, i32* %27, align 4
  %el.115 = getelementptr [2 x i32]* %metadata13, i64 0, i64 1
  store i32 8, i32* %el.115, align 4
  %28 = load [2 x i32]* %metadata13, align 4
  store [2 x i32] %28, [2 x i32]* %nilprop_metadata10, align 8
  %witness_table16 = alloca [1 x i8*], align 8
  %29 = getelementptr inbounds [1 x i8*]* %witness_table16, i64 0, i64 0
  store i8* bitcast (%Int (%Baz*)* @sum_mBaz to i8*), i8** %29, align 8
  %30 = load [1 x i8*]* %witness_table16, align 8
  store [1 x i8*] %30, [1 x i8*]* %nilmethod_metadata11, align 8
  store %Baz { %Int { i64 2 }, %Int { i64 3 } }, %Baz* %25, align 8
  %31 = bitcast i8** %nilopaque12 to %Baz**
  store %Baz* %25, %Baz** %31, align 8
  %32 = load %Eq.ex* %26, align 8
  %.fca.1.0.extract20 = extractvalue %Eq.ex %32, 1, 0
  %.fca.2.extract = extractvalue %Eq.ex %32, 2
  %33 = bitcast i8* %.fca.1.0.extract20 to %Int (i8*)*
  %34 = call %Int %33(i8* %.fca.2.extract)
  %35 = extractvalue %Int %34, 0
  %36 = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %35, i64 2)
  %37 = extractvalue { i64, i1 } %36, 1
  br i1 %37, label %"i.-P_tIntInt.+.trap.i", label %foo_tEqInt.exit

"i.-P_tIntInt.+.trap.i":                          ; preds = %foo2_tEqInt.exit
  call void @llvm.trap()
  unreachable

foo_tEqInt.exit:                                  ; preds = %foo2_tEqInt.exit
  %38 = extractvalue { i64, i1 } %36, 0
  tail call void @vist-Uprint_ti64(i64 %38)
  ret void
}

; Function Attrs: nounwind readnone
define %Int @sum_mBaz(%Baz* nocapture readnone %self) #1 {
entry:
  ret %Int { i64 1 }
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #1

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #2

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #1

; Function Attrs: noinline nounwind ssp uwtable
declare void @vist-Uprint_ti64(i64) #3

attributes #0 = { nounwind }
attributes #1 = { nounwind readnone }
attributes #2 = { noreturn nounwind }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
