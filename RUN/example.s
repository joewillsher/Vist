	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_fooer_tI
	.align	4, 0x90
_fooer_tI:                              ## @fooer_tI
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
	movl	$8, %eax
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movl	%eax, %edi
	callq	_vist_allocObject
	movq	%rax, %rdi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	_vist_retainObject
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rdi
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, (%rdi)
	movq	%rax, %rdi
	callq	_vist_releaseUnownedObject
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movl	8(%rax), %edx
	movq	(%rax), %rcx
	movq	%rcx, -16(%rbp)
	movl	%edx, -8(%rbp)
	leaq	-16(%rbp), %rcx
	movq	%rcx, %rdi
	movq	%rcx, -40(%rbp)         ## 8-byte Spill
	callq	_vist_retainObject
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	callq	_vist_releaseUnownedObject
	movq	-16(%rbp), %rax
	movl	-8(%rbp), %edx
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
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
	subq	$64, %rsp
	leaq	-16(%rbp), %rax
	movl	$8, %edi
	movq	%rax, -40(%rbp)         ## 8-byte Spill
	callq	_vist_allocObject
	movq	%rax, %rdi
	movq	%rax, -48(%rbp)         ## 8-byte Spill
	callq	_vist_retainObject
	movq	-48(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rdi
	movq	$4, (%rdi)
	movq	%rax, %rdi
	callq	_vist_releaseUnownedObject
	movq	-48(%rbp), %rax         ## 8-byte Reload
	movl	8(%rax), %ecx
	movq	(%rax), %rdi
	movq	%rdi, -16(%rbp)
	movl	%ecx, -8(%rbp)
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	movq	%rdi, -56(%rbp)         ## 8-byte Spill
	callq	_vist_retainObject
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	callq	_vist_releaseUnownedObject
	leaq	-32(%rbp), %rax
	movq	-16(%rbp), %rdi
	movl	-8(%rbp), %ecx
	movq	%rdi, -32(%rbp)
	movl	%ecx, -24(%rbp)
	movq	%rax, %rdi
	callq	_vist_deallocUnownedObject
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_Foo_tI
	.align	4, 0x90
_Foo_tI:                                ## @Foo_tI
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
	callq	_vist_releaseUnownedObject
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rax
	movq	-16(%rbp), %rcx         ## 8-byte Reload
	movl	8(%rcx), %edx
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
