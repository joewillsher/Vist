	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_print
	.align	4, 0x90
_print:                                 ## @print
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
	movq	%rdi, %rcx
	leaq	L_.str(%rip), %rdi
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
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	leaq	L_.str1(%rip), %rdi
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
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	subq	$40, %rsp
Ltmp9:
	.cfi_offset %rbx, -24
	movq	___stack_chk_guard@GOTPCREL(%rip), %rbx
	movq	(%rbx), %rbx
	movq	%rbx, -16(%rbp)
	movq	$1, -40(%rbp)
	movq	$2, -32(%rbp)
	movq	$3, -24(%rbp)
	movq	-32(%rbp), %rsi
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	cmpq	-16(%rbp), %rbx
	jne	LBB2_2
## BB#1:                                ## %entry
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	retq
LBB2_2:                                 ## %entry
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%llu\n"

L_.str1:                                ## @.str1
	.asciz	"%f\n"


.subsections_via_symbols
