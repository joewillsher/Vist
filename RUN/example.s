	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_printStr
	.align	4, 0x90
_printStr:                              ## @printStr
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	leaq	L_str(%rip), %rdi
	popq	%rbp
	jmp	_puts                   ## TAILCALL
	.cfi_endproc

	.globl	_print
	.align	4, 0x90
_print:                                 ## @print
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	movq	%rdi, %rcx
	leaq	L_.str1(%rip), %rdi
	xorl	%eax, %eax
	movq	%rcx, %rsi
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	_printd
	.align	4, 0x90
_printd:                                ## @printd
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	leaq	L_.str2(%rip), %rdi
	movb	$1, %al
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
Ltmp12:
	.cfi_offset %rbx, -32
Ltmp13:
	.cfi_offset %r14, -24
	leaq	L_.str1(%rip), %rbx
	xorl	%r14d, %r14d
	.align	4, 0x90
LBB3_1:                                 ## %loop
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB3_2 Depth 2
                                        ##     Child Loop BB3_5 Depth 2
                                        ##     Child Loop BB3_8 Depth 2
                                        ##     Child Loop BB3_11 Depth 2
                                        ##     Child Loop BB3_14 Depth 2
                                        ##     Child Loop BB3_17 Depth 2
                                        ##     Child Loop BB3_20 Depth 2
                                        ##     Child Loop BB3_23 Depth 2
                                        ##     Child Loop BB3_26 Depth 2
                                        ##     Child Loop BB3_29 Depth 2
                                        ##     Child Loop BB3_32 Depth 2
                                        ##     Child Loop BB3_35 Depth 2
                                        ##     Child Loop BB3_38 Depth 2
                                        ##     Child Loop BB3_41 Depth 2
                                        ##     Child Loop BB3_44 Depth 2
                                        ##     Child Loop BB3_47 Depth 2
                                        ##     Child Loop BB3_50 Depth 2
                                        ##     Child Loop BB3_53 Depth 2
                                        ##     Child Loop BB3_56 Depth 2
                                        ##     Child Loop BB3_59 Depth 2
                                        ##     Child Loop BB3_62 Depth 2
                                        ##     Child Loop BB3_65 Depth 2
	incq	%r14
	movl	$1, %esi
	xorl	%eax, %eax
	jmp	LBB3_2
	.align	4, 0x90
LBB3_3:                                 ## %cont0.i
                                        ##   in Loop: Header=BB3_2 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_2:                                 ## %tailrecurse.i
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_3
## BB#4:                                ## %fact.exit
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$1, %eax
	jmp	LBB3_5
	.align	4, 0x90
LBB3_6:                                 ## %cont0.i5
                                        ##   in Loop: Header=BB3_5 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_5:                                 ## %tailrecurse.i4
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_6
## BB#7:                                ## %fact.exit8
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$2, %eax
	jmp	LBB3_8
	.align	4, 0x90
LBB3_9:                                 ## %cont0.i21
                                        ##   in Loop: Header=BB3_8 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_8:                                 ## %tailrecurse.i20
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_9
## BB#10:                               ## %fact.exit24
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$3, %eax
	jmp	LBB3_11
	.align	4, 0x90
LBB3_12:                                ## %cont0.i37
                                        ##   in Loop: Header=BB3_11 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_11:                                ## %tailrecurse.i36
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_12
## BB#13:                               ## %fact.exit40
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$4, %eax
	jmp	LBB3_14
	.align	4, 0x90
LBB3_15:                                ## %cont0.i53
                                        ##   in Loop: Header=BB3_14 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_14:                                ## %tailrecurse.i52
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_15
## BB#16:                               ## %fact.exit56
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$5, %eax
	jmp	LBB3_17
	.align	4, 0x90
LBB3_18:                                ## %cont0.i69
                                        ##   in Loop: Header=BB3_17 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_17:                                ## %tailrecurse.i68
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_18
## BB#19:                               ## %fact.exit72
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$6, %eax
	jmp	LBB3_20
	.align	4, 0x90
LBB3_21:                                ## %cont0.i85
                                        ##   in Loop: Header=BB3_20 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_20:                                ## %tailrecurse.i84
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_21
## BB#22:                               ## %fact.exit88
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$7, %eax
	jmp	LBB3_23
	.align	4, 0x90
LBB3_24:                                ## %cont0.i101
                                        ##   in Loop: Header=BB3_23 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_23:                                ## %tailrecurse.i100
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_24
## BB#25:                               ## %fact.exit104
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$8, %eax
	jmp	LBB3_26
	.align	4, 0x90
LBB3_27:                                ## %cont0.i117
                                        ##   in Loop: Header=BB3_26 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_26:                                ## %tailrecurse.i116
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_27
## BB#28:                               ## %fact.exit120
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$9, %eax
	jmp	LBB3_29
	.align	4, 0x90
