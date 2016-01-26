; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define i64 @main() {
entry:
  %....res = tail call { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 } zeroinitializer, { i64 } { i64 100 })
  %start = extractvalue { { i64 }, { i64 } } %....res, 0
  %start.value = extractvalue { i64 } %start, 0
  %end = extractvalue { { i64 }, { i64 } } %....res, 1
  %end.value = extractvalue { i64 } %end, 0
  br label %loop.header

loop.header:                                      ; preds = %loop.header, %entry
  %loop.count.a = phi i64 [ %start.value, %entry ], [ %next.a, %loop.header ]
  %next.a = add i64 %loop.count.a, 1
  %a1 = insertvalue { i64 } undef, i64 %loop.count.a, 0
  tail call void @_print_S.i64({ i64 } %a1)
  %loop.repeat.test = icmp sgt i64 %next.a, %end.value
  br i1 %loop.repeat.test, label %loop.exit, label %loop.header

loop.exit:                                        ; preds = %loop.header
  ret i64 0
}

declare { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 }, { i64 })

declare void @_print_S.i64({ i64 })
