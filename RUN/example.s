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
	leaq	L___unnamed_1(%rip), %rdi
	movl	$17, %eax
	movl	%eax, %esi
	xorl	%edx, %edx
	callq	_String_topi64b
	movq	%rax, %rdi
	movq	%rdx, %rsi
	movq	%rcx, %rdx
	popq	%rbp
	jmp	_print_tString          ## TAILCALL
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
	.align	4                       ## @0
L___unnamed_1:
	.asciz	"\360\237\244\224\360\237\244\224\360\237\244\224\360\237\244\224"


.subsections_via_symbols
