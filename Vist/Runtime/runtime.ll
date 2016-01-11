; ModuleID = 'runtime.cpp'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%"class.std::__1::__libcpp_compressed_pair_imp" = type { %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep" }
%"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep" = type { %union.anon }
%union.anon = type { %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__long" }
%"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__long" = type { i64, i64, i8* }
%"class.std::__1::__compressed_pair" = type { %"class.std::__1::__libcpp_compressed_pair_imp" }
%"class.std::__1::basic_string" = type { %"class.std::__1::__compressed_pair" }
%"class.std::__1::allocator" = type { i8 }
%"class.std::__1::__basic_string_common" = type { i8 }
%"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__raw" = type { [3 x i64] }
%"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short" = type { %union.anon.0, [23 x i8] }
%union.anon.0 = type { i8 }

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str3 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str4 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1

; Function Attrs: noinline ssp uwtable
define void @"_$print_i64"(i64 %i) #0 {
  %1 = alloca i64, align 8
  store i64 %i, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i64 %2)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline ssp uwtable
define void @"_$print_i32"(i32 %i) #0 {
  %1 = alloca i32, align 4
  store i32 %i, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %2)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"_$print_FP64"(double %d) #0 {
  %1 = alloca double, align 8
  store double %d, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %2)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"_$print_FP32"(float %d) #0 {
  %1 = alloca float, align 4
  store float %d, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = fpext float %2 to double
  %4 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %3)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"_$print_b"(i1 zeroext %b) #0 {
  %1 = alloca i8, align 1
  %2 = zext i1 %b to i8
  store i8 %2, i8* %1, align 1
  %3 = load i8* %1, align 1
  %4 = trunc i8 %3 to i1
  br i1 %4, label %5, label %7

; <label>:5                                       ; preds = %0
  %6 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str3, i32 0, i32 0))
  br label %9

; <label>:7                                       ; preds = %0
  %8 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([7 x i8]* @.str4, i32 0, i32 0))
  br label %9

; <label>:9                                       ; preds = %7, %5
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @"_$fatalError_"() #0 {
  %1 = call i32 @raise(i32 6)
  ret void
}

declare i32 @raise(i32) #1

; Function Attrs: noinline ssp uwtable
define void @"_$demangle_Pi8Pi8i64"(i8* %output, i8* %input, i64 %length) #0 {
  %1 = alloca i8*, align 8
  %2 = alloca %"class.std::__1::__libcpp_compressed_pair_imp"*, align 8
  %3 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %4 = alloca %"class.std::__1::basic_string"*, align 8
  %5 = alloca i8*, align 8
  %6 = alloca i8*, align 8
  %7 = alloca %"class.std::__1::__libcpp_compressed_pair_imp"*, align 8
  %8 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %9 = alloca %"class.std::__1::basic_string"*, align 8
  %10 = alloca %"class.std::__1::__libcpp_compressed_pair_imp"*, align 8
  %11 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %12 = alloca %"class.std::__1::basic_string"*, align 8
  %13 = alloca %"class.std::__1::basic_string"*, align 8
  %14 = alloca %"class.std::__1::basic_string"*, align 8
  %15 = alloca %"class.std::__1::basic_string"*, align 8
  %16 = alloca %"class.std::__1::basic_string"*, align 8
  %17 = alloca i8, align 1
  %18 = alloca %"class.std::__1::basic_string"*, align 8
  %19 = alloca i8, align 1
  %20 = alloca %"class.std::__1::__libcpp_compressed_pair_imp"*, align 8
  %21 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %22 = alloca %"class.std::__1::basic_string"*, align 8
  %__a.i.i.i = alloca [3 x i64]*, align 8
  %__i.i.i.i = alloca i32, align 4
  %23 = alloca %"class.std::__1::allocator"*, align 8
  %24 = alloca %"class.std::__1::__libcpp_compressed_pair_imp"*, align 8
  %25 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %26 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %27 = alloca %"class.std::__1::basic_string"*, align 8
  %28 = alloca %"class.std::__1::basic_string"*, align 8
  %29 = alloca i8*, align 8
  %30 = alloca i8*, align 8
  %31 = alloca i64, align 8
  %accum = alloca %"class.std::__1::basic_string", align 8
  %underscore_seen = alloca i32, align 4
  %i = alloca i32, align 4
  %32 = alloca i8*
  %33 = alloca i32
  store i8* %output, i8** %29, align 8
  store i8* %input, i8** %30, align 8
  store i64 %length, i64* %31, align 8
  %34 = load i8** %30, align 8
  %35 = icmp ne i8* %34, null
  br i1 %35, label %36, label %39

