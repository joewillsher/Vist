; ModuleID = 'example_.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [10 x i8] c"sup meme\0A\00", align 1
@.str1 = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@str = private unnamed_addr constant [9 x i8] c"sup meme\00"

; Function Attrs: ssp uwtable
define void @printStr() #0 {
  %puts = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @str, i64 0, i64 0))
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: ssp uwtable
define void @print(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %i)
  ret void
}

; Function Attrs: ssp uwtable
define void @printd(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: ssp
define i64 @main() #2 {
entry:
  br label %loop

loop:                                             ; preds = %fact.exit16, %entry
  %i = phi i64 [ 0, %entry ], [ %nexti, %fact.exit16 ]
  %nexti = add i64 %i, 1
  br label %loop1

afterloop:                                        ; preds = %fact.exit16
  ret i64 0

loop1:                                            ; preds = %loop
  br label %tailrecurse.i

tailrecurse.i:                                    ; preds = %cont0.i, %loop1
  %accumulator.tr.i = phi i64 [ 1, %loop1 ], [ %mul_res.i, %cont0.i ]
  %"$0.tr.i" = phi i64 [ 0, %loop1 ], [ %sub_res.i, %cont0.i ]
  %cmp_lte_res.i = icmp slt i64 %"$0.tr.i", 2
  br i1 %cmp_lte_res.i, label %fact.exit, label %cont0.i

cont0.i:                                          ; preds = %tailrecurse.i
  %sub_res.i = add i64 %"$0.tr.i", -1
  %mul_res.i = mul i64 %accumulator.tr.i, %"$0.tr.i"
  br label %tailrecurse.i

fact.exit:                                        ; preds = %tailrecurse.i
  %accumulator.tr.i.lcssa = phi i64 [ %accumulator.tr.i, %tailrecurse.i ]
  %0 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i.lcssa)
  br label %tailrecurse.i4

tailrecurse.i4:                                   ; preds = %cont0.i5, %fact.exit
  %accumulator.tr.i1 = phi i64 [ 1, %fact.exit ], [ %mul_res.i7, %cont0.i5 ]
  %"$0.tr.i2" = phi i64 [ 1, %fact.exit ], [ %sub_res.i6, %cont0.i5 ]
  %cmp_lte_res.i3 = icmp slt i64 %"$0.tr.i2", 2
  br i1 %cmp_lte_res.i3, label %fact.exit8, label %cont0.i5

cont0.i5:                                         ; preds = %tailrecurse.i4
  %sub_res.i6 = add i64 %"$0.tr.i2", -1
  %mul_res.i7 = mul i64 %accumulator.tr.i1, %"$0.tr.i2"
  br label %tailrecurse.i4

fact.exit8:                                       ; preds = %tailrecurse.i4
  %accumulator.tr.i1.lcssa = phi i64 [ %accumulator.tr.i1, %tailrecurse.i4 ]
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i1.lcssa)
  br label %tailrecurse.i20

tailrecurse.i20:                                  ; preds = %cont0.i21, %fact.exit8
  %accumulator.tr.i17 = phi i64 [ 1, %fact.exit8 ], [ %mul_res.i23, %cont0.i21 ]
  %"$0.tr.i18" = phi i64 [ 2, %fact.exit8 ], [ %sub_res.i22, %cont0.i21 ]
  %cmp_lte_res.i19 = icmp slt i64 %"$0.tr.i18", 2
  br i1 %cmp_lte_res.i19, label %fact.exit24, label %cont0.i21

cont0.i21:                                        ; preds = %tailrecurse.i20
  %sub_res.i22 = add i64 %"$0.tr.i18", -1
  %mul_res.i23 = mul i64 %accumulator.tr.i17, %"$0.tr.i18"
  br label %tailrecurse.i20

fact.exit24:                                      ; preds = %tailrecurse.i20
  %accumulator.tr.i17.lcssa = phi i64 [ %accumulator.tr.i17, %tailrecurse.i20 ]
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i17.lcssa)
  br label %tailrecurse.i36

tailrecurse.i36:                                  ; preds = %cont0.i37, %fact.exit24
  %accumulator.tr.i33 = phi i64 [ 1, %fact.exit24 ], [ %mul_res.i39, %cont0.i37 ]
  %"$0.tr.i34" = phi i64 [ 3, %fact.exit24 ], [ %sub_res.i38, %cont0.i37 ]
  %cmp_lte_res.i35 = icmp slt i64 %"$0.tr.i34", 2
  br i1 %cmp_lte_res.i35, label %fact.exit40, label %cont0.i37

