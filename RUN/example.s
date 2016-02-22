	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %foo_Eq_Int.exit
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$144, %rsp
	movl	$2, %eax
	movl	%eax, %ecx
	movl	$17, %eax
	movl	%eax, %edi
	movq	%rcx, -72(%rbp)         ## 8-byte Spill
	callq	"_-Uprint_i64"
	movabsq	$34359738384, %rcx      ## imm = 0x800000010
	movq	%rcx, -56(%rbp)
	movl	-56(%rbp), %eax
	movl	%eax, -48(%rbp)
	movl	$8, -44(%rbp)
	leaq	_Bar.sum_(%rip), %rcx
	movq	%rcx, -64(%rbp)
	movq	%rcx, -40(%rbp)
	movq	$4, -8(%rbp)
	movq	$11, -16(%rbp)
	movb	$1, -24(%rbp)
	leaq	-24(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-40(%rbp), %rdi
	movl	-48(%rbp), %eax
	movl	-44(%rbp), %edx
	movslq	%eax, %rsi
	movq	(%rcx,%rsi), %rsi
	movslq	%edx, %r8
	movq	-72(%rbp), %r9          ## 8-byte Reload
	imulq	(%rcx,%r8), %r9
	seto	%r10b
	movq	%r9, -80(%rbp)          ## 8-byte Spill
	movq	%rdi, -88(%rbp)         ## 8-byte Spill
	movq	%rsi, -96(%rbp)         ## 8-byte Spill
	movb	%r10b, -97(%rbp)        ## 1-byte Spill
	jo	LBB0_1
	jmp	LBB0_2
LBB0_1:                                 ## %inlined.-A_Int_Int.then.0.i.i
	ud2
LBB0_2:                                 ## %inlined.-A_Int_Int.condFail_b.exit.i
	movq	-80(%rbp), %rax         ## 8-byte Reload
	addq	$2, %rax
	seto	%cl
	movq	%rax, -112(%rbp)        ## 8-byte Spill
	movb	%cl, -113(%rbp)         ## 1-byte Spill
	jo	LBB0_3
	jmp	LBB0_4
LBB0_3:                                 ## %inlined.-P_Int_Int.then.0.i.i
	ud2
LBB0_4:                                 ## %inlined.-P_Int_Int.condFail_b.exit.i
	movq	-96(%rbp), %rax         ## 8-byte Reload
	movq	-112(%rbp), %rcx        ## 8-byte Reload
	addq	%rcx, %rax
	seto	%dl
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	movb	%dl, -129(%rbp)         ## 1-byte Spill
	jo	LBB0_5
	jmp	LBB0_6
LBB0_5:                                 ## %inlined.-P_Int_Int.then.0.i20.i
	ud2
LBB0_6:                                 ## %foo2_Eq_Int.exit
	movq	-128(%rbp), %rax        ## 8-byte Reload
	movq	%rax, %rdi
	addq	$144, %rsp
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL

	.globl	_Bar_Bool_Int_Int
	.align	4, 0x90
_Bar_Bool_Int_Int:                      ## @Bar_Bool_Int_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	movq	%rdx, -8(%rbp)          ## 8-byte Spill
	movq	%rsi, %rdx
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	popq	%rbp
	retq

	.align	4, 0x90
_Bar.sum_:                              ## @Bar.sum_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	16(%rdi), %rax
	addq	8(%rdi), %rax
	seto	%cl
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	movb	%cl, -9(%rbp)           ## 1-byte Spill
	jo	LBB2_1
	jmp	LBB2_2
LBB2_1:                                 ## %inlined.-P_Int_Int.then.0.i
	ud2
LBB2_2:                                 ## %inlined.-P_Int_Int.condFail_b.exit
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq


.subsections_via_symbols
