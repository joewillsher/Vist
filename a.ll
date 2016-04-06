; ModuleID = 'a.cpp'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%"class.std::__1::basic_string" = type { %"class.std::__1::__compressed_pair" }
%"class.std::__1::__compressed_pair" = type { %"class.std::__1::__libcpp_compressed_pair_imp" }
%"class.std::__1::__libcpp_compressed_pair_imp" = type { %"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__rep" }
%"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__rep" = type { %union.anon }
%union.anon = type { %"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__long" }
%"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__long" = type { i64, i64, i16* }
%"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__short" = type { %union.anon.0, [11 x i16] }
%union.anon.0 = type { i16 }
%"class.std::__1::__basic_string_common" = type { i8 }

@.str = private unnamed_addr constant [19 x i16] [i16 97, i16 97, i16 97, i16 97, i16 97, i16 97, i16 97, i16 97, i16 97, i16 -10178, i16 -8940, i16 97, i16 97, i16 97, i16 97, i16 97, i16 97, i16 97, i16 0], align 2
@.str.1 = private unnamed_addr constant [3 x i8] c"%s\00", align 1

; Function Attrs: ssp uwtable
define i32 @main() #0 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %a = alloca %"class.std::__1::basic_string", align 8
  %1 = bitcast %"class.std::__1::basic_string"* %a to i8*
  call void @llvm.lifetime.start(i64 24, i8* %1) #9
  call void @llvm.memset.p0i8.i64(i8* %1, i8 0, i64 24, i32 8, i1 false) #9
  %2 = tail call zeroext i1 @_ZNSt3__111char_traitsIDsE2eqEDsDs(i16 zeroext 97, i16 zeroext 0) #9
  br i1 %2, label %_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEEC1EPKDs.exit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %0, %.lr.ph.i.i.i
  %__len.02.i.i.i = phi i64 [ %3, %.lr.ph.i.i.i ], [ 0, %0 ]
  %.01.i.i.i = phi i16* [ %4, %.lr.ph.i.i.i ], [ getelementptr inbounds ([19 x i16], [19 x i16]* @.str, i64 0, i64 0), %0 ]
  %3 = add i64 %__len.02.i.i.i, 1
  %4 = getelementptr inbounds i16, i16* %.01.i.i.i, i64 1
  %5 = load i16, i16* %4, align 2, !tbaa !2
  %6 = tail call zeroext i1 @_ZNSt3__111char_traitsIDsE2eqEDsDs(i16 zeroext %5, i16 zeroext 0) #9
  br i1 %6, label %_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEEC1EPKDs.exit, label %.lr.ph.i.i.i

_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEEC1EPKDs.exit: ; preds = %.lr.ph.i.i.i, %0
  %__len.0.lcssa.i.i.i = phi i64 [ 0, %0 ], [ %3, %.lr.ph.i.i.i ]
  call void @_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEE6__initEPKDsm(%"class.std::__1::basic_string"* nonnull %a, i16* nonnull getelementptr inbounds ([19 x i16], [19 x i16]* @.str, i64 0, i64 0), i64 %__len.0.lcssa.i.i.i)
  %7 = load i8, i8* %1, align 8, !tbaa !6
  %8 = and i8 %7, 1
  %9 = icmp eq i8 %8, 0
  %10 = getelementptr inbounds %"class.std::__1::basic_string", %"class.std::__1::basic_string"* %a, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2
  %11 = load i16*, i16** %10, align 8, !tbaa !7
  %12 = bitcast %"class.std::__1::basic_string"* %a to %"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__short"*
  %13 = getelementptr inbounds %"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__short", %"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__short"* %12, i64 0, i32 1, i64 0
  %14 = select i1 %9, i16* %13, i16* %11
  %15 = call i32 (i8*, ...) @printf(i8* nonnull getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i16* %14)
  call void @_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED1Ev(%"class.std::__1::basic_string"* nonnull %a) #9
  call void @llvm.lifetime.end(i64 24, i8* nonnull %1) #9
  ret i32 0
}

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.start(i64, i8* nocapture) #1

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #2

