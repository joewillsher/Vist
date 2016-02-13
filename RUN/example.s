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
	movl	$11, %eax
	movl	%eax, %edi
	callq	__Int_i64
	movl	$4, %ecx
	movl	%ecx, %edi
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	callq	__Int_i64
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	movq	%rdi, -16(%rbp)
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rdx
	movl	$2, %ecx
	movl	%ecx, %edi
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movq	%rdx, -80(%rbp)         ## 8-byte Spill
	callq	__Int_i64
	movl	$8, -56(%rbp)
	movl	$0, -48(%rbp)
	movl	-56(%rbp), %ecx
	movl	-52(%rbp), %esi
	movl	%esi, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movq	-72(%rbp), %rdx         ## 8-byte Reload
	movq	%rdx, -40(%rbp)
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movq	%rdi, -48(%rbp)
	leaq	-48(%rbp), %rdi
	movq	%rdi, -24(%rbp)
	movl	-32(%rbp), %ecx
	movl	-28(%rbp), %esi
	movq	%rdi, -88(%rbp)         ## 8-byte Spill
	movl	%ecx, %edi
	movq	-88(%rbp), %rdx         ## 8-byte Reload
	movq	%rax, %rcx
	callq	__foo_Eq_Int
	movq	%rax, %rdi
	callq	__print_Int
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc

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
	subq	$32, %rsp
	movl	%edi, -16(%rbp)
	movl	%esi, -12(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movslq	-16(%rbp), %rax
	movq	(%rdx,%rax), %rdi
	movslq	-12(%rbp), %rax
	movq	(%rdx,%rax), %rsi
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdi
	callq	"__+_Int_Int"
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, %rsi
	callq	"__+_Int_Int"
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Bar_Int_Int
	.align	4, 0x90
__Bar_Int_Int:                          ## @_Bar_Int_Int
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
	movq	%rdi, -16(%rbp)
	movq	%rsi, -8(%rbp)
	movq	-16(%rbp), %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
