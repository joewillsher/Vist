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
	movl	$3, %eax
	movl	%eax, %ecx
	movl	$4, %eax
	movl	%eax, %edx
	addq	%rdx, %rcx
	seto	%sil
	movq	%rcx, -8(%rbp)          ## 8-byte Spill
	movb	%sil, -9(%rbp)          ## 1-byte Spill
	jo	LBB0_1
	jmp	LBB0_2
LBB0_1:                                 ## %inlined._+_S.i64_S.i64.then.0.i
	ud2
LBB0_2:                                 ## %inlined._+_S.i64_S.i64._condFail_b.exit
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	%rax, %rdi
	callq	__$print_i64
	xorl	%ecx, %ecx
	movl	%ecx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
