; ModuleID = '/Users/JoeWillsher/Developer/Vist/Vist/stdlib/shims.c'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%struct.__sFILE = type { i8*, i32, i32, i16, i16, %struct.__sbuf, i32, i8*, i32 (i8*)*, i32 (i8*, i8*, i32)*, i64 (i8*, i64, i32)*, i32 (i8*, i8*, i32)*, %struct.__sbuf, %struct.__sFILEX*, i32, [3 x i8], [1 x i8], %struct.__sbuf, i32, i64 }
%struct.__sFILEX = type opaque
%struct.__sbuf = type { i8*, i32 }

@__stdoutp = external global %struct.__sFILE*

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @"vist$Ucshim$Uwrite_topi64"(i8* %str, i64 %size) #0 {
entry:
  %str.addr = alloca i8*, align 8
  %size.addr = alloca i64, align 8
  store i8* %str, i8** %str.addr, align 8
  store i64 %size, i64* %size.addr, align 8
  %0 = load i8** %str.addr, align 8
  %1 = load i64* %size.addr, align 8
  %2 = load %struct.__sFILE** @__stdoutp, align 8
  %call = call i64 @"\01_fwrite"(i8* %0, i64 %1, i64 1, %struct.__sFILE* %2)
  ret void
}

declare i64 @"\01_fwrite"(i8*, i64, i64, %struct.__sFILE*) #1

; Function Attrs: noinline nounwind ssp uwtable
define void @"vist$Ucshim$Uputchar_ti8"(i8 signext %c) #2 {
entry:
  %retval.i = alloca i32, align 4
  %_c.addr.i = alloca i32, align 4
  %_p.addr.i = alloca %struct.__sFILE*, align 8
  %c.addr = alloca i8, align 1
  store i8 %c, i8* %c.addr, align 1
  %0 = load i8* %c.addr, align 1
  %conv = sext i8 %0 to i32
  %1 = load %struct.__sFILE** @__stdoutp, align 8
  store i32 %conv, i32* %_c.addr.i, align 4
  store %struct.__sFILE* %1, %struct.__sFILE** %_p.addr.i, align 8
  %2 = load %struct.__sFILE** %_p.addr.i, align 8
  %_w.i = getelementptr inbounds %struct.__sFILE* %2, i32 0, i32 2
  %3 = load i32* %_w.i, align 4
  %dec.i = add nsw i32 %3, -1
  store i32 %dec.i, i32* %_w.i, align 4
  %cmp.i = icmp sge i32 %dec.i, 0
  br i1 %cmp.i, label %if.then.i, label %lor.lhs.false.i

lor.lhs.false.i:                                  ; preds = %entry
  %4 = load %struct.__sFILE** %_p.addr.i, align 8
  %_w1.i = getelementptr inbounds %struct.__sFILE* %4, i32 0, i32 2
  %5 = load i32* %_w1.i, align 4
  %6 = load %struct.__sFILE** %_p.addr.i, align 8
  %_lbfsize.i = getelementptr inbounds %struct.__sFILE* %6, i32 0, i32 6
  %7 = load i32* %_lbfsize.i, align 4
  %cmp2.i = icmp sge i32 %5, %7
  br i1 %cmp2.i, label %land.lhs.true.i, label %if.else.i

land.lhs.true.i:                                  ; preds = %lor.lhs.false.i
  %8 = load i32* %_c.addr.i, align 4
  %conv.i = trunc i32 %8 to i8
  %conv3.i = sext i8 %conv.i to i32
  %cmp4.i = icmp ne i32 %conv3.i, 10
  br i1 %cmp4.i, label %if.then.i, label %if.else.i

if.then.i:                                        ; preds = %land.lhs.true.i, %entry
  %9 = load i32* %_c.addr.i, align 4
  %conv6.i = trunc i32 %9 to i8
  %10 = load %struct.__sFILE** %_p.addr.i, align 8
  %_p7.i = getelementptr inbounds %struct.__sFILE* %10, i32 0, i32 0
  %11 = load i8** %_p7.i, align 8
  %incdec.ptr.i = getelementptr inbounds i8* %11, i32 1
  store i8* %incdec.ptr.i, i8** %_p7.i, align 8
  store i8 %conv6.i, i8* %11, align 1
  %conv8.i = zext i8 %conv6.i to i32
  store i32 %conv8.i, i32* %retval.i
  br label %__sputc.exit

if.else.i:                                        ; preds = %land.lhs.true.i, %lor.lhs.false.i
  %12 = load i32* %_c.addr.i, align 4
  %13 = load %struct.__sFILE** %_p.addr.i, align 8
  %call.i = call i32 @__swbuf(i32 %12, %struct.__sFILE* %13) #3
  store i32 %call.i, i32* %retval.i
  br label %__sputc.exit

__sputc.exit:                                     ; preds = %if.then.i, %if.else.i
  %14 = load i32* %retval.i
  ret void
}

declare i32 @__swbuf(i32, %struct.__sFILE*) #1

attributes #0 = { alwaysinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
