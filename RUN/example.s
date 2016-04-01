	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$5, %edi
	callq	_malloc
	movq	%rax, %rcx
	movb	$0, 4(%rax)
	movl	$1701668205, (%rax)     ## imm = 0x656D656D
	movq	%rcx, %rdi
	popq	%rbp
	jmp	"_vist-Uprint_top"      ## TAILCALL

	.section	__TEXT,__cstring,cstring_literals
L___unnamed_1:                          ## @0
	.asciz	"meme"


.subsections_via_symbols
