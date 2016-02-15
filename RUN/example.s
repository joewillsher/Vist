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
	subq	$96, %rsp
	movl	$1, %eax
	movl	%eax, %edi
	callq	__Int_i64
	movq	%rax, -24(%rbp)
	movl	$0, -52(%rbp)
	movl	$0, -40(%rbp)
	movq	%rax, -48(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, -32(%rbp)
	movl	-40(%rbp), %ecx
	movq	%rax, -8(%rbp)
	movl	%ecx, -16(%rbp)
	movl	-16(%rbp), %ecx
	movq	-8(%rbp), %rax
	movq	%rax, -64(%rbp)
	movl	%ecx, -72(%rbp)
	movl	-72(%rbp), %ecx
	movq	-64(%rbp), %rax
	movq	%rax, -80(%rbp)
	movl	%ecx, -88(%rbp)
	movq	-80(%rbp), %rax
	movslq	-88(%rbp), %rdi
	movq	(%rax,%rdi), %rdi
	callq	__print_Int
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Foo_Int
	.align	4, 0x90
__Foo_Int:                              ## @_Foo_Int
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
	movq	%rdi, -8(%rbp)
	movq	%rdi, %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Bar_Eq
	.align	4, 0x90
__Bar_Eq:                               ## @_Bar_Eq
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
	movl	%edi, -16(%rbp)
	movq	%rsi, -8(%rbp)
	movl	-16(%rbp), %eax
	movq	-8(%rbp), %rdx
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
