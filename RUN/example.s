	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$12, %eax
	movl	%eax, %ecx
	movq	%rcx, %rdi
	movq	%rcx, -8(%rbp)          ## 8-byte Spill
	callq	"_-Uprint_i64"
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	callq	"_-Uprint_i64"
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	callq	"_-Uprint_i64"
	movl	$12, %eax
	movl	%eax, %edi
	addq	$16, %rsp
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL

	.globl	_Bar_Int
	.align	4, 0x90
_Bar_Int:                               ## @Bar_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq


.subsections_via_symbols
