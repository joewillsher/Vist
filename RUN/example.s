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
	movl	$3, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	movl	$4, %eax
	movl	%eax, %edi
	callq	__print_S.i64
	xorl	%eax, %eax
                                        ## kill: RAX<def> EAX<kill>
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
