; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Foo.st = type { %Int.st }
%TestC.ex = type { [1 x i32], i8* }
%Bar.st = type { %TestC.ex }
%Bool.st = type { i1 }

define void @main() {
entry:
  %0 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %Foo_res = call %Foo.st @Foo_Int(%Int.st %0)
  %1 = alloca %TestC.ex
  %.metadata = getelementptr inbounds %TestC.ex* %1, i32 0, i32 0
  %.opaque = getelementptr inbounds %TestC.ex* %1, i32 0, i32 1
  %2 = alloca %Foo.st
  %metadata = alloca [1 x i32]
  %3 = bitcast [1 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %3, i32 0
  store i32 0, i32* %el.0
  %4 = load [1 x i32]* %metadata
  store [1 x i32] %4, [1 x i32]* %.metadata
  store %Foo.st %Foo_res, %Foo.st* %2
  %5 = bitcast %Foo.st* %2 to i8*
  store i8* %5, i8** %.opaque
  %6 = load %TestC.ex* %1
  %Bar_res = call %Bar.st @Bar_TestC(%TestC.ex %6)
  %b = alloca %Bar.st
  store %Bar.st %Bar_res, %Bar.st* %b
  %b.foo.ptr = getelementptr inbounds %Bar.st* %b, i32 0, i32 0
  %b.foo = load %TestC.ex* %b.foo.ptr
  %7 = alloca %TestC.ex
  store %TestC.ex %b.foo, %TestC.ex* %7
  store %TestC.ex %b.foo, %TestC.ex* %7
  %.metadata_ptr = getelementptr inbounds %TestC.ex* %7, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %.metadata_ptr to i32*
  %8 = getelementptr i32* %metadata_base_ptr, i32 0
  %9 = load i32* %8
  %.element_pointer = getelementptr inbounds %TestC.ex* %7, i32 0, i32 1
  %.opaque_instance_pointer = load i8** %.element_pointer
  %10 = getelementptr i8* %.opaque_instance_pointer, i32 %9
  %t.ptr = bitcast i8* %10 to %Int.st*
  %t = load %Int.st* %t.ptr
  %u = alloca %Int.st
  store %Int.st %t, %Int.st* %u
  %u1 = load %Int.st* %u
  call void @print_Int(%Int.st %u1), !stdlib.call.optim !0
  %11 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %factorial_res = call %Int.st @factorial_Int(%Int.st %11)
  call void @print_Int(%Int.st %factorial_res), !stdlib.call.optim !0
  %12 = call %Int.st @Int_i64(i64 10), !stdlib.call.optim !0
  %factorial_res2 = call %Int.st @factorial_Int(%Int.st %12)
  call void @print_Int(%Int.st %factorial_res2), !stdlib.call.optim !0
  %13 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %14 = call %Int.st @Int_i64(i64 3), !stdlib.call.optim !0
  %"+.res" = call %Int.st @-P_Int_Int(%Int.st %13, %Int.st %14), !stdlib.call.optim !0
  %factorial_res3 = call %Int.st @factorial_Int(%Int.st %"+.res")
  call void @print_Int(%Int.st %factorial_res3), !stdlib.call.optim !0
  %15 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %dupe_res = call { %Int.st, %Int.st } @dupe_Int(%Int.st %15)
  %dupe = alloca { %Int.st, %Int.st }
  store { %Int.st, %Int.st } %dupe_res, { %Int.st, %Int.st }* %dupe
  %dupe.0.ptr = getelementptr inbounds { %Int.st, %Int.st }* %dupe, i32 0, i32 0
  %dupe.0 = load %Int.st* %dupe.0.ptr
  %dupe.1.ptr = getelementptr inbounds { %Int.st, %Int.st }* %dupe, i32 0, i32 1
  %dupe.1 = load %Int.st* %dupe.1.ptr
  %"+.res4" = call %Int.st @-P_Int_Int(%Int.st %dupe.0, %Int.st %dupe.1), !stdlib.call.optim !0
  %factorial_res5 = call %Int.st @factorial_Int(%Int.st %"+.res4")
  %w = alloca %Int.st
  store %Int.st %factorial_res5, %Int.st* %w
  %w6 = load %Int.st* %w
  call void @print_Int(%Int.st %w6), !stdlib.call.optim !0
  %16 = call %Int.st @Int_i64(i64 3), !stdlib.call.optim !0
  %factorial_res7 = call %Int.st @factorial_Int(%Int.st %16)
  %factorial_res8 = call %Int.st @factorial_Int(%Int.st %factorial_res7)
  call void @print_Int(%Int.st %factorial_res8), !stdlib.call.optim !0
  call void @void_()
  %two_res = call %Int.st @two_()
  call void @print_Int(%Int.st %two_res), !stdlib.call.optim !0
  %17 = call %Int.st @Int_i64(i64 3), !stdlib.call.optim !0
  %a = alloca %Int.st
  store %Int.st %17, %Int.st* %a
  %a9 = load %Int.st* %a
  %18 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %19 = call %Int.st @Int_i64(i64 100), !stdlib.call.optim !0
  %"*.res" = call %Int.st @-A_Int_Int(%Int.st %18, %Int.st %19), !stdlib.call.optim !0
  %"<.res" = call %Bool.st @-L_Int_Int(%Int.st %a9, %Int.st %"*.res"), !stdlib.call.optim !0
  %20 = extractvalue %Bool.st %"<.res", 0
  br i1 %20, label %then.0, label %cont.stmt

cont.stmt:                                        ; preds = %entry, %then.0
  %a11 = load %Int.st* %a
  %21 = call %Int.st @Int_i64(i64 4), !stdlib.call.optim !0
  %">.res" = call %Bool.st @-G_Int_Int(%Int.st %a11, %Int.st %21), !stdlib.call.optim !0
  %22 = extractvalue %Bool.st %">.res", 0
  br i1 %22, label %then.012, label %cont.0

then.0:                                           ; preds = %entry
  %23 = call %Int.st @Int_i64(i64 100), !stdlib.call.optim !0
  call void @print_Int(%Int.st %23), !stdlib.call.optim !0
  br label %cont.stmt

cont.stmt10:                                      ; preds = %cont.0, %then.1, %then.012
  %24 = call %Bool.st @Bool_b(i1 false), !stdlib.call.optim !0
  %25 = extractvalue %Bool.st %24, 0
  br i1 %25, label %then.016, label %cont.015

cont.0:                                           ; preds = %cont.stmt
  %a13 = load %Int.st* %a
  %26 = call %Int.st @Int_i64(i64 3), !stdlib.call.optim !0
  %"==.res" = call %Bool.st @-E-E_Int_Int(%Int.st %a13, %Int.st %26), !stdlib.call.optim !0
  %27 = extractvalue %Bool.st %"==.res", 0
  br i1 %27, label %then.1, label %cont.stmt10

then.012:                                         ; preds = %cont.stmt
  %28 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  call void @print_Int(%Int.st %28), !stdlib.call.optim !0
  br label %cont.stmt10

then.1:                                           ; preds = %cont.0
  %29 = call %Int.st @Int_i64(i64 11), !stdlib.call.optim !0
  call void @print_Int(%Int.st %29), !stdlib.call.optim !0
  br label %cont.stmt10

cont.stmt14:                                      ; preds = %else.2, %then.117, %then.016
  ret void

cont.015:                                         ; preds = %cont.stmt10
  %30 = call %Bool.st @Bool_b(i1 false), !stdlib.call.optim !0
  %31 = extractvalue %Bool.st %30, 0
  br i1 %31, label %then.117, label %cont.1

then.016:                                         ; preds = %cont.stmt10
  %32 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  call void @print_Int(%Int.st %32), !stdlib.call.optim !0
  br label %cont.stmt14

cont.1:                                           ; preds = %cont.015
  br label %else.2

then.117:                                         ; preds = %cont.015
  %33 = call %Bool.st @Bool_b(i1 false), !stdlib.call.optim !0
  call void @print_Bool(%Bool.st %33), !stdlib.call.optim !0
  br label %cont.stmt14

else.2:                                           ; preds = %cont.1
  %34 = call %Int.st @Int_i64(i64 20), !stdlib.call.optim !0
  call void @print_Int(%Int.st %34), !stdlib.call.optim !0
  br label %cont.stmt14
}

; Function Attrs: alwaysinline
define %Foo.st @Foo_Int(%Int.st %"$0") #0 {
entry:
  %Foo = alloca %Foo.st
  %Foo.t.ptr = getelementptr inbounds %Foo.st* %Foo, i32 0, i32 0
  store %Int.st %"$0", %Int.st* %Foo.t.ptr
  %Foo1 = load %Foo.st* %Foo
  ret %Foo.st %Foo1
}