; <label>:36                                      ; preds = %0
  %37 = load i8** %29, align 8
  %38 = icmp ne i8* %37, null
  br i1 %38, label %40, label %39

; <label>:39                                      ; preds = %36, %0
  br label %169

; <label>:40                                      ; preds = %36
  store %"class.std::__1::basic_string"* %accum, %"class.std::__1::basic_string"** %28, align 8
  %41 = load %"class.std::__1::basic_string"** %28
  store %"class.std::__1::basic_string"* %41, %"class.std::__1::basic_string"** %27, align 8
  %42 = load %"class.std::__1::basic_string"** %27
  %43 = bitcast %"class.std::__1::basic_string"* %42 to %"class.std::__1::__basic_string_common"*
  %44 = getelementptr inbounds %"class.std::__1::basic_string"* %42, i32 0, i32 0
  store %"class.std::__1::__compressed_pair"* %44, %"class.std::__1::__compressed_pair"** %26, align 8
  %45 = load %"class.std::__1::__compressed_pair"** %26
  store %"class.std::__1::__compressed_pair"* %45, %"class.std::__1::__compressed_pair"** %25, align 8
  %46 = load %"class.std::__1::__compressed_pair"** %25
  %47 = bitcast %"class.std::__1::__compressed_pair"* %46 to %"class.std::__1::__libcpp_compressed_pair_imp"*
  store %"class.std::__1::__libcpp_compressed_pair_imp"* %47, %"class.std::__1::__libcpp_compressed_pair_imp"** %24, align 8
  %48 = load %"class.std::__1::__libcpp_compressed_pair_imp"** %24
  %49 = bitcast %"class.std::__1::__libcpp_compressed_pair_imp"* %48 to %"class.std::__1::allocator"*
  store %"class.std::__1::allocator"* %49, %"class.std::__1::allocator"** %23, align 8
  %50 = load %"class.std::__1::allocator"** %23
  %51 = getelementptr inbounds %"class.std::__1::__libcpp_compressed_pair_imp"* %48, i32 0, i32 0
  store %"class.std::__1::basic_string"* %42, %"class.std::__1::basic_string"** %22, align 8
  %52 = load %"class.std::__1::basic_string"** %22
  %53 = getelementptr inbounds %"class.std::__1::basic_string"* %52, i32 0, i32 0
  store %"class.std::__1::__compressed_pair"* %53, %"class.std::__1::__compressed_pair"** %21, align 8
  %54 = load %"class.std::__1::__compressed_pair"** %21
  %55 = bitcast %"class.std::__1::__compressed_pair"* %54 to %"class.std::__1::__libcpp_compressed_pair_imp"*
  store %"class.std::__1::__libcpp_compressed_pair_imp"* %55, %"class.std::__1::__libcpp_compressed_pair_imp"** %20, align 8
  %56 = load %"class.std::__1::__libcpp_compressed_pair_imp"** %20
  %57 = getelementptr inbounds %"class.std::__1::__libcpp_compressed_pair_imp"* %56, i32 0, i32 0
  %58 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep"* %57, i32 0, i32 0
  %59 = bitcast %union.anon* %58 to %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__raw"*
  %60 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__raw"* %59, i32 0, i32 0
  store [3 x i64]* %60, [3 x i64]** %__a.i.i.i, align 8
  store i32 0, i32* %__i.i.i.i, align 4
  br label %61

