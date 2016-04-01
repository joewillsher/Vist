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
	movl	$6, %eax
	movl	%eax, %esi
	callq	_String_topi64
	movq	%rax, %rdi
	movq	%rdx, %rsi
	callq	_print_tString
	leaq	L___unnamed_2(%rip), %rdi
	movl	$5, %ecx
	movl	%ecx, %esi
	callq	_String_topi64
	movq	%rax, %rdi
	movq	%rdx, %rsi
	callq	_print_tString
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L___unnamed_1:                          ## @0
	.asciz	"memes"

L___unnamed_2:                          ## @1
	.asciz	"same"


.subsections_via_symbols
