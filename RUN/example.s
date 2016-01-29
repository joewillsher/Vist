	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$8, %eax
	movl	%eax, %edi
	callq	__fact_S.i64
	addq	$5, %rax
	seto	%cl
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	movb	%cl, -9(%rbp)           ## 1-byte Spill
	jo	LBB0_1
	jmp	LBB0_2
LBB0_1:                                 ## %inlined._+_S.i64_S.i64.then.0.i.i
	ud2
LBB0_2:                                 ## %_foo_S.i64_S.i64.exit
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	callq	__$print_i64
	xorl	%eax, %eax
                                        ## kill: RAX<def> EAX<kill>
	addq	$16, %rsp
	popq	%rbp
	retq

	.globl	__foo_S.i64_S.i64
	.align	4, 0x90
__foo_S.i64_S.i64:                      ## @_foo_S.i64_S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	addq	%rsi, %rdi
	seto	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movb	%al, -9(%rbp)           ## 1-byte Spill
	jo	LBB1_1
	jmp	LBB1_2
LBB1_1:                                 ## %inlined._+_S.i64_S.i64.then.0.i
	ud2
LBB1_2:                                 ## %inlined._+_S.i64_S.i64._condFail_b.exit
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq

	.globl	__fact_S.i64
	.align	4, 0x90
__fact_S.i64:                           ## @_fact_S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	cmpq	$2, %rdi
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	jge	LBB2_2
## BB#1:                                ## %then.0
	movl	$1, %eax
                                        ## kill: RAX<def> EAX<kill>
	addq	$48, %rsp
	popq	%rbp
	retq
LBB2_2:                                 ## %else.1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	decq	%rax
	seto	%cl
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	movb	%cl, -17(%rbp)          ## 1-byte Spill
	jo	LBB2_3
	jmp	LBB2_4
LBB2_3:                                 ## %inlined._-_S.i64_S.i64.then.0.i
	ud2
LBB2_4:                                 ## %inlined._-_S.i64_S.i64._condFail_b.exit
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__fact_S.i64
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	imulq	%rax, %rdi
	seto	%cl
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	movb	%cl, -33(%rbp)          ## 1-byte Spill
	jo	LBB2_5
	jmp	LBB2_6
LBB2_5:                                 ## %inlined._*_S.i64_S.i64.then.0.i
	ud2
LBB2_6:                                 ## %inlined._*_S.i64_S.i64._condFail_b.exit
	movq	-32(%rbp), %rax         ## 8-byte Reload
	addq	$48, %rsp
	popq	%rbp
	retq


.subsections_via_symbols
