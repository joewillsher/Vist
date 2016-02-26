	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:                                ## %foo_Eq_Int.exit191
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	subq	$184, %rsp
Ltmp3:
	.cfi_offset %rbx, -40
Ltmp4:
	.cfi_offset %r14, -32
Ltmp5:
	.cfi_offset %r15, -24
	movl	$2, %eax
	movl	%eax, %ecx
	movl	$17, %eax
	movl	%eax, %edi
	movq	%rcx, -96(%rbp)         ## 8-byte Spill
	callq	"_-Uprint_i64"
	movabsq	$34359738384, %rcx      ## imm = 0x800000010
	movq	%rcx, -80(%rbp)
	movl	-80(%rbp), %eax
	movl	%eax, -72(%rbp)
	movl	$8, -68(%rbp)
	leaq	_Bar.sum_(%rip), %rcx
	movq	%rcx, -88(%rbp)
	movq	%rcx, -64(%rbp)
	movq	$4, -32(%rbp)
	movq	$11, -40(%rbp)
	movb	$1, -48(%rbp)
	leaq	-48(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movq	-64(%rbp), %rdi
	movl	-72(%rbp), %eax
	movl	-68(%rbp), %edx
	movslq	%eax, %rsi
	movq	(%rcx,%rsi), %rsi
	movslq	%edx, %r8
	movq	-96(%rbp), %r9          ## 8-byte Reload
	imulq	(%rcx,%r8), %r9
	seto	%r10b
	movq	%r9, -104(%rbp)         ## 8-byte Spill
	movq	%rdi, -112(%rbp)        ## 8-byte Spill
	movq	%rsi, -120(%rbp)        ## 8-byte Spill
	movb	%r10b, -121(%rbp)       ## 1-byte Spill
	jo	LBB0_1
	jmp	LBB0_2
LBB0_1:                                 ## %inlined.-A_Int_Int.then.0.i.i
	ud2
LBB0_2:                                 ## %inlined.-A_Int_Int.condFail_b.exit.i
	movq	-104(%rbp), %rax        ## 8-byte Reload
	addq	$2, %rax
	seto	%cl
	movq	%rax, -136(%rbp)        ## 8-byte Spill
	movb	%cl, -137(%rbp)         ## 1-byte Spill
	jo	LBB0_3
	jmp	LBB0_4
LBB0_3:                                 ## %inlined.-P_Int_Int.then.0.i.i178
	ud2
LBB0_4:                                 ## %inlined.-P_Int_Int.condFail_b.exit.i
	movq	-120(%rbp), %rax        ## 8-byte Reload
	movq	-136(%rbp), %rcx        ## 8-byte Reload
	addq	%rcx, %rax
	seto	%dl
	movq	%rax, -152(%rbp)        ## 8-byte Spill
	movb	%dl, -153(%rbp)         ## 1-byte Spill
	jo	LBB0_5
	jmp	LBB0_6
LBB0_5:                                 ## %inlined.-P_Int_Int.then.0.i18.i
	ud2
LBB0_6:                                 ## %foo2_Eq_Int.exit
	movq	-152(%rbp), %rdi        ## 8-byte Reload
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
	movl	%r8d, -160(%rbp)        ## 4-byte Spill
	movl	%r9d, -164(%rbp)        ## 4-byte Spill
	callq	*%rdx
	addq	$2, %rax
	seto	%r10b
	movq	%rax, -176(%rbp)        ## 8-byte Spill
	movb	%r10b, -177(%rbp)       ## 1-byte Spill
	jo	LBB0_7
	jmp	LBB0_8
LBB0_7:                                 ## %inlined.-P_Int_Int.then.0.i.i
	ud2
LBB0_8:                                 ## %foo_Eq_Int.exit
	movq	-176(%rbp), %rdi        ## 8-byte Reload
	callq	"_-Uprint_i64"
	movl	$4, %eax
	movl	%eax, %edi
	movq	%rdi, -192(%rbp)        ## 8-byte Spill
	callq	"_-Uprint_i64"
	movl	$1, %eax
	movl	%eax, %edi
	callq	"_-Uprint_i64"
	movq	-192(%rbp), %rdi        ## 8-byte Reload
	callq	"_-Uprint_i64"
	movl	$7, %eax
	movl	%eax, %edi
	callq	"_-Uprint_i64"
	movl	$6, %eax
	movl	%eax, %edi
	callq	"_-Uprint_i64"
	movq	%rsp, %rdi
	movq	%rdi, %rcx
	addq	$-32, %rcx
	movq	%rcx, %rsp
	movb	$0, -8(%rdi)
	movq	$1, -16(%rdi)
	movq	$1, -24(%rdi)
	movb	$0, -32(%rdi)
	movb	$1, -32(%rdi)
	movl	$1, %eax
	movq	%rdi, -200(%rbp)        ## 8-byte Spill
	movl	%eax, %edi
	callq	"_-Uprint_b"
	movq	%rsp, %rcx
	movq	%rcx, %rdx
	addq	$-16, %rdx
	movq	%rdx, %rsp
	movq	$2, -16(%rcx)
	movq	$2, -8(%rcx)
	movq	-16(%rcx), %rcx
	movq	-200(%rbp), %rdx        ## 8-byte Reload
	movb	-32(%rdx), %sil
	movq	-24(%rdx), %r8
	movq	-16(%rdx), %r9
	movb	-8(%rdx), %r10b
	movq	%rsp, %r11
	movq	%r11, %rbx
	addq	$-64, %rbx
	movq	%rbx, %rsp
	movq	$1, -64(%r11)
	movq	%rcx, -56(%r11)
	movq	$2, -48(%r11)
	movb	%r10b, -16(%r11)
	movq	%r9, -24(%r11)
	movq	%r8, -32(%r11)
	movb	%sil, -40(%r11)
	movq	-64(%r11), %rcx
	movq	-56(%r11), %r8
	movq	-48(%r11), %r9
	movb	-40(%r11), %sil
	movq	-32(%r11), %rbx
	movq	-24(%r11), %r14
	movb	-16(%r11), %r10b
	movq	%rsp, %r11
	movq	%r11, %r15
	addq	$-64, %r15
	movq	%r15, %rsp
	movb	%r10b, -16(%r11)
	movq	%r14, -24(%r11)
	movq	%rbx, -32(%r11)
	movb	%sil, -40(%r11)
	movq	%r9, -48(%r11)
	movq	%r8, -56(%r11)
	movq	%rcx, -64(%r11)
	movq	$2, -64(%r11)
	movq	%rsp, %rcx
	movq	%rcx, %r8
	addq	$-16, %r8
	movq	%r8, %rsp
	movq	$1, -16(%rcx)
	movq	$1, -8(%rcx)
	movq	-16(%rcx), %rcx
	movq	%rcx, -56(%r11)
	movq	$1, -48(%r11)
	movq	-64(%r11), %rdi
	movq	%r11, -208(%rbp)        ## 8-byte Spill
	callq	"_-Uprint_i64"
	movq	-208(%rbp), %rcx        ## 8-byte Reload
	movq	$4, -48(%rcx)
	movl	$4, %eax
	movl	%eax, %edi
	leaq	-24(%rbp), %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
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

	.globl	_Foo_Bar_Bool
	.align	4, 0x90
_Foo_Bar_Bool:                          ## @Foo_Bar_Bool
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%sil, %al
	movb	%r8b, %r9b
	movq	%rdi, %r10
	andb	$1, %r9b
	movb	%r9b, 24(%rdi)
	movq	%rdx, 8(%rdi)
	andb	$1, %al
	movb	%al, (%rdi)
	movq	%rcx, 16(%rdi)
	movq	%r10, %rax
	popq	%rbp
	retq


.subsections_via_symbols
