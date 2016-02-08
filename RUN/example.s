	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$12, %eax
	movl	%eax, %edi
	callq	__$print_i64
	movl	$10, %eax
	movl	%eax, %edi
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	callq	__$print_i64
	movl	$3, %eax
	movl	%eax, %edi
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	callq	__$print_i64
	movl	$13, %eax
	movl	%eax, %edi
	callq	__$print_i64
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	callq	__$print_i64
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	callq	__$print_i64
	xorl	%edi, %edi
	addq	$16, %rsp
	popq	%rbp
	jmp	__$print_b              ## TAILCALL

	.globl	__StackOf2_S.i64_S.i64
	.align	4, 0x90
__StackOf2_S.i64_S.i64:                 ## @_StackOf2_S.i64_S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq


.subsections_via_symbols
