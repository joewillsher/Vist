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
	subq	$48, %rsp
	movl	$1, %eax
	movl	%eax, %edi
	callq	__Int_i64
	movq	%rax, -8(%rbp)
	movl	$2, %ecx
	movl	%ecx, %edi
	movq	%rax, -48(%rbp)         ## 8-byte Spill
	callq	__Int_i64
	movl	-36(%rbp), %ecx
	movl	%ecx, -24(%rbp)
	movq	-48(%rbp), %rdi         ## 8-byte Reload
	movq	%rdi, -32(%rbp)
	leaq	-32(%rbp), %rdx
	movq	%rdx, -16(%rbp)
	movl	-24(%rbp), %edi
	movq	%rdx, %rsi
	movq	%rax, %rdx
	callq	__foo_Eq_Int
	movq	%rax, %rdi
	callq	__print_Int
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__foo_Eq_Int
	.align	4, 0x90
__foo_Eq_Int:                           ## @_foo_Eq_Int
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
	subq	$16, %rsp
	movl	%edi, -16(%rbp)
	movq	%rsi, -8(%rbp)
	movq	-8(%rbp), %rsi
	movslq	-16(%rbp), %rax
	movq	(%rsi,%rax), %rdi
	movq	%rdx, %rsi
	callq	"__+_Int_Int"
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Bar_Int
	.align	4, 0x90
__Bar_Int:                              ## @_Bar_Int
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
	movq	%rdi, -8(%rbp)
	movq	%rdi, %rax
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