cont0.i37:                                        ; preds = %tailrecurse.i36
  %sub_res.i38 = add i64 %"$0.tr.i34", -1
  %mul_res.i39 = mul i64 %accumulator.tr.i33, %"$0.tr.i34"
  br label %tailrecurse.i36

fact.exit40:                                      ; preds = %tailrecurse.i36
  %accumulator.tr.i33.lcssa = phi i64 [ %accumulator.tr.i33, %tailrecurse.i36 ]
  %3 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i33.lcssa)
  br label %tailrecurse.i52

tailrecurse.i52:                                  ; preds = %cont0.i53, %fact.exit40
  %accumulator.tr.i49 = phi i64 [ 1, %fact.exit40 ], [ %mul_res.i55, %cont0.i53 ]
  %"$0.tr.i50" = phi i64 [ 4, %fact.exit40 ], [ %sub_res.i54, %cont0.i53 ]
  %cmp_lte_res.i51 = icmp slt i64 %"$0.tr.i50", 2
  br i1 %cmp_lte_res.i51, label %fact.exit56, label %cont0.i53

cont0.i53:                                        ; preds = %tailrecurse.i52
  %sub_res.i54 = add i64 %"$0.tr.i50", -1
  %mul_res.i55 = mul i64 %accumulator.tr.i49, %"$0.tr.i50"
  br label %tailrecurse.i52

fact.exit56:                                      ; preds = %tailrecurse.i52
  %accumulator.tr.i49.lcssa = phi i64 [ %accumulator.tr.i49, %tailrecurse.i52 ]
  %4 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i49.lcssa)
  br label %tailrecurse.i68

tailrecurse.i68:                                  ; preds = %cont0.i69, %fact.exit56
  %accumulator.tr.i65 = phi i64 [ 1, %fact.exit56 ], [ %mul_res.i71, %cont0.i69 ]
  %"$0.tr.i66" = phi i64 [ 5, %fact.exit56 ], [ %sub_res.i70, %cont0.i69 ]
  %cmp_lte_res.i67 = icmp slt i64 %"$0.tr.i66", 2
  br i1 %cmp_lte_res.i67, label %fact.exit72, label %cont0.i69

cont0.i69:                                        ; preds = %tailrecurse.i68
  %sub_res.i70 = add i64 %"$0.tr.i66", -1
  %mul_res.i71 = mul i64 %accumulator.tr.i65, %"$0.tr.i66"
  br label %tailrecurse.i68

fact.exit72:                                      ; preds = %tailrecurse.i68
  %accumulator.tr.i65.lcssa = phi i64 [ %accumulator.tr.i65, %tailrecurse.i68 ]
  %5 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i65.lcssa)
  br label %tailrecurse.i84

tailrecurse.i84:                                  ; preds = %cont0.i85, %fact.exit72
  %accumulator.tr.i81 = phi i64 [ 1, %fact.exit72 ], [ %mul_res.i87, %cont0.i85 ]
  %"$0.tr.i82" = phi i64 [ 6, %fact.exit72 ], [ %sub_res.i86, %cont0.i85 ]
  %cmp_lte_res.i83 = icmp slt i64 %"$0.tr.i82", 2
  br i1 %cmp_lte_res.i83, label %fact.exit88, label %cont0.i85

cont0.i85:                                        ; preds = %tailrecurse.i84
  %sub_res.i86 = add i64 %"$0.tr.i82", -1
  %mul_res.i87 = mul i64 %accumulator.tr.i81, %"$0.tr.i82"
  br label %tailrecurse.i84

fact.exit88:                                      ; preds = %tailrecurse.i84
  %accumulator.tr.i81.lcssa = phi i64 [ %accumulator.tr.i81, %tailrecurse.i84 ]
  %6 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i81.lcssa)
  br label %tailrecurse.i100