declare i32 @__gxx_personality_v0(...)

; Function Attrs: nounwind ssp uwtable
define linkonce_odr void @_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED1Ev(%"class.std::__1::basic_string"* nocapture readonly %this) unnamed_addr #3 align 2 {
  tail call void @_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED2Ev(%"class.std::__1::basic_string"* %this) #9
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.end(i64, i8* nocapture) #1

; Function Attrs: nounwind ssp uwtable
define linkonce_odr void @_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED2Ev(%"class.std::__1::basic_string"* nocapture readonly %this) unnamed_addr #3 align 2 personality i32 (...)* @__gxx_personality_v0 {
  %1 = bitcast %"class.std::__1::basic_string"* %this to i8*
  %2 = load i8, i8* %1, align 8, !tbaa !6
  %3 = and i8 %2, 1
  %4 = icmp eq i8 %3, 0
  br i1 %4, label %9, label %5

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %"class.std::__1::basic_string", %"class.std::__1::basic_string"* %this, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2
  %7 = bitcast i16** %6 to i8**
  %8 = load i8*, i8** %7, align 8, !tbaa !7
  tail call void @_ZdlPv(i8* %8) #10
  br label %9

; <label>:9                                       ; preds = %0, %5
  ret void
}

; Function Attrs: nobuiltin nounwind
declare void @_ZdlPv(i8*) #4

; Function Attrs: ssp uwtable
define linkonce_odr void @_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEE6__initEPKDsm(%"class.std::__1::basic_string"* %this, i16* nocapture readonly %__s, i64 %__sz) #0 align 2 {
  %1 = alloca i16, align 2
  %2 = icmp ugt i64 %__sz, 9223372036854775791
  br i1 %2, label %.thread, label %4

.thread:                                          ; preds = %0
  %3 = bitcast %"class.std::__1::basic_string"* %this to %"class.std::__1::__basic_string_common"*
  tail call void @_ZNKSt3__121__basic_string_commonILb1EE20__throw_length_errorEv(%"class.std::__1::__basic_string_common"* %3)
  br label %.thread1

; <label>:4                                       ; preds = %0
  %5 = icmp ult i64 %__sz, 11
  br i1 %5, label %16, label %.thread1

.thread1:                                         ; preds = %4, %.thread
  %6 = add i64 %__sz, 8
  %7 = and i64 %6, -8
  %8 = shl i64 %7, 1
  %9 = tail call noalias i8* @_Znwm(i64 %8) #11
  %10 = bitcast i8* %9 to i16*
  %11 = getelementptr inbounds %"class.std::__1::basic_string", %"class.std::__1::basic_string"* %this, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2
  %12 = bitcast i16** %11 to i8**
  store i8* %9, i8** %12, align 8, !tbaa !7
  %13 = or i64 %7, 1
  %14 = getelementptr inbounds %"class.std::__1::basic_string", %"class.std::__1::basic_string"* %this, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0
  store i64 %13, i64* %14, align 8, !tbaa !11
  %15 = getelementptr inbounds %"class.std::__1::basic_string", %"class.std::__1::basic_string"* %this, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1
  store i64 %__sz, i64* %15, align 8, !tbaa !12
  br label %.lr.ph.i.preheader

