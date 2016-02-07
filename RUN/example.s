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
	subq	$16, %rsp
	movl	$1, %eax
	movl	%eax, %edi
	callq	__Int_i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$10, %ecx
	movl	%ecx, %edi
	callq	__factorial_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$4, %ecx
	movl	%ecx, %eax
	movq	%rax, %rdi
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	callq	__factorial_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	callq	__factorial_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$3, %ecx
	movl	%ecx, %edi
	callq	__factorial_S.i64
	movq	%rax, %rdi
	callq	__factorial_S.i64
	movq	%rax, %rdi
	callq	__$print_i64
	movl	$41, %ecx
	movl	%ecx, %edi
	callq	__$print_i64
	movl	$2, %ecx
	movl	%ecx, %edi
	addq	$16, %rsp
	popq	%rbp
	jmp	__$print_i64            ## TAILCALL
	.cfi_endproc

	.align	4, 0x90
__factorial_S.i64:                      ## @_factorial_S.i64
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
	subq	$48, %rsp
	movl	$1, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rcx, %rdi
	callq	__Int_i64
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	cmpq	$2, %rcx
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	jge	LBB1_2
## BB#1:                                ## %then.0
	movq	-16(%rbp), %rax         ## 8-byte Reload
	addq	$48, %rsp
	popq	%rbp
	retq
LBB1_2:                                 ## %else.1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	-16(%rbp), %rcx         ## 8-byte Reload
	subq	%rcx, %rax
	seto	%dl
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	movb	%dl, -25(%rbp)          ## 1-byte Spill
	jo	LBB1_3
	jmp	LBB1_4
LBB1_3:                                 ## %inlined._-_S.i64_S.i64.then.0.i
	ud2
LBB1_4:                                 ## %inlined._-_S.i64_S.i64._condFail_b.exit
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__factorial_S.i64
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	imulq	%rax, %rdi
	seto	%cl
	movq	%rdi, -40(%rbp)         ## 8-byte Spill
	movb	%cl, -41(%rbp)          ## 1-byte Spill
	jo	LBB1_5
	jmp	LBB1_6
LBB1_5:                                 ## %inlined._*_S.i64_S.i64.then.0.i
	ud2
LBB1_6:                                 ## %inlined._*_S.i64_S.i64._condFail_b.exit
	movq	-40(%rbp), %rax         ## 8-byte Reload
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
