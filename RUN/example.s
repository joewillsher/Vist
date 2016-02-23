	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:                                ## %foo_Eq_Int.exit131
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$176, %rsp
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
LBB0_3:                                 ## %inlined.-P_Int_Int.then.0.i.i118
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
	movq	-128(%rbp), %rdi        ## 8-byte Reload
	callq	"_-Uprint_i64"
	movq	%rsp, %rdi
	movq	%rdi, %rax
	addq	$-16, %rax
	movq	%rax, %rsp
	movq	%rsp, %rcx
	movq	%rcx, %rdx
	addq	$-32, %rdx
	movq	%rdx, %rsp
	movq	%rsp, %rdx
	movq	%rdx, %rsi
	addq	$-16, %rsi
	movq	%rsi, %rsp
	movabsq	$34359738368, %rsi      ## imm = 0x800000000
	movq	%rsi, -16(%rdx)
	movl	-16(%rdx), %r8d
	movl	%r8d, -32(%rcx)
	movl	$8, -28(%rcx)
	movq	%rsp, %rdx
	movq	%rdx, %rsi
	addq	$-16, %rsi
	movq	%rsi, %rsp
	leaq	_Baz.sum_(%rip), %rsi
	movq	%rsi, -16(%rdx)
	movq	%rsi, -24(%rcx)
	movq	$3, -8(%rdi)
	movq	$2, -16(%rdi)
	movq	%rax, -16(%rcx)
	movq	-24(%rcx), %rdx
	movl	-32(%rcx), %r8d
	movl	-28(%rcx), %r9d
	movq	%rax, %rdi
	movl	%r8d, -136(%rbp)        ## 4-byte Spill
	movl	%r9d, -140(%rbp)        ## 4-byte Spill
	callq	*%rdx
	addq	$2, %rax
	seto	%r10b
	movq	%rax, -152(%rbp)        ## 8-byte Spill
	movb	%r10b, -153(%rbp)       ## 1-byte Spill
	jo	LBB0_7
	jmp	LBB0_8
LBB0_7:                                 ## %inlined.-P_Int_Int.then.0.i.i
	ud2
LBB0_8:                                 ## %foo_Eq_Int.exit
	movq	-152(%rbp), %rdi        ## 8-byte Reload
	callq	"_-Uprint_i64"
	movl	$4, %eax
	movl	%eax, %edi
	movq	%rdi, -168(%rbp)        ## 8-byte Spill
	callq	"_-Uprint_i64"
	movl	$1, %eax
	movl	%eax, %edi
	callq	"_-Uprint_i64"
	movq	-168(%rbp), %rdi        ## 8-byte Reload
	callq	"_-Uprint_i64"
	movl	$7, %eax
	movl	%eax, %edi
	callq	"_-Uprint_i64"
	movl	$6, %eax
	movl	%eax, %edi
	movq	%rbp, %rsp
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL
	.cfi_endproc

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

	.globl	_Baz_Int_Int
	.align	4, 0x90
_Baz_Int_Int:                           ## @Baz_Int_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq

	.align	4, 0x90
_Baz.sum_:                              ## @Baz.sum_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, %eax
                                        ## kill: RAX<def> EAX<kill>
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	popq	%rbp
	retq


.subsections_via_symbols
