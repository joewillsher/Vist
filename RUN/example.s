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
	movl	$1, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$2, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$3, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$4, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$5, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$6, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$7, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$8, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$9, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$10, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$11, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$12, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$13, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$14, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$15, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$16, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$17, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$18, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$19, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$20, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	xorl	%eax, %eax
                                        ## kill: RAX<def> EAX<kill>
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
