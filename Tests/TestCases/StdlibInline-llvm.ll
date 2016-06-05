; ModuleID = 'StdlibInline-llvm'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int = type { i64 }

@_gIntsconceptConformanceArr = constant [0 x i8**] zeroinitializer
@_gIntsname = constant [4 x i8] c"Int\00"
@_gInts = constant { { i8*, i32*, i32, { { i8* }*, i32 }* }**, i32, i8* } { { i8*, i32*, i32, { { i8* }*, i32 }* }** bitcast ([0 x i8**]* @_gIntsconceptConformanceArr to { i8*, i32*, i32, { { i8* }*, i32 }* }**), i32 0, i8* getelementptr inbounds ([4 x i8]* @_gIntsname, i32 0, i32 0) }

; Function Attrs: nounwind readnone
define void @main() #0 {
entry:
  ret void
}

define void @foo1_t() {
entry:
  tail call void @print_tI(%Int { i64 3 })
  ret void
}

declare void @print_tI(%Int)

attributes #0 = { nounwind readnone }