tailrecurse.i100:                                 ; preds = %cont0.i101, %fact.exit88
  %accumulator.tr.i97 = phi i64 [ 1, %fact.exit88 ], [ %mul_res.i103, %cont0.i101 ]
  %"$0.tr.i98" = phi i64 [ 7, %fact.exit88 ], [ %sub_res.i102, %cont0.i101 ]
  %cmp_lte_res.i99 = icmp slt i64 %"$0.tr.i98", 2
  br i1 %cmp_lte_res.i99, label %fact.exit104, label %cont0.i101

cont0.i101:                                       ; preds = %tailrecurse.i100
  %sub_res.i102 = add i64 %"$0.tr.i98", -1
  %mul_res.i103 = mul i64 %accumulator.tr.i97, %"$0.tr.i98"
  br label %tailrecurse.i100

fact.exit104:                                     ; preds = %tailrecurse.i100
  %accumulator.tr.i97.lcssa = phi i64 [ %accumulator.tr.i97, %tailrecurse.i100 ]
  %7 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i97.lcssa)
  br label %tailrecurse.i116

tailrecurse.i116:                                 ; preds = %cont0.i117, %fact.exit104
  %accumulator.tr.i113 = phi i64 [ 1, %fact.exit104 ], [ %mul_res.i119, %cont0.i117 ]
  %"$0.tr.i114" = phi i64 [ 8, %fact.exit104 ], [ %sub_res.i118, %cont0.i117 ]
  %cmp_lte_res.i115 = icmp slt i64 %"$0.tr.i114", 2
  br i1 %cmp_lte_res.i115, label %fact.exit120, label %cont0.i117

cont0.i117:                                       ; preds = %tailrecurse.i116
  %sub_res.i118 = add i64 %"$0.tr.i114", -1
  %mul_res.i119 = mul i64 %accumulator.tr.i113, %"$0.tr.i114"
  br label %tailrecurse.i116

fact.exit120:                                     ; preds = %tailrecurse.i116
  %accumulator.tr.i113.lcssa = phi i64 [ %accumulator.tr.i113, %tailrecurse.i116 ]
  %8 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i113.lcssa)
  br label %tailrecurse.i132

tailrecurse.i132:                                 ; preds = %cont0.i133, %fact.exit120
  %accumulator.tr.i129 = phi i64 [ 1, %fact.exit120 ], [ %mul_res.i135, %cont0.i133 ]
  %"$0.tr.i130" = phi i64 [ 9, %fact.exit120 ], [ %sub_res.i134, %cont0.i133 ]
  %cmp_lte_res.i131 = icmp slt i64 %"$0.tr.i130", 2
  br i1 %cmp_lte_res.i131, label %fact.exit136, label %cont0.i133

cont0.i133:                                       ; preds = %tailrecurse.i132
  %sub_res.i134 = add i64 %"$0.tr.i130", -1
  %mul_res.i135 = mul i64 %accumulator.tr.i129, %"$0.tr.i130"
  br label %tailrecurse.i132

fact.exit136:                                     ; preds = %tailrecurse.i132
  %accumulator.tr.i129.lcssa = phi i64 [ %accumulator.tr.i129, %tailrecurse.i132 ]
  %9 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i129.lcssa)
  br label %tailrecurse.i148

tailrecurse.i148:                                 ; preds = %cont0.i149, %fact.exit136
  %accumulator.tr.i145 = phi i64 [ 1, %fact.exit136 ], [ %mul_res.i151, %cont0.i149 ]
  %"$0.tr.i146" = phi i64 [ 10, %fact.exit136 ], [ %sub_res.i150, %cont0.i149 ]
  %cmp_lte_res.i147 = icmp slt i64 %"$0.tr.i146", 2
  br i1 %cmp_lte_res.i147, label %fact.exit152, label %cont0.i149

cont0.i149:                                       ; preds = %tailrecurse.i148
  %sub_res.i150 = add i64 %"$0.tr.i146", -1
  %mul_res.i151 = mul i64 %accumulator.tr.i145, %"$0.tr.i146"
  br label %tailrecurse.i148

fact.exit152:                                     ; preds = %tailrecurse.i148
  %accumulator.tr.i145.lcssa = phi i64 [ %accumulator.tr.i145, %tailrecurse.i148 ]
  %10 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i145.lcssa)
  br label %tailrecurse.i164

