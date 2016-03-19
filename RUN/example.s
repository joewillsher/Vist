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

	.globl	_foo_Int
	.align	4, 0x90
_foo_Int:                               ## @foo_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$2, %eax
	movl	%eax, %ecx
	imulq	%rcx, %rdi
	seto	%dl
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movb	%dl, -9(%rbp)           ## 1-byte Spill
	jo	LBB1_1
	jmp	LBB1_2
LBB1_1:                                 ## %inlined.-A_Int_Int.then.0.i
	ud2
LBB1_2:                                 ## %inlined.-A_Int_Int.condFail_b.exit
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq


.subsections_via_symbols