; <label>:61                                      ; preds = %64, %40
  %62 = load i32* %__i.i.i.i, align 4
  %63 = icmp ult i32 %62, 3
  br i1 %63, label %64, label %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Ev.exit

; <label>:64                                      ; preds = %61
  %65 = load i32* %__i.i.i.i, align 4
  %66 = zext i32 %65 to i64
  %67 = load [3 x i64]** %__a.i.i.i, align 8
  %68 = getelementptr inbounds [3 x i64]* %67, i32 0, i64 %66
  store i64 0, i64* %68, align 8
  %69 = load i32* %__i.i.i.i, align 4
  %70 = add i32 %69, 1
  store i32 %70, i32* %__i.i.i.i, align 4
  br label %61

_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Ev.exit: ; preds = %61
  store i32 0, i32* %underscore_seen, align 4
  store i32 0, i32* %i, align 4
  br label %71

; <label>:71                                      ; preds = %118, %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Ev.exit
  %72 = load i32* %i, align 4
  %73 = sext i32 %72 to i64
  %74 = load i64* %31, align 8
  %75 = icmp slt i64 %73, %74
  br i1 %75, label %76, label %86

; <label>:76                                      ; preds = %71
  %77 = load i32* %i, align 4
  %78 = sext i32 %77 to i64
  %79 = load i8** %30, align 8
  %80 = getelementptr inbounds i8* %79, i64 %78
  %81 = load i8* %80, align 1
  %82 = icmp ne i8 %81, 0
  br i1 %82, label %83, label %86

; <label>:83                                      ; preds = %76
  %84 = load i32* %underscore_seen, align 4
  %85 = icmp ne i32 %84, 2
  br label %86

; <label>:86                                      ; preds = %83, %76, %71
  %87 = phi i1 [ false, %76 ], [ false, %71 ], [ %85, %83 ]
  br i1 %87, label %88, label %121

; <label>:88                                      ; preds = %86
  %89 = load i32* %i, align 4
  %90 = sext i32 %89 to i64
  %91 = load i8** %30, align 8
  %92 = getelementptr inbounds i8* %91, i64 %90
  %93 = load i8* %92, align 1
  %94 = sext i8 %93 to i32
  switch i32 %94, label %108 [
    i32 95, label %95
    i32 36, label %100
  ]

; <label>:95                                      ; preds = %88
  %96 = load i32* %underscore_seen, align 4
  %97 = icmp eq i32 %96, 1
  br i1 %97, label %98, label %99

; <label>:98                                      ; preds = %95
  store i32 2, i32* %underscore_seen, align 4
  br label %117

; <label>:99                                      ; preds = %95
  store i32 1, i32* %underscore_seen, align 4
  br label %117

; <label>:100                                     ; preds = %88
  store %"class.std::__1::basic_string"* %accum, %"class.std::__1::basic_string"** %18, align 8
  store i8 95, i8* %19, align 1
  %101 = load %"class.std::__1::basic_string"** %18
  %102 = load i8* %19, align 1
  invoke void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc(%"class.std::__1::basic_string"* %101, i8 signext %102)
          to label %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEpLEc.exit unwind label %104

_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEpLEc.exit: ; preds = %100
  br label %103

; <label>:103                                     ; preds = %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEpLEc.exit
  br label %117

; <label>:104                                     ; preds = %108, %100, %_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5c_strEv.exit
  %105 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %106 = extractvalue { i8*, i32 } %105, 0
  store i8* %106, i8** %32
  %107 = extractvalue { i8*, i32 } %105, 1
  store i32 %107, i32* %33
  invoke void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev(%"class.std::__1::basic_string"* %accum)
          to label %170 unwind label %176

