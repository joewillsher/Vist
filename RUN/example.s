	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_HalfOpenRange_tII
	.align	4, 0x90
_HalfOpenRange_tII:                     ## @HalfOpenRange_tII
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq

	.globl	_loop_thunk
	.align	4, 0x90
_loop_thunk:                            ## @loop_thunk
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	popq	%rbp
	jmp	_print_tI               ## TAILCALL
	.cfi_endproc

	.globl	_generate_mHalfOpenRangePtI
	.align	4, 0x90
_generate_mHalfOpenRangePtI:            ## @generate_mHalfOpenRangePtI
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rsi, -16(%rbp)         ## 8-byte Spill
	movq	%rdx, -24(%rbp)         ## 8-byte Spill
	callq	"_-L_tII"
	testb	$1, %al
	jne	LBB2_1
	jmp	LBB2_4
LBB2_1:                                 ## %loop.preheader
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	jmp	LBB2_2
LBB2_2:                                 ## %loop
                                        ## =>This Inner Loop Header: Depth=1
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	movq	%rax, -40(%rbp)         ## 8-byte Spill
	callq	*%rcx
	movl	$1, %edx
	movl	%edx, %esi
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	callq	"_-P_tII"
	movq	%rax, %rcx
	movq	%rax, %rdi
	movq	-16(%rbp), %rsi         ## 8-byte Reload
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	callq	"_-L_tII"
	testb	$1, %al
	movq	-48(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	jne	LBB2_2
	jmp	LBB2_3
LBB2_3:                                 ## %loop.exit.loopexit
	jmp	LBB2_4
LBB2_4:                                 ## %loop.exit
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$1, %eax
	movl	%eax, %edi
	movl	$10, %eax
	movl	%eax, %esi
	callq	"_-L_tII"
	testb	$1, %al
	jne	LBB3_1
	jmp	LBB3_4
LBB3_1:                                 ## %loop.i.preheader
	movl	$1, %eax
	movl	%eax, %ecx
	movq	%rcx, -8(%rbp)          ## 8-byte Spill
	jmp	LBB3_2
LBB3_2:                                 ## %loop.i
                                        ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	%rax, %rdi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	callq	_print_tI
	movl	$1, %ecx
	movl	%ecx, %esi
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	callq	"_-P_tII"
	movq	%rax, %rsi
	movl	$10, %ecx
	movl	%ecx, %edi
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	movq	%rax, %rsi
	callq	"_-L_tII"
	testb	$1, %al
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	%rsi, -8(%rbp)          ## 8-byte Spill
	jne	LBB3_2
	jmp	LBB3_3
LBB3_3:                                 ## %generate_mHalfOpenRangePtI.exit.loopexit
	jmp	LBB3_4
LBB3_4:                                 ## %generate_mHalfOpenRangePtI.exit
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
