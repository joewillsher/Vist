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
	movl	$1, %eax
	movl	%eax, %edi
	callq	_print_tI
	leaq	L___unnamed_1(%rip), %rdi
	movl	$6, %eax
	movl	%eax, %esi
	movl	$1, %edx
	callq	_String_topi64b
	movq	%rax, %rdi
	movq	%rdx, %rsi
	movq	%rcx, %rdx
	callq	_print_tString
	leaq	L___unnamed_2(%rip), %rdi
	movl	$14, %r8d
	movl	%r8d, %esi
	xorl	%edx, %edx
	callq	_String_topi64b
	movq	%rax, %rdi
	movq	%rdx, %rsi
	movq	%rcx, %rdx
	popq	%rbp
	jmp	_print_tString          ## TAILCALL
	.cfi_endproc

	.globl	_foo_tI
	.align	4, 0x90
_foo_tI:                                ## @foo_tI
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
	popq	%rbp
	jmp	_print_tI               ## TAILCALL
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L___unnamed_1:                          ## @0
	.asciz	"memes"

L___unnamed_2:                          ## @1
	.asciz	"\360\237\230\216\360\237\230\227memes"


.subsections_via_symbols
