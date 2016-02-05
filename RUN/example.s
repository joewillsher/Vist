	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -8(%rbp)          ## 8-byte Spill
	jmp	LBB0_1
LBB0_1:                                 ## %loop.header
                                        ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movl	$3, %ecx
	movl	%ecx, %edx
	movq	%rax, %rsi
	addq	$1, %rsi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	xorl	%ecx, %ecx
	movq	%rdx, -24(%rbp)         ## 8-byte Spill
	movl	%ecx, %edx
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	divq	%rdi
	cmpq	$0, %rdx
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	je	LBB0_5
	jmp	LBB0_4
LBB0_2:                                 ## %loop.exit
	addq	$48, %rsp
	popq	%rbp
	retq
LBB0_3:                                 ## %cont.stmt
                                        ##   in Loop: Header=BB0_1 Depth=1
	movq	-32(%rbp), %rax         ## 8-byte Reload
	cmpq	$1001, %rax             ## imm = 0x3E9
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	jl	LBB0_1
	jmp	LBB0_2
LBB0_4:                                 ## %cont.0
                                        ##   in Loop: Header=BB0_1 Depth=1
	movl	$1000, %eax             ## imm = 0x3E8
	movl	%eax, %ecx
	movq	-16(%rbp), %rax         ## 8-byte Reload
	xorl	%edx, %edx
                                        ## kill: RDX<def> EDX<kill>
	divq	%rcx
	cmpq	$0, %rdx
	je	LBB0_8
	jmp	LBB0_9
LBB0_5:                                 ## %then.0
                                        ##   in Loop: Header=BB0_1 Depth=1
	movl	$3, %eax
	movl	%eax, %ecx
	movq	-16(%rbp), %rdx         ## 8-byte Reload
	imulq	%rcx, %rdx
	seto	%sil
	movq	%rdx, -40(%rbp)         ## 8-byte Spill
	movb	%sil, -41(%rbp)         ## 1-byte Spill
	jo	LBB0_6
	jmp	LBB0_7
LBB0_6:                                 ## %inlined._*_S.i64_S.i64.then.0.i
	ud2
LBB0_7:                                 ## %inlined._*_S.i64_S.i64._condFail_b.exit
                                        ##   in Loop: Header=BB0_1 Depth=1
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	callq	__$print_i64
	jmp	LBB0_3
LBB0_8:                                 ## %then.1
                                        ##   in Loop: Header=BB0_1 Depth=1
	movl	$1000000, %eax          ## imm = 0xF4240
	movl	%eax, %edi
	callq	__$print_i64
	jmp	LBB0_3
LBB0_9:                                 ## %else.2
                                        ##   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	callq	__$print_i64
	jmp	LBB0_3


.subsections_via_symbols
