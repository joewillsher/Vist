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
	subq	$32, %rsp
	xorl	%eax, %eax
	movl	%eax, %edi
	movl	$100, %eax
	movl	%eax, %esi
	callq	__..._S.i64_S.i64
	movq	%rdx, -8(%rbp)          ## 8-byte Spill
	movq	%rax, -16(%rbp)         ## 8-byte Spill
LBB0_1:                                 ## %loop.header
                                        ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rcx
	incq	%rcx
	movq	%rax, %rdi
	movq	%rcx, -24(%rbp)         ## 8-byte Spill
	callq	__print_S.i64
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	cmpq	%rcx, %rax
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	jle	LBB0_1
## BB#2:                                ## %loop.exit
	xorl	%eax, %eax
                                        ## kill: RAX<def> EAX<kill>
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