; <label>:108                                     ; preds = %88
  %109 = load i32* %i, align 4
  %110 = sext i32 %109 to i64
  %111 = load i8** %30, align 8
  %112 = getelementptr inbounds i8* %111, i64 %110
  %113 = load i8* %112, align 1
  store %"class.std::__1::basic_string"* %accum, %"class.std::__1::basic_string"** %16, align 8
  store i8 %113, i8* %17, align 1
  %114 = load %"class.std::__1::basic_string"** %16
  %115 = load i8* %17, align 1
  invoke void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc(%"class.std::__1::basic_string"* %114, i8 signext %115)
          to label %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEpLEc.exit1 unwind label %104

_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEpLEc.exit1: ; preds = %108
  br label %116

; <label>:116                                     ; preds = %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEpLEc.exit1
  br label %117

; <label>:117                                     ; preds = %116, %103, %99, %98
  br label %118

; <label>:118                                     ; preds = %117
  %119 = load i32* %i, align 4
  %120 = add nsw i32 %119, 1
  store i32 %120, i32* %i, align 4
  br label %71

; <label>:121                                     ; preds = %86
  %122 = load i8** %29, align 8
  store %"class.std::__1::basic_string"* %accum, %"class.std::__1::basic_string"** %15, align 8
  %123 = load %"class.std::__1::basic_string"** %15
  store %"class.std::__1::basic_string"* %123, %"class.std::__1::basic_string"** %14, align 8
  %124 = load %"class.std::__1::basic_string"** %14
  store %"class.std::__1::basic_string"* %124, %"class.std::__1::basic_string"** %13, align 8
  %125 = load %"class.std::__1::basic_string"** %13
  store %"class.std::__1::basic_string"* %125, %"class.std::__1::basic_string"** %12, align 8
  %126 = load %"class.std::__1::basic_string"** %12
  %127 = getelementptr inbounds %"class.std::__1::basic_string"* %126, i32 0, i32 0
  store %"class.std::__1::__compressed_pair"* %127, %"class.std::__1::__compressed_pair"** %11, align 8
  %128 = load %"class.std::__1::__compressed_pair"** %11
  %129 = bitcast %"class.std::__1::__compressed_pair"* %128 to %"class.std::__1::__libcpp_compressed_pair_imp"*
  store %"class.std::__1::__libcpp_compressed_pair_imp"* %129, %"class.std::__1::__libcpp_compressed_pair_imp"** %10, align 8
  %130 = load %"class.std::__1::__libcpp_compressed_pair_imp"** %10
  %131 = getelementptr inbounds %"class.std::__1::__libcpp_compressed_pair_imp"* %130, i32 0, i32 0
  %132 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep"* %131, i32 0, i32 0
  %133 = bitcast %union.anon* %132 to %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short"*
  %134 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short"* %133, i32 0, i32 0
  %135 = bitcast %union.anon.0* %134 to i8*
  %136 = load i8* %135, align 1
  %137 = zext i8 %136 to i32
  %138 = and i32 %137, 1
  %139 = icmp ne i32 %138, 0
  br i1 %139, label %140, label %151

; <label>:140                                     ; preds = %121
  store %"class.std::__1::basic_string"* %125, %"class.std::__1::basic_string"** %4, align 8
  %141 = load %"class.std::__1::basic_string"** %4
  %142 = getelementptr inbounds %"class.std::__1::basic_string"* %141, i32 0, i32 0
  store %"class.std::__1::__compressed_pair"* %142, %"class.std::__1::__compressed_pair"** %3, align 8
  %143 = load %"class.std::__1::__compressed_pair"** %3
  %144 = bitcast %"class.std::__1::__compressed_pair"* %143 to %"class.std::__1::__libcpp_compressed_pair_imp"*
  store %"class.std::__1::__libcpp_compressed_pair_imp"* %144, %"class.std::__1::__libcpp_compressed_pair_imp"** %2, align 8
  %145 = load %"class.std::__1::__libcpp_compressed_pair_imp"** %2
  %146 = getelementptr inbounds %"class.std::__1::__libcpp_compressed_pair_imp"* %145, i32 0, i32 0
  %147 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep"* %146, i32 0, i32 0
  %148 = bitcast %union.anon* %147 to %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__long"*
  %149 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__long"* %148, i32 0, i32 2
  %150 = load i8** %149, align 8
  br label %_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5c_strEv.exit

