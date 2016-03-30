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
	movl	$1, %eax
	movl	%eax, %esi
	callq	_..._Int_Int
	movq	%rdx, -8(%rbp)          ## 8-byte Spill
	movq	%rax, -16(%rbp)         ## 8-byte Spill
LBB0_1:                                 ## %loop
                                        ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movl	$1, %ecx
	movl	%ecx, %edi
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	callq	_print_Int
	movq	-24(%rbp), %rax         ## 8-byte Reload
	addq	$1, %rax
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	cmpq	%rdi, %rax
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	jle	LBB0_1
## BB#2:                                ## %loop.exit
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
