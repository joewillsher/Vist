; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define i64 @main() {
entry:
  br label %loop.header

loop.header:                                      ; preds = %loop.header, %entry
  %loop.count.a = phi i64 [ 1, %entry ], [ %next.a, %loop.header ]
  %next.a = add nuw nsw i64 %loop.count.a, 1
  %a2 = insertvalue { i64 } undef, i64 %loop.count.a, 0
  tail call void @_print_S.i64({ i64 } %a2)
  %exitcond = icmp eq i64 %next.a, 501
  br i1 %exitcond, label %loop.exit, label %loop.header

loop.exit:                                        ; preds = %loop.header
  ret i64 0
}

declare void @_print_S.i64({ i64 })