; <label>:151                                     ; preds = %121
  store %"class.std::__1::basic_string"* %125, %"class.std::__1::basic_string"** %9, align 8
  %152 = load %"class.std::__1::basic_string"** %9
  %153 = getelementptr inbounds %"class.std::__1::basic_string"* %152, i32 0, i32 0
  store %"class.std::__1::__compressed_pair"* %153, %"class.std::__1::__compressed_pair"** %8, align 8
  %154 = load %"class.std::__1::__compressed_pair"** %8
  %155 = bitcast %"class.std::__1::__compressed_pair"* %154 to %"class.std::__1::__libcpp_compressed_pair_imp"*
  store %"class.std::__1::__libcpp_compressed_pair_imp"* %155, %"class.std::__1::__libcpp_compressed_pair_imp"** %7, align 8
  %156 = load %"class.std::__1::__libcpp_compressed_pair_imp"** %7
  %157 = getelementptr inbounds %"class.std::__1::__libcpp_compressed_pair_imp"* %156, i32 0, i32 0
  %158 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep"* %157, i32 0, i32 0
  %159 = bitcast %union.anon* %158 to %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short"*
  %160 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short"* %159, i32 0, i32 1
  %161 = getelementptr inbounds [23 x i8]* %160, i32 0, i64 0
  store i8* %161, i8** %6, align 8
  %162 = load i8** %6, align 8
  store i8* %162, i8** %5, align 8
  %163 = load i8** %5, align 8
  br label %_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5c_strEv.exit

_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5c_strEv.exit: ; preds = %140, %151
  %164 = phi i8* [ %150, %140 ], [ %163, %151 ]
  store i8* %164, i8** %1, align 8
  %165 = load i8** %1, align 8
  %166 = load i64* %31, align 8
  %167 = invoke i64 @strlcpy(i8* %122, i8* %165, i64 %166)
          to label %168 unwind label %104

; <label>:168                                     ; preds = %_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5c_strEv.exit
  call void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev(%"class.std::__1::basic_string"* %accum)
  br label %169

; <label>:169                                     ; preds = %168, %39
  ret void

; <label>:170                                     ; preds = %104
  br label %171

; <label>:171                                     ; preds = %170
  %172 = load i8** %32
  %173 = load i32* %33
  %174 = insertvalue { i8*, i32 } undef, i8* %172, 0
  %175 = insertvalue { i8*, i32 } %174, i32 %173, 1
  resume { i8*, i32 } %175

; <label>:176                                     ; preds = %104
  %177 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %178 = extractvalue { i8*, i32 } %177, 0
  call void @__clang_call_terminate(i8* %178) #3
  unreachable
}

declare i32 @__gxx_personality_v0(...)

declare i64 @strlcpy(i8*, i8*, i64) #1

declare void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev(%"class.std::__1::basic_string"*) #1

; Function Attrs: noinline noreturn nounwind
define linkonce_odr hidden void @__clang_call_terminate(i8*) #2 {
  %2 = call i8* @__cxa_begin_catch(i8* %0) #4
  call void @_ZSt9terminatev() #3
  unreachable
}

declare i8* @__cxa_begin_catch(i8*)

declare void @_ZSt9terminatev()

declare void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc(%"class.std::__1::basic_string"*, i8 signext) #1

attributes #0 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noinline noreturn nounwind }
attributes #3 = { noreturn nounwind }
attributes #4 = { nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
