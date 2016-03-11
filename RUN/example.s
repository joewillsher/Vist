	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -8(%rbp)          ## 8-byte Spill
	jmp	LBB0_1
LBB0_1:                                 ## %loop
                                        ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	%rax, %rdi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	callq	"_-Uprint_i64"
	movq	-16(%rbp), %rax         ## 8-byte Reload
	addq	$1, %rax
	cmpq	$101, %rax
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	jne	LBB0_1
## BB#2:                                ## %loop.exit
	addq	$16, %rsp
	popq	%rbp
	retq


.subsections_via_symbols
