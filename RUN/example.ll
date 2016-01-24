; ModuleID = 'example_.ll'

define i64 @main() {
entry:
  %0 = alloca { { i64 }, { i64 }, { i64 } }
  %1 = bitcast { { i64 }, { i64 }, { i64 } }* %0 to i8*
  call void @llvm.lifetime.start(i64 -1, i8* %1)
  %2 = tail call { i64 } @_Int_i64(i64 10)
  %a_ptr.i = getelementptr inbounds { { i64 }, { i64 }, { i64 } }* %0, i32 0, i32 0
  store { i64 } %2, { i64 }* %a_ptr.i
  %3 = tail call { i64 } @_Int_i64(i64 20)
  %b_ptr.i = getelementptr inbounds { { i64 }, { i64 }, { i64 } }* %0, i32 0, i32 1
  store { i64 } %3, { i64 }* %b_ptr.i
  %4 = tail call { i64 } @_Int_i64(i64 40)
  %c_ptr.i = getelementptr inbounds { { i64 }, { i64 }, { i64 } }* %0, i32 0, i32 2
  store { i64 } %4, { i64 }* %c_ptr.i
  %5 = load { { i64 }, { i64 }, { i64 } }* %0
  call void @llvm.lifetime.end(i64 -1, i8* %1)
  %6 = tail call { i64 } @_Int_i64(i64 1)
  %7 = tail call { i64 } @_Int_i64(i64 2)
  %8 = tail call { i64 } @_Int_i64(i64 1)
  %"+.res.i" = tail call { i64 } @"_+_S.i64_S.i64"({ i64 } %6, { i64 } %8)
  %"+.res.i1" = tail call { i64 } @"_+_S.i64_S.i64"({ i64 } %"+.res.i", { i64 } %7)
  %9 = tail call { i64 } @_Int_i64(i64 1)
  %10 = tail call { i64 } @_Int_i64(i64 1)
  %a.i = extractvalue { { i64 }, { i64 }, { i64 } } %5, 0
  %b.i = extractvalue { { i64 }, { i64 }, { i64 } } %5, 1
  %c.i = extractvalue { { i64 }, { i64 }, { i64 } } %5, 2
  %"+.res.i2" = tail call { i64 } @"_+_S.i64_S.i64"({ i64 } %b.i, { i64 } %c.i)
  %"+.res1.i" = tail call { i64 } @"_+_S.i64_S.i64"({ i64 } %a.i, { i64 } %"+.res.i2")
  %"*.res.i" = tail call { i64 } @"_*_S.i64_S.i64"({ i64 } %"+.res1.i", { i64 } %10)
  %"+.res.i3" = tail call { i64 } @"_+_S.i64_S.i64"({ i64 } %9, { i64 } %"*.res.i")
  tail call void @_print_S.i64({ i64 } %"+.res.i3")
  %11 = tail call { i64 } @_Int_i64(i64 1)
  %12 = tail call { i64 } @_Int_i64(i64 2)
  %"+.res" = tail call { i64 } @"_+_S.i64_S.i64"({ i64 } %11, { i64 } %12)
  tail call void @_print_S.i64({ i64 } %"+.res")
  %13 = tail call { i64 } @_Int_i64(i64 0)
  %14 = tail call { i64 } @_Int_i64(i64 10)
  %....res = tail call { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 } %13, { i64 } %14)
  %start = extractvalue { { i64 }, { i64 } } %....res, 0
  %start.value = extractvalue { i64 } %start, 0
  %end = extractvalue { { i64 }, { i64 } } %....res, 1
  %end.value = extractvalue { i64 } %end, 0
  br label %loop.header

loop.header:                                      ; preds = %loop.header, %entry
  %loop.count.a = phi i64 [ %start.value, %entry ], [ %next.a, %loop.header ]
  %next.a = add i64 %loop.count.a, 1
  %a3 = tail call { i64 } @_Int_i64(i64 %loop.count.a)
  tail call void @_print_S.i64({ i64 } %a3)
  %loop.repeat.test = icmp sgt i64 %next.a, %end.value
  br i1 %loop.repeat.test, label %loop.exit, label %loop.header

loop.exit:                                        ; preds = %loop.header
  ret i64 0
}

; Function Attrs: alwaysinline
define { { i64 }, { i64 }, { i64 } } @_Foo_() #0 {
entry:
  %0 = alloca { { i64 }, { i64 }, { i64 } }
  %1 = tail call { i64 } @_Int_i64(i64 10)
  %a_ptr = getelementptr inbounds { { i64 }, { i64 }, { i64 } }* %0, i32 0, i32 0
  store { i64 } %1, { i64 }* %a_ptr
  %2 = tail call { i64 } @_Int_i64(i64 20)
  %b_ptr = getelementptr inbounds { { i64 }, { i64 }, { i64 } }* %0, i32 0, i32 1
  store { i64 } %2, { i64 }* %b_ptr
  %3 = tail call { i64 } @_Int_i64(i64 40)
  %c_ptr = getelementptr inbounds { { i64 }, { i64 }, { i64 } }* %0, i32 0, i32 2
  store { i64 } %3, { i64 }* %c_ptr
  %4 = load { { i64 }, { i64 }, { i64 } }* %0
  ret { { i64 }, { i64 }, { i64 } } %4
}

declare { i64 } @_Int_i64(i64)

define { i64 } @_Foo.sumTimes_S.i64({ { i64 }, { i64 }, { i64 } } %self, { i64 } %"$0") {
entry:
  %a = extractvalue { { i64 }, { i64 }, { i64 } } %self, 0
  %b = extractvalue { { i64 }, { i64 }, { i64 } } %self, 1
  %c = extractvalue { { i64 }, { i64 }, { i64 } } %self, 2
  %"+.res" = tail call { i64 } @"_+_S.i64_S.i64"({ i64 } %b, { i64 } %c)
  %"+.res1" = tail call { i64 } @"_+_S.i64_S.i64"({ i64 } %a, { i64 } %"+.res")
  %"*.res" = tail call { i64 } @"_*_S.i64_S.i64"({ i64 } %"+.res1", { i64 } %"$0")
  ret { i64 } %"*.res"
}

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

declare { i64 } @"_*_S.i64_S.i64"({ i64 }, { i64 })

define void @_Foo.printA_S.b({ { i64 }, { i64 }, { i64 } } %self, { i1 } %"$0") {
entry:
  %value = extractvalue { i1 } %"$0", 0
  br i1 %value, label %then.0, label %cont.stmt

cont.stmt:                                        ; preds = %then.0, %entry
  ret void

then.0:                                           ; preds = %entry
  %a = extractvalue { { i64 }, { i64 }, { i64 } } %self, 0
  tail call void @_print_S.i64({ i64 } %a)
  br label %cont.stmt
}

declare void @_print_S.i64({ i64 })

define { i64 } @_add_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") {
entry:
  %"+.res" = tail call { i64 } @"_+_S.i64_S.i64"({ i64 } %"$0", { i64 } %"$1")
  ret { i64 } %"+.res"
}

declare { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 }, { i64 })

; Function Attrs: nounwind
declare void @llvm.lifetime.start(i64, i8* nocapture) #1

; Function Attrs: nounwind
declare void @llvm.lifetime.end(i64, i8* nocapture) #1

attributes #0 = { alwaysinline }
attributes #1 = { nounwind }
