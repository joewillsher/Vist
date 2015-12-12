	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 15, 2
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
	movl	$2, %edi
	callq	_bar
	movq	%rax, -8(%rbp)
	cmpq	$2, %rax
	jg	LBB0_3
## BB#1:                                ## %entry
	cmpq	$1, %rax
	jne	LBB0_3
## BB#2:                                ## %then0
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movq	$2, -16(%rax)
LBB0_3:                                 ## %cont1
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movq	$3, -16(%rax)
	xorl	%eax, %eax
	movq	%rbp, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_bar
	.align	4, 0x90
_bar:                                   ## @bar
	.cfi_startproc
## BB#0:                                ## %entry
	movq	%rdi, %rax
	retq
	.cfi_endproc


.subsections_via_symbols