tailrecurse.i164:                                 ; preds = %cont0.i165, %fact.exit152
  %accumulator.tr.i161 = phi i64 [ 1, %fact.exit152 ], [ %mul_res.i167, %cont0.i165 ]
  %"$0.tr.i162" = phi i64 [ 11, %fact.exit152 ], [ %sub_res.i166, %cont0.i165 ]
  %cmp_lte_res.i163 = icmp slt i64 %"$0.tr.i162", 2
  br i1 %cmp_lte_res.i163, label %fact.exit168, label %cont0.i165

cont0.i165:                                       ; preds = %tailrecurse.i164
  %sub_res.i166 = add i64 %"$0.tr.i162", -1
  %mul_res.i167 = mul i64 %accumulator.tr.i161, %"$0.tr.i162"
  br label %tailrecurse.i164

fact.exit168:                                     ; preds = %tailrecurse.i164
  %accumulator.tr.i161.lcssa = phi i64 [ %accumulator.tr.i161, %tailrecurse.i164 ]
  %11 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i161.lcssa)
  br label %tailrecurse.i156

tailrecurse.i156:                                 ; preds = %cont0.i157, %fact.exit168
  %accumulator.tr.i153 = phi i64 [ 1, %fact.exit168 ], [ %mul_res.i159, %cont0.i157 ]
  %"$0.tr.i154" = phi i64 [ 12, %fact.exit168 ], [ %sub_res.i158, %cont0.i157 ]
  %cmp_lte_res.i155 = icmp slt i64 %"$0.tr.i154", 2
  br i1 %cmp_lte_res.i155, label %fact.exit160, label %cont0.i157

cont0.i157:                                       ; preds = %tailrecurse.i156
  %sub_res.i158 = add i64 %"$0.tr.i154", -1
  %mul_res.i159 = mul i64 %accumulator.tr.i153, %"$0.tr.i154"
  br label %tailrecurse.i156

fact.exit160:                                     ; preds = %tailrecurse.i156
  %accumulator.tr.i153.lcssa = phi i64 [ %accumulator.tr.i153, %tailrecurse.i156 ]
  %12 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i153.lcssa)
  br label %tailrecurse.i140

tailrecurse.i140:                                 ; preds = %cont0.i141, %fact.exit160
  %accumulator.tr.i137 = phi i64 [ 1, %fact.exit160 ], [ %mul_res.i143, %cont0.i141 ]
  %"$0.tr.i138" = phi i64 [ 13, %fact.exit160 ], [ %sub_res.i142, %cont0.i141 ]
  %cmp_lte_res.i139 = icmp slt i64 %"$0.tr.i138", 2
  br i1 %cmp_lte_res.i139, label %fact.exit144, label %cont0.i141

cont0.i141:                                       ; preds = %tailrecurse.i140
  %sub_res.i142 = add i64 %"$0.tr.i138", -1
  %mul_res.i143 = mul i64 %accumulator.tr.i137, %"$0.tr.i138"
  br label %tailrecurse.i140

fact.exit144:                                     ; preds = %tailrecurse.i140
  %accumulator.tr.i137.lcssa = phi i64 [ %accumulator.tr.i137, %tailrecurse.i140 ]
  %13 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i137.lcssa)
  br label %tailrecurse.i124

tailrecurse.i124:                                 ; preds = %cont0.i125, %fact.exit144
  %accumulator.tr.i121 = phi i64 [ 1, %fact.exit144 ], [ %mul_res.i127, %cont0.i125 ]
  %"$0.tr.i122" = phi i64 [ 14, %fact.exit144 ], [ %sub_res.i126, %cont0.i125 ]
  %cmp_lte_res.i123 = icmp slt i64 %"$0.tr.i122", 2
  br i1 %cmp_lte_res.i123, label %fact.exit128, label %cont0.i125

cont0.i125:                                       ; preds = %tailrecurse.i124
  %sub_res.i126 = add i64 %"$0.tr.i122", -1
  %mul_res.i127 = mul i64 %accumulator.tr.i121, %"$0.tr.i122"
  br label %tailrecurse.i124

fact.exit128:                                     ; preds = %tailrecurse.i124
  %accumulator.tr.i121.lcssa = phi i64 [ %accumulator.tr.i121, %tailrecurse.i124 ]
  %14 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i121.lcssa)
  br label %tailrecurse.i108

