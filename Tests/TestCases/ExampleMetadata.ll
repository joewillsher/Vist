; ModuleID = 'example'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

; %ExistentialObject = type { i8*, i32, { i8*, i32*, i32, { { i8* }*, i32 }* }** }
; %Y = type { %Bool, %Int }
; %Bool = type { i1 }
; %Int = type { i64 }

@_gXsconceptConformanceArr = constant [0 x i8**] zeroinitializer
@_gXsname = constant [2 x i8] c"X\00"
@_gXs = constant { { i8*, i32*, i32, { { i8* }*, i32 }* }**, i32, i8* } { { i8*, i32*, i32, { { i8* }*, i32 }* }** bitcast ([0 x i8**]* @_gXsconceptConformanceArr to { i8*, i32*, i32, { { i8* }*, i32 }* }**), i32 0, i8* getelementptr inbounds ([2 x i8]* @_gXsname, i32 0, i32 0) }
@_gIntsconceptConformanceArr = constant [0 x i8**] zeroinitializer
@_gIntsname = constant [4 x i8] c"Int\00"
@_gInts = constant { { i8*, i32*, i32, { { i8* }*, i32 }* }**, i32, i8* } { { i8*, i32*, i32, { { i8* }*, i32 }* }** bitcast ([0 x i8**]* @_gIntsconceptConformanceArr to { i8*, i32*, i32, { { i8* }*, i32 }* }**), i32 0, i8* getelementptr inbounds ([4 x i8]* @_gIntsname, i32 0, i32 0) }
@_gBoolsconceptConformanceArr = constant [0 x i8**] zeroinitializer
@_gBoolsname = constant [5 x i8] c"Bool\00"
@_gBools = constant { { i8*, i32*, i32, { { i8* }*, i32 }* }**, i32, i8* } { { i8*, i32*, i32, { { i8* }*, i32 }* }** bitcast ([0 x i8**]* @_gBoolsconceptConformanceArr to { i8*, i32*, i32, { { i8* }*, i32 }* }**), i32 0, i8* getelementptr inbounds ([5 x i8]* @_gBoolsname, i32 0, i32 0) }
@_gYconfXconceptconceptConformanceArr = constant [0 x i8**] zeroinitializer
@_gYconfXconcept = constant { { i8*, i32*, i32, { { i8* }*, i32 }* }**, i32, i8* } { { i8*, i32*, i32, { { i8* }*, i32 }* }** bitcast ([0 x i8**]* @_gYconfXconceptconceptConformanceArr to { i8*, i32*, i32, { { i8* }*, i32 }* }**), i32 0, i8* getelementptr inbounds ([2 x i8]* @_gXsname, i32 0, i32 0) }
@_gYconfXpropWitnessOffsetArr0 = constant i32 8
@_gYconfXpropWitnessOffsetArr01 = constant i32* @_gYconfXpropWitnessOffsetArr0
@_gYconfXpropWitnessOffsetArr1 = constant i32 0
@_gYconfXpropWitnessOffsetArr12 = constant i32* @_gYconfXpropWitnessOffsetArr1
@_gYconfXpropWitnessOffsetArr = constant [2 x i32**] [i32** @_gYconfXpropWitnessOffsetArr01, i32** @_gYconfXpropWitnessOffsetArr12]
@_gYconfXwitnessTablewitnessArr0 = constant { i8* } { i8* bitcast (void (%Y*)* @foo_mY to i8*) }
@_gYconfXwitnessTablewitnessArr03 = constant { i8* }* @_gYconfXwitnessTablewitnessArr0
@_gYconfXwitnessTablewitnessArr = constant [1 x { i8* }**] [{ i8* }** @_gYconfXwitnessTablewitnessArr03]
@_gYconfXwitnessTable = constant { { i8* }*, i32 } { { i8* }* bitcast ([1 x { i8* }**]* @_gYconfXwitnessTablewitnessArr to { i8* }*), i32 1 }
@_gYconfX = constant { i8*, i32*, i32, { { i8* }*, i32 }* } { i8* bitcast ({ { i8*, i32*, i32, { { i8* }*, i32 }* }**, i32, i8* }* @_gYconfXconcept to i8*), i32* bitcast ([2 x i32**]* @_gYconfXpropWitnessOffsetArr to i32*), i32 2, { { i8* }*, i32 }* @_gYconfXwitnessTable }