; Function Attrs: alwaysinline
define %Bar.st @Bar_TestC(%TestC.ex %"$0") #0 {
entry:
  %"$01" = alloca %TestC.ex
  store %TestC.ex %"$0", %TestC.ex* %"$01"
  %Bar = alloca %Bar.st
  %"$02" = load %TestC.ex* %"$01"
  %Bar.foo.ptr = getelementptr inbounds %Bar.st* %Bar, i32 0, i32 0
  store %TestC.ex %"$02", %TestC.ex* %Bar.foo.ptr
  %Bar3 = load %Bar.st* %Bar
  ret %Bar.st %Bar3
}

declare %Int.st @Int_i64(i64)

declare void @print_Int(%Int.st)

define internal { %Int.st, %Int.st } @dupe_Int(%Int.st %a) {
entry:
  %0 = alloca { %Int.st, %Int.st }
  %.0.ptr = getelementptr inbounds { %Int.st, %Int.st }* %0, i32 0, i32 0
  store %Int.st %a, %Int.st* %.0.ptr
  %.1.ptr = getelementptr inbounds { %Int.st, %Int.st }* %0, i32 0, i32 1
  store %Int.st %a, %Int.st* %.1.ptr
  %1 = load { %Int.st, %Int.st }* %0
  ret { %Int.st, %Int.st } %1
}