tailrecurse.i108:                                 ; preds = %cont0.i109, %fact.exit128
  %accumulator.tr.i105 = phi i64 [ 1, %fact.exit128 ], [ %mul_res.i111, %cont0.i109 ]
  %"$0.tr.i106" = phi i64 [ 15, %fact.exit128 ], [ %sub_res.i110, %cont0.i109 ]
  %cmp_lte_res.i107 = icmp slt i64 %"$0.tr.i106", 2
  br i1 %cmp_lte_res.i107, label %fact.exit112, label %cont0.i109

cont0.i109:                                       ; preds = %tailrecurse.i108
  %sub_res.i110 = add i64 %"$0.tr.i106", -1
  %mul_res.i111 = mul i64 %accumulator.tr.i105, %"$0.tr.i106"
  br label %tailrecurse.i108

fact.exit112:                                     ; preds = %tailrecurse.i108
  %accumulator.tr.i105.lcssa = phi i64 [ %accumulator.tr.i105, %tailrecurse.i108 ]
  %15 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i105.lcssa)
  br label %tailrecurse.i92

tailrecurse.i92:                                  ; preds = %cont0.i93, %fact.exit112
  %accumulator.tr.i89 = phi i64 [ 1, %fact.exit112 ], [ %mul_res.i95, %cont0.i93 ]
  %"$0.tr.i90" = phi i64 [ 16, %fact.exit112 ], [ %sub_res.i94, %cont0.i93 ]
  %cmp_lte_res.i91 = icmp slt i64 %"$0.tr.i90", 2
  br i1 %cmp_lte_res.i91, label %fact.exit96, label %cont0.i93

cont0.i93:                                        ; preds = %tailrecurse.i92
  %sub_res.i94 = add i64 %"$0.tr.i90", -1
  %mul_res.i95 = mul i64 %accumulator.tr.i89, %"$0.tr.i90"
  br label %tailrecurse.i92

fact.exit96:                                      ; preds = %tailrecurse.i92
  %accumulator.tr.i89.lcssa = phi i64 [ %accumulator.tr.i89, %tailrecurse.i92 ]
  %16 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i89.lcssa)
  br label %tailrecurse.i76

tailrecurse.i76:                                  ; preds = %cont0.i77, %fact.exit96
  %accumulator.tr.i73 = phi i64 [ 1, %fact.exit96 ], [ %mul_res.i79, %cont0.i77 ]
  %"$0.tr.i74" = phi i64 [ 17, %fact.exit96 ], [ %sub_res.i78, %cont0.i77 ]
  %cmp_lte_res.i75 = icmp slt i64 %"$0.tr.i74", 2
  br i1 %cmp_lte_res.i75, label %fact.exit80, label %cont0.i77

cont0.i77:                                        ; preds = %tailrecurse.i76
  %sub_res.i78 = add i64 %"$0.tr.i74", -1
  %mul_res.i79 = mul i64 %accumulator.tr.i73, %"$0.tr.i74"
  br label %tailrecurse.i76

fact.exit80:                                      ; preds = %tailrecurse.i76
  %accumulator.tr.i73.lcssa = phi i64 [ %accumulator.tr.i73, %tailrecurse.i76 ]
  %17 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i73.lcssa)
  br label %tailrecurse.i60

tailrecurse.i60:                                  ; preds = %cont0.i61, %fact.exit80
  %accumulator.tr.i57 = phi i64 [ 1, %fact.exit80 ], [ %mul_res.i63, %cont0.i61 ]
  %"$0.tr.i58" = phi i64 [ 18, %fact.exit80 ], [ %sub_res.i62, %cont0.i61 ]
  %cmp_lte_res.i59 = icmp slt i64 %"$0.tr.i58", 2
  br i1 %cmp_lte_res.i59, label %fact.exit64, label %cont0.i61

cont0.i61:                                        ; preds = %tailrecurse.i60
  %sub_res.i62 = add i64 %"$0.tr.i58", -1
  %mul_res.i63 = mul i64 %accumulator.tr.i57, %"$0.tr.i58"
  br label %tailrecurse.i60

fact.exit64:                                      ; preds = %tailrecurse.i60
  %accumulator.tr.i57.lcssa = phi i64 [ %accumulator.tr.i57, %tailrecurse.i60 ]
  %18 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i57.lcssa)
  br label %tailrecurse.i44

