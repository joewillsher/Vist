; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.refcounted = type { %Foo*, i32 }
%Foo = type { %Int }
%Int = type { i64 }
%RefcountedObject = type { i8*, i32 }

define %Foo.refcounted @Foo_tInt(%Int %"$0") {
entry:
  %refcounted = tail call %RefcountedObject @vist_allocObject(i32 8)
  %refcounted.fca.0.extract = extractvalue %RefcountedObject %refcounted, 0
  %refcounted.fca.1.extract = extractvalue %RefcountedObject %refcounted, 1
  %0 = bitcast i8* %refcounted.fca.0.extract to %Foo*
  %a = bitcast i8* %refcounted.fca.0.extract to %Int*
  store %Int %"$0", %Int* %a, align 8
  %.fca.0.insert = insertvalue %Foo.refcounted undef, %Foo* %0, 0
  %.fca.1.insert = insertvalue %Foo.refcounted %.fca.0.insert, i32 %refcounted.fca.1.extract, 1
  ret %Foo.refcounted %.fca.1.insert
}

declare %RefcountedObject @vist_allocObject(i32)

define void @main() {
entry:
  %refcounted.i = tail call %RefcountedObject @vist_allocObject(i32 8)
  %refcounted.i.fca.0.extract = extractvalue %RefcountedObject %refcounted.i, 0
  %a.i = bitcast i8* %refcounted.i.fca.0.extract to %Int*
  store %Int { i64 1 }, %Int* %a.i, align 8
  %0 = bitcast i8* %refcounted.i.fca.0.extract to i64*
  %1 = load i64* %0, align 8
  tail call void @vist-Uprint_ti64(i64 %1)
  store %Int { i64 2 }, %Int* %a.i, align 8
  %2 = load i64* %0, align 8
  tail call void @vist-Uprint_ti64(i64 %2)
  %3 = load i64* %0, align 8
  tail call void @vist-Uprint_ti64(i64 %3)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @vist-Uprint_ti64(i64) #0

attributes #0 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
