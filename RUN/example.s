	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$2, %eax
	movl	%eax, %edi
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL

	.globl	_I_Int
	.align	4, 0x90
_I_Int:                                 ## @I_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_A_I
	.align	4, 0x90
_A_I:                                   ## @A_I
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_B_X
	.align	4, 0x90
_B_X:                                   ## @B_X
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, %eax
	movq	%rsi, %rdx
	popq	%rbp
	retq


.subsections_via_symbols