LBB3_30:                                ## %cont0.i133
                                        ##   in Loop: Header=BB3_29 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_29:                                ## %tailrecurse.i132
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_30
## BB#31:                               ## %fact.exit136
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$10, %eax
	jmp	LBB3_32
	.align	4, 0x90
LBB3_33:                                ## %cont0.i149
                                        ##   in Loop: Header=BB3_32 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_32:                                ## %tailrecurse.i148
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_33
## BB#34:                               ## %fact.exit152
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$11, %eax
	jmp	LBB3_35
	.align	4, 0x90
LBB3_36:                                ## %cont0.i165
                                        ##   in Loop: Header=BB3_35 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_35:                                ## %tailrecurse.i164
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_36
## BB#37:                               ## %fact.exit168
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$12, %eax
	jmp	LBB3_38
	.align	4, 0x90
LBB3_39:                                ## %cont0.i157
                                        ##   in Loop: Header=BB3_38 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_38:                                ## %tailrecurse.i156
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_39
## BB#40:                               ## %fact.exit160
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$13, %eax
	jmp	LBB3_41
	.align	4, 0x90
LBB3_42:                                ## %cont0.i141
                                        ##   in Loop: Header=BB3_41 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_41:                                ## %tailrecurse.i140
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_42
## BB#43:                               ## %fact.exit144
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$14, %eax
	jmp	LBB3_44
	.align	4, 0x90
LBB3_45:                                ## %cont0.i125
                                        ##   in Loop: Header=BB3_44 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_44:                                ## %tailrecurse.i124
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_45
## BB#46:                               ## %fact.exit128
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$15, %eax
	jmp	LBB3_47
	.align	4, 0x90
LBB3_48:                                ## %cont0.i109
                                        ##   in Loop: Header=BB3_47 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_47:                                ## %tailrecurse.i108
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_48
## BB#49:                               ## %fact.exit112
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$16, %eax
	jmp	LBB3_50
	.align	4, 0x90
LBB3_51:                                ## %cont0.i93
                                        ##   in Loop: Header=BB3_50 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_50:                                ## %tailrecurse.i92
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_51
## BB#52:                               ## %fact.exit96
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$17, %eax
	jmp	LBB3_53
	.align	4, 0x90
LBB3_54:                                ## %cont0.i77
                                        ##   in Loop: Header=BB3_53 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_53:                                ## %tailrecurse.i76
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_54
## BB#55:                               ## %fact.exit80
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$18, %eax
	jmp	LBB3_56
	.align	4, 0x90
LBB3_57:                                ## %cont0.i61
                                        ##   in Loop: Header=BB3_56 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_56:                                ## %tailrecurse.i60
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_57
## BB#58:                               ## %fact.exit64
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$19, %eax
	jmp	LBB3_59
	.align	4, 0x90
LBB3_60:                                ## %cont0.i45
                                        ##   in Loop: Header=BB3_59 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_59:                                ## %tailrecurse.i44
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_60
## BB#61:                               ## %fact.exit48
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$20, %eax
	jmp	LBB3_62
	.align	4, 0x90
LBB3_63:                                ## %cont0.i29
                                        ##   in Loop: Header=BB3_62 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_62:                                ## %tailrecurse.i28
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_63
## BB#64:                               ## %fact.exit32
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movl	$1, %esi
	movl	$21, %eax
	jmp	LBB3_65
	.align	4, 0x90
LBB3_66:                                ## %cont0.i13
                                        ##   in Loop: Header=BB3_65 Depth=2
	imulq	%rax, %rsi
	decq	%rax
LBB3_65:                                ## %tailrecurse.i12
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	$2, %rax
	jge	LBB3_66
## BB#67:                               ## %fact.exit16
                                        ##   in Loop: Header=BB3_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	cmpq	$30001, %r14            ## imm = 0x7531
	jl	LBB3_1
## BB#68:                               ## %afterloop
	xorl	%eax, %eax
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_fact
	.align	4, 0x90
_fact:                                  ## @fact
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp14:
	.cfi_def_cfa_offset 16
Ltmp15:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp16:
	.cfi_def_cfa_register %rbp
	movl	$1, %eax
	jmp	LBB4_1
	.align	4, 0x90
LBB4_3:                                 ## %else1
                                        ##   in Loop: Header=BB4_1 Depth=1
	imulq	%rdi, %rax
	decq	%rdi
LBB4_1:                                 ## %tailrecurse
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$1, %rdi
	jg	LBB4_3
## BB#2:                                ## %then0
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"sup meme\n"

L_.str1:                                ## @.str1
	.asciz	"%llu\n"

L_.str2:                                ## @.str2
	.asciz	"%f\n"

L_str:                                  ## @str
	.asciz	"sup meme"


.subsections_via_symbols
