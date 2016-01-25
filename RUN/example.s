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
	movl	%eax, %ecx
	movq	%rcx, -8(%rbp)          ## 8-byte Spill
	jmp	LBB0_1
LBB0_1:                                 ## %loop.header
                                        ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	%rax, %rcx
	incq	%rcx
	movq	%rax, %rdi
	movq	%rcx, -16(%rbp)         ## 8-byte Spill
	callq	__print_S.i64
	movq	-16(%rbp), %rax         ## 8-byte Reload
	cmpq	$501, %rax              ## imm = 0x1F5
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	jne	LBB0_1
## BB#2:                                ## %loop.exit
	xorl	%eax, %eax
                                        ## kill: RAX<def> EAX<kill>
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