define internal %Int.st @factorial_Int(%Int.st %a) {
entry:
  %0 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %"<=.res" = call %Bool.st @-L-E_Int_Int(%Int.st %a, %Int.st %0), !stdlib.call.optim !0
  %1 = extractvalue %Bool.st %"<=.res", 0
  br i1 %1, label %then.0, label %cont.0

cont.0:                                           ; preds = %entry
  br label %else.1

then.0:                                           ; preds = %entry
  %2 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  ret %Int.st %2

else.1:                                           ; preds = %cont.0
  %3 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %-.res = call %Int.st @-M_Int_Int(%Int.st %a, %Int.st %3), !stdlib.call.optim !0
  %factorial_res = call %Int.st @factorial_Int(%Int.st %-.res)
  %"*.res" = call %Int.st @-A_Int_Int(%Int.st %a, %Int.st %factorial_res), !stdlib.call.optim !0
  ret %Int.st %"*.res"
}

declare %Bool.st @-L-E_Int_Int(%Int.st, %Int.st)

declare %Int.st @-M_Int_Int(%Int.st, %Int.st)

declare %Int.st @-A_Int_Int(%Int.st, %Int.st)

declare %Int.st @-P_Int_Int(%Int.st, %Int.st)

define internal void @void_() {
entry:
  %0 = call %Int.st @Int_i64(i64 41), !stdlib.call.optim !0
  call void @print_Int(%Int.st %0), !stdlib.call.optim !0
  ret void
}

define internal %Int.st @two_() {
entry:
  %0 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  ret %Int.st %0
}

declare %Bool.st @-L_Int_Int(%Int.st, %Int.st)

declare %Bool.st @-G_Int_Int(%Int.st, %Int.st)

declare %Bool.st @-E-E_Int_Int(%Int.st, %Int.st)

declare %Bool.st @Bool_b(i1)

declare void @print_Bool(%Bool.st)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
