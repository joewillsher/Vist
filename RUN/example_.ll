; ModuleID = 'vist_module'

define i64 @main() {
entry:
  %Foo_res = call { { i64 }, { i64 }, { i64 } } @_Foo_()
  %0 = alloca { { i64 }, { i64 }, { i64 } }
  store { { i64 }, { i64 }, { i64 } } %Foo_res, { { i64 }, { i64 }, { i64 } }* %0
  %1 = call { i64 } @_Int_i64(i64 1)
  %2 = alloca { i64 }
  store { i64 } %1, { i64 }* %2
  %3 = call { i64 } @_Int_i64(i64 2)
  %4 = alloca { i64 }
  store { i64 } %3, { i64 }* %4
  %a = load { i64 }* %2
  %5 = call { i64 } @_Int_i64(i64 1)
  %add_res = call { i64 } @_add_S.i64_S.i64({ i64 } %a, { i64 } %5)
  %b = load { i64 }* %4
  %add_res1 = call { i64 } @_add_S.i64_S.i64({ i64 } %add_res, { i64 } %b)
  %6 = alloca { i64 }
  store { i64 } %add_res1, { i64 }* %6
  %7 = call { i64 } @_Int_i64(i64 1)
  %f = load { { i64 }, { i64 }, { i64 } }* %0
  %8 = call { i64 } @_Int_i64(i64 1)
  %sumTimes.res = call { i64 } @_Foo.sumTimes_S.i64({ { i64 }, { i64 }, { i64 } } %f, { i64 } %8)
  %add_res2 = call { i64 } @_add_S.i64_S.i64({ i64 } %7, { i64 } %sumTimes.res)
  call void @_print_S.i64({ i64 } %add_res2)
  %9 = call { i64 } @_Int_i64(i64 1)
  %10 = call { i64 } @_Int_i64(i64 2)
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %9, { i64 } %10)
  %11 = alloca { i64 }
  store { i64 } %"+.res", { i64 }* %11
  %w = load { i64 }* %11
  call void @_print_S.i64({ i64 } %w)
  %12 = call { i64 } @_Int_i64(i64 0)
  %13 = call { i64 } @_Int_i64(i64 10)
  %....res = call { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 } %12, { i64 } %13)
  %start = extractvalue { { i64 }, { i64 } } %....res, 0
  %start.value = extractvalue { i64 } %start, 0
  %end = extractvalue { { i64 }, { i64 } } %....res, 1
  %end.value = extractvalue { i64 } %end, 0
  br label %loop.header

loop.header:                                      ; preds = %loop.latch, %entry
  %loop.count.a = phi i64 [ %start.value, %entry ], [ %next.a, %loop.latch ]
  %next.a = add i64 1, %loop.count.a
  %a3 = call { i64 } @_Int_i64(i64 %loop.count.a)
  br label %loop.body

loop.body:                                        ; preds = %loop.header
  call void @_print_S.i64({ i64 } %a3)
  br label %loop.latch

loop.latch:                                       ; preds = %loop.body
  %loop.repeat.test = icmp sle i64 %next.a, %end.value
  br i1 %loop.repeat.test, label %loop.header, label %loop.exit

loop.exit:                                        ; preds = %loop.latch
  ret i64 0
}

; Function Attrs: alwaysinline
define { { i64 }, { i64 }, { i64 } } @_Foo_() #0 {
entry:
  %0 = alloca { { i64 }, { i64 }, { i64 } }
  %1 = call { i64 } @_Int_i64(i64 10)
  %a_ptr = getelementptr inbounds { { i64 }, { i64 }, { i64 } }* %0, i32 0, i32 0
  store { i64 } %1, { i64 }* %a_ptr
  %2 = call { i64 } @_Int_i64(i64 20)
  %b_ptr = getelementptr inbounds { { i64 }, { i64 }, { i64 } }* %0, i32 0, i32 1
  store { i64 } %2, { i64 }* %b_ptr
  %3 = call { i64 } @_Int_i64(i64 40)
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
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %b, { i64 } %c)
  %"+.res1" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %a, { i64 } %"+.res")
  %"*.res" = call { i64 } @"_*_S.i64_S.i64"({ i64 } %"+.res1", { i64 } %"$0")
  ret { i64 } %"*.res"
}

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

declare { i64 } @"_*_S.i64_S.i64"({ i64 }, { i64 })

define void @_Foo.printA_S.b({ { i64 }, { i64 }, { i64 } } %self, { i1 } %"$0") {
entry:
  %value = extractvalue { i1 } %"$0", 0
  br i1 %value, label %then.0, label %cont.stmt

cont.stmt:                                        ; preds = %entry, %then.0
  ret void

then.0:                                           ; preds = %entry
  %a = extractvalue { { i64 }, { i64 }, { i64 } } %self, 0
  call void @_print_S.i64({ i64 } %a)
  br label %cont.stmt
}

declare void @_print_S.i64({ i64 })

define { i64 } @_add_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") {
entry:
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %"$0", { i64 } %"$1")
  ret { i64 } %"+.res"
}

declare { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 }, { i64 })

attributes #0 = { alwaysinline }
