	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
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
	subq	$16, %rsp
	movl	$1, %eax
	movl	%eax, %ecx
	movq	%rcx, %rdi
	movq	%rcx, -8(%rbp)          ## 8-byte Spill
	callq	__Int_i64
	movq	%rax, %rdi
	callq	__$print_i64
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	callq	__Int_i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$2, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$3, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$4, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$5, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$6, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$7, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$8, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$9, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$10, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$11, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$12, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$13, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$14, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$15, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$16, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$17, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$18, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$19, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$20, %edx
	movl	%edx, %edi
	callq	__fib_S.i64
	movq	%rax, %rdi
	addq	$16, %rsp
	popq	%rbp
	jmp	__$print_i64            ## TAILCALL
	.cfi_endproc

	.align	4, 0x90
__fib_S.i64:                            ## @_fib_S.i64
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
	subq	$80, %rsp
	cmpq	$0, %rdi
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	jl	LBB1_2
## BB#1:                                ## %cont.stmt
	movl	$1, %eax
	movl	%eax, %edi
	callq	__Int_i64
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	cmpq	$2, %rdi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	jl	LBB1_3
	jmp	LBB1_4
LBB1_2:                                 ## %then.0
	ud2
LBB1_3:                                 ## %then.02
	movq	-16(%rbp), %rax         ## 8-byte Reload
	addq	$80, %rsp
	popq	%rbp
	retq
LBB1_4:                                 ## %else.1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	-16(%rbp), %rcx         ## 8-byte Reload
	subq	%rcx, %rax
	seto	%dl
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	movb	%dl, -25(%rbp)          ## 1-byte Spill
	jo	LBB1_5
	jmp	LBB1_6
LBB1_5:                                 ## %inlined._-_S.i64_S.i64.then.0.i
	ud2
LBB1_6:                                 ## %inlined._-_S.i64_S.i64._condFail_b.exit
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__fib_S.i64
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	subq	$2, %rdi
	seto	%cl
	movq	%rax, -40(%rbp)         ## 8-byte Spill
	movq	%rdi, -48(%rbp)         ## 8-byte Spill
	movb	%cl, -49(%rbp)          ## 1-byte Spill
	jo	LBB1_7
	jmp	LBB1_8
LBB1_7:                                 ## %inlined._-_S.i64_S.i64.then.0.i37
	ud2
LBB1_8:                                 ## %inlined._-_S.i64_S.i64._condFail_b.exit38
	movq	-48(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__fib_S.i64
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	addq	%rax, %rdi
	seto	%cl
	movq	%rdi, -64(%rbp)         ## 8-byte Spill
	movb	%cl, -65(%rbp)          ## 1-byte Spill
	jo	LBB1_9
	jmp	LBB1_10
LBB1_9:                                 ## %inlined._+_S.i64_S.i64.then.0.i
	ud2
LBB1_10:                                ## %inlined._+_S.i64_S.i64._condFail_b.exit
	movq	-64(%rbp), %rax         ## 8-byte Reload
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
