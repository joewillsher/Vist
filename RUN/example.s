	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_Foo_tInt
	.align	4, 0x90
_Foo_tInt:                              ## @Foo_tInt
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
	movl	$8, %eax
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movl	%eax, %edi
	callq	_vist_allocObject
	movq	%rax, %rdi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	callq	_vist_retainObject
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rdi
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	movq	%rcx, (%rdi)
	movq	%rax, %rdi
	callq	_vist_releaseUnretainedObject
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rax
	movq	-16(%rbp), %rcx         ## 8-byte Reload
	movl	8(%rcx), %edx
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_fooGen_tInt
	.align	4, 0x90
_fooGen_tInt:                           ## @fooGen_tInt
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
	callq	_Foo_tInt
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
	subq	$48, %rsp
	leaq	-32(%rbp), %rax
	movl	$1, %ecx
	movl	%ecx, %edi
	movq	%rax, -40(%rbp)         ## 8-byte Spill
	callq	_fooGen_tInt
	movl	%edx, -8(%rbp)
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rdi
	callq	_vist_retainObject
	movq	-16(%rbp), %rax
	movq	(%rax), %rdi
	callq	_print_tInt
	movq	-16(%rbp), %rax
	movl	-8(%rbp), %ecx
	movl	%ecx, -24(%rbp)
	movq	%rax, -32(%rbp)
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	_vist_retainObject
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	callq	_vist_releaseObject
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	callq	_vist_releaseObject
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
