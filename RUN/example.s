	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$3, %eax
	movl	%eax, %edi
	popq	%rbp
	jmp	__$print_i64            ## TAILCALL


.subsections_via_symbols