; <label>:16                                      ; preds = %4
  %17 = shl i64 %__sz, 1
  %18 = trunc i64 %17 to i8
  %19 = bitcast %"class.std::__1::basic_string"* %this to i8*
  store i8 %18, i8* %19, align 8, !tbaa !6
  %20 = bitcast %"class.std::__1::basic_string"* %this to %"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__short"*
  %21 = getelementptr inbounds %"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__short", %"struct.std::__1::basic_string<char16_t, std::__1::char_traits<char16_t>, std::__1::allocator<char16_t> >::__short"* %20, i64 0, i32 1, i64 0
  %22 = icmp eq i64 %__sz, 0
  br i1 %22, label %_ZNSt3__111char_traitsIDsE4copyEPDsPKDsm.exit, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %16, %.thread1
  %__p.02.ph = phi i16* [ %10, %.thread1 ], [ %21, %16 ]
  br label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %.lr.ph.i
  %.05.i = phi i16* [ %24, %.lr.ph.i ], [ %__p.02.ph, %.lr.ph.i.preheader ]
  %.014.i = phi i64 [ %23, %.lr.ph.i ], [ %__sz, %.lr.ph.i.preheader ]
  %.023.i = phi i16* [ %25, %.lr.ph.i ], [ %__s, %.lr.ph.i.preheader ]
  tail call void @_ZNSt3__111char_traitsIDsE6assignERDsRKDs(i16* dereferenceable(2) %.05.i, i16* dereferenceable(2) %.023.i) #9
  %23 = add i64 %.014.i, -1
  %24 = getelementptr inbounds i16, i16* %.05.i, i64 1
  %25 = getelementptr inbounds i16, i16* %.023.i, i64 1
  %26 = icmp eq i64 %23, 0
  br i1 %26, label %_ZNSt3__111char_traitsIDsE4copyEPDsPKDsm.exit, label %.lr.ph.i

_ZNSt3__111char_traitsIDsE4copyEPDsPKDsm.exit:    ; preds = %.lr.ph.i, %16
  %__p.03 = phi i16* [ %21, %16 ], [ %__p.02.ph, %.lr.ph.i ]
  %27 = getelementptr inbounds i16, i16* %__p.03, i64 %__sz
  store i16 0, i16* %1, align 2, !tbaa !2
  call void @_ZNSt3__111char_traitsIDsE6assignERDsRKDs(i16* dereferenceable(2) %27, i16* nonnull dereferenceable(2) %1) #9
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture, i8, i64, i32, i1) #1

declare void @_ZNKSt3__121__basic_string_commonILb1EE20__throw_length_errorEv(%"class.std::__1::__basic_string_common"*) #5

; Function Attrs: inlinehint nounwind ssp uwtable
define linkonce_odr void @_ZNSt3__111char_traitsIDsE6assignERDsRKDs(i16* nocapture dereferenceable(2) %__c1, i16* nocapture readonly dereferenceable(2) %__c2) #6 align 2 {
  %1 = load i16, i16* %__c2, align 2, !tbaa !2
  store i16 %1, i16* %__c1, align 2, !tbaa !2
  ret void
}

; Function Attrs: nobuiltin
declare noalias i8* @_Znwm(i64) #7

; Function Attrs: inlinehint nounwind readnone ssp uwtable
define linkonce_odr zeroext i1 @_ZNSt3__111char_traitsIDsE2eqEDsDs(i16 zeroext %__c1, i16 zeroext %__c2) #8 align 2 {
  %1 = icmp eq i16 %__c1, %__c2
  ret i1 %1
}

attributes #0 = { ssp uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind ssp uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nobuiltin nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { inlinehint nounwind ssp uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { nobuiltin "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #8 = { inlinehint nounwind readnone ssp uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #9 = { nounwind }
attributes #10 = { builtin nounwind }
attributes #11 = { builtin }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"Apple LLVM version 7.3.0 (clang-703.0.29)"}
!2 = !{!3, !3, i64 0}
!3 = !{!"char16_t", !4, i64 0}
!4 = !{!"omnipotent char", !5, i64 0}
!5 = !{!"Simple C/C++ TBAA"}
!6 = !{!4, !4, i64 0}
!7 = !{!8, !10, i64 16}
!8 = !{!"_ZTSNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEE6__longE", !9, i64 0, !9, i64 8, !10, i64 16}
!9 = !{!"long", !4, i64 0}
!10 = !{!"any pointer", !4, i64 0}
!11 = !{!8, !9, i64 0}
!12 = !{!8, !9, i64 8}
