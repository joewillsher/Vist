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
	jmp	"_-Uprint_i64"          ## TAILCALL

	.globl	_Foo_Int
	.align	4, 0x90
_Foo_Int:                               ## @Foo_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_Bar_TestC
	.align	4, 0x90
_Bar_TestC:                             ## @Bar_TestC
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, %eax
	movq	%rsi, %rdx
	popq	%rbp
	retq


.subsections_via_symbols