tailrecurse.i44:                                  ; preds = %cont0.i45, %fact.exit64
  %accumulator.tr.i41 = phi i64 [ 1, %fact.exit64 ], [ %mul_res.i47, %cont0.i45 ]
  %"$0.tr.i42" = phi i64 [ 19, %fact.exit64 ], [ %sub_res.i46, %cont0.i45 ]
  %cmp_lte_res.i43 = icmp slt i64 %"$0.tr.i42", 2
  br i1 %cmp_lte_res.i43, label %fact.exit48, label %cont0.i45

cont0.i45:                                        ; preds = %tailrecurse.i44
  %sub_res.i46 = add i64 %"$0.tr.i42", -1
  %mul_res.i47 = mul i64 %accumulator.tr.i41, %"$0.tr.i42"
  br label %tailrecurse.i44

fact.exit48:                                      ; preds = %tailrecurse.i44
  %accumulator.tr.i41.lcssa = phi i64 [ %accumulator.tr.i41, %tailrecurse.i44 ]
  %19 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i41.lcssa)
  br label %tailrecurse.i28

tailrecurse.i28:                                  ; preds = %cont0.i29, %fact.exit48
  %accumulator.tr.i25 = phi i64 [ 1, %fact.exit48 ], [ %mul_res.i31, %cont0.i29 ]
  %"$0.tr.i26" = phi i64 [ 20, %fact.exit48 ], [ %sub_res.i30, %cont0.i29 ]
  %cmp_lte_res.i27 = icmp slt i64 %"$0.tr.i26", 2
  br i1 %cmp_lte_res.i27, label %fact.exit32, label %cont0.i29

cont0.i29:                                        ; preds = %tailrecurse.i28
  %sub_res.i30 = add i64 %"$0.tr.i26", -1
  %mul_res.i31 = mul i64 %accumulator.tr.i25, %"$0.tr.i26"
  br label %tailrecurse.i28

fact.exit32:                                      ; preds = %tailrecurse.i28
  %accumulator.tr.i25.lcssa = phi i64 [ %accumulator.tr.i25, %tailrecurse.i28 ]
  %20 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i25.lcssa)
  br label %tailrecurse.i12

tailrecurse.i12:                                  ; preds = %cont0.i13, %fact.exit32
  %accumulator.tr.i9 = phi i64 [ 1, %fact.exit32 ], [ %mul_res.i15, %cont0.i13 ]
  %"$0.tr.i10" = phi i64 [ 21, %fact.exit32 ], [ %sub_res.i14, %cont0.i13 ]
  %cmp_lte_res.i11 = icmp slt i64 %"$0.tr.i10", 2
  br i1 %cmp_lte_res.i11, label %fact.exit16, label %cont0.i13

cont0.i13:                                        ; preds = %tailrecurse.i12
  %sub_res.i14 = add i64 %"$0.tr.i10", -1
  %mul_res.i15 = mul i64 %accumulator.tr.i9, %"$0.tr.i10"
  br label %tailrecurse.i12

fact.exit16:                                      ; preds = %tailrecurse.i12
  %accumulator.tr.i9.lcssa = phi i64 [ %accumulator.tr.i9, %tailrecurse.i12 ]
  %21 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str1, i64 0, i64 0), i64 %accumulator.tr.i9.lcssa)
  %looptest3 = icmp slt i64 %nexti, 30001
  br i1 %looptest3, label %loop, label %afterloop
}

define i64 @fact(i64 %"$0") {
entry:
  br label %tailrecurse

tailrecurse:                                      ; preds = %else1, %entry
  %accumulator.tr = phi i64 [ 1, %entry ], [ %mul_res, %else1 ]
  %"$0.tr" = phi i64 [ %"$0", %entry ], [ %sub_res, %else1 ]
  %cmp_lte_res = icmp slt i64 %"$0.tr", 2
  br i1 %cmp_lte_res, label %then0, label %cont0

cont0:                                            ; preds = %tailrecurse
  br label %else1

then0:                                            ; preds = %tailrecurse
  ret i64 %accumulator.tr

else1:                                            ; preds = %cont0
  %sub_res = add i64 %"$0.tr", -1
  %mul_res = mul i64 %accumulator.tr, %"$0.tr"
  br label %tailrecurse
}

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture) #3

attributes #0 = { ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { ssp }
attributes #3 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
