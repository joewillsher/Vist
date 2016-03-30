	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_fib_Int
	.align	4, 0x90
_fib_Int:                               ## @fib_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$64, %rsp
	cmpq	$2, %rdi
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	jge	LBB0_2
## BB#1:                                ## %if.01
	movl	$1, %eax
                                        ## kill: RAX<def> EAX<kill>
	addq	$64, %rsp
	popq	%rbp
	retq
LBB0_2:                                 ## %else.1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	decq	%rax
	seto	%cl
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	movb	%cl, -17(%rbp)          ## 1-byte Spill
	jo	LBB0_8
## BB#3:                                ## %inlined.-M_Int_Int.entry.cont
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	_fib_Int
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	subq	$2, %rdi
	seto	%cl
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	movq	%rdi, -40(%rbp)         ## 8-byte Spill
	movb	%cl, -41(%rbp)          ## 1-byte Spill
	jo	LBB0_7
## BB#4:                                ## %inlined.-M_Int_Int.entry.cont7
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	_fib_Int
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	addq	%rax, %rdi
	seto	%cl
	movq	%rdi, -56(%rbp)         ## 8-byte Spill
	movb	%cl, -57(%rbp)          ## 1-byte Spill
	jo	LBB0_6
## BB#5:                                ## %inlined.-P_Int_Int.entry.cont
	movq	-56(%rbp), %rax         ## 8-byte Reload
	addq	$64, %rsp
	popq	%rbp
	retq
LBB0_6:                                 ## %inlined.-P_Int_Int.+.trap
	ud2
LBB0_7:                                 ## %inlined.-M_Int_Int.-.trap10
	ud2
LBB0_8:                                 ## %inlined.-M_Int_Int.-.trap
	ud2

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
	jmp	LBB1_1
LBB1_1:                                 ## %loop
                                        ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	%rax, %rcx
	movq	%rcx, %rdi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	callq	_fib_Int
	movq	%rax, %rdi
	callq	"_vist-Uprint_i64"
	movq	-16(%rbp), %rax         ## 8-byte Reload
	addq	$1, %rax
	cmpq	$37, %rax
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	jne	LBB1_1
## BB#2:                                ## %loop.exit
	addq	$16, %rsp
	popq	%rbp
	retq


.subsections_via_symbols
