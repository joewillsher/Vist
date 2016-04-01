	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_foo_tEqInt
	.align	4, 0x90
_foo_tEqInt:                            ## @foo_tEqInt
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	%edi, -4(%rbp)          ## 4-byte Spill
	movq	%rcx, %rdi
	movq	%r8, -16(%rbp)          ## 8-byte Spill
	movl	%esi, -20(%rbp)         ## 4-byte Spill
	callq	*%rdx
	movq	-16(%rbp), %rcx         ## 8-byte Reload
	addq	%rcx, %rax
	seto	%r9b
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	movb	%r9b, -33(%rbp)         ## 1-byte Spill
	jo	LBB0_2
## BB#1:                                ## %i.-P_tIntInt.entry.cont
	movq	-32(%rbp), %rax         ## 8-byte Reload
	addq	$48, %rsp
	popq	%rbp
	retq
LBB0_2:                                 ## %i.-P_tIntInt.+.trap
	ud2
	.cfi_endproc

	.globl	_foo2_tEqInt
	.align	4, 0x90
_foo2_tEqInt:                           ## @foo2_tEqInt
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	movl	$2, %eax
	movl	%eax, %r9d
	movslq	%edi, %r10
	movq	(%rcx,%r10), %r10
	movslq	%esi, %r11
	imulq	(%rcx,%r11), %r9
	seto	%bl
	movq	%r8, -16(%rbp)          ## 8-byte Spill
	movq	%r10, -24(%rbp)         ## 8-byte Spill
	movq	%r9, -32(%rbp)          ## 8-byte Spill
	movq	%rdx, -40(%rbp)         ## 8-byte Spill
	movb	%bl, -41(%rbp)          ## 1-byte Spill
	jo	LBB1_6
## BB#1:                                ## %i.-A_tIntInt.entry.cont
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	-16(%rbp), %rcx         ## 8-byte Reload
	addq	%rcx, %rax
	seto	%dl
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	movb	%dl, -57(%rbp)          ## 1-byte Spill
	jo	LBB1_5
## BB#2:                                ## %i.-P_tIntInt.entry.cont
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	-56(%rbp), %rcx         ## 8-byte Reload
	addq	%rcx, %rax
	seto	%dl
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movb	%dl, -73(%rbp)          ## 1-byte Spill
	jo	LBB1_4
## BB#3:                                ## %i.-P_tIntInt.entry.cont9
	movq	-72(%rbp), %rax         ## 8-byte Reload
	popq	%rbx
	popq	%rbp
	retq
LBB1_4:                                 ## %i.-P_tIntInt.+.trap12
	ud2
LBB1_5:                                 ## %i.-P_tIntInt.+.trap
	ud2
LBB1_6:                                 ## %i.-A_tIntInt.*.trap
	ud2

	.globl	_Bar_tBoolIntInt
	.align	4, 0x90
_Bar_tBoolIntInt:                       ## @Bar_tBoolIntInt
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	movq	%rdx, -8(%rbp)          ## 8-byte Spill
	movq	%rsi, %rdx
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	popq	%rbp
	retq

	.globl	_Baz_tIntInt
	.align	4, 0x90
_Baz_tIntInt:                           ## @Baz_tIntInt
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq

	.globl	_sum_mBar
	.align	4, 0x90
_sum_mBar:                              ## @sum_mBar
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	16(%rdi), %rax
	addq	8(%rdi), %rax
	seto	%cl
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	movb	%cl, -9(%rbp)           ## 1-byte Spill
	jo	LBB4_2
## BB#1:                                ## %i.-P_tIntInt.entry.cont
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq
LBB4_2:                                 ## %i.-P_tIntInt.+.trap
	ud2

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:                                ## %foo_tEqInt.exit27
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$160, %rsp
	movl	$2, %eax
	movl	%eax, %ecx
	movl	$17, %eax
	movl	%eax, %edi
	movq	%rcx, -72(%rbp)         ## 8-byte Spill
	callq	"_vist-Uprint_ti64"
	movabsq	$34359738384, %rcx      ## imm = 0x800000010
	movq	%rcx, -56(%rbp)
	movl	-56(%rbp), %eax
	movl	%eax, -48(%rbp)
	movl	$8, -44(%rbp)
	leaq	_sum_mBar(%rip), %rcx
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
	jo	LBB5_5
## BB#1:                                ## %i.-A_tIntInt.entry.cont.i
	movq	-80(%rbp), %rax         ## 8-byte Reload
	addq	$2, %rax
	seto	%cl
	movq	%rax, -112(%rbp)        ## 8-byte Spill
	movb	%cl, -113(%rbp)         ## 1-byte Spill
	jo	LBB5_4
## BB#2:                                ## %i.-P_tIntInt.entry.cont.i
	movq	-96(%rbp), %rax         ## 8-byte Reload
	movq	-112(%rbp), %rcx        ## 8-byte Reload
	addq	%rcx, %rax
	seto	%dl
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	movb	%dl, -129(%rbp)         ## 1-byte Spill
	jo	LBB5_3
	jmp	LBB5_6
LBB5_3:                                 ## %i.-P_tIntInt.+.trap12.i
	ud2
LBB5_4:                                 ## %i.-P_tIntInt.+.trap.i21
	ud2
LBB5_5:                                 ## %i.-A_tIntInt.*.trap.i
	ud2
LBB5_6:                                 ## %foo2_tEqInt.exit
	movq	-128(%rbp), %rdi        ## 8-byte Reload
	callq	"_vist-Uprint_ti64"
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
	leaq	_sum_mBaz(%rip), %rsi
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
	jo	LBB5_7
	jmp	LBB5_8
LBB5_7:                                 ## %i.-P_tIntInt.+.trap.i
	ud2
LBB5_8:                                 ## %foo_tEqInt.exit
	movq	-152(%rbp), %rax        ## 8-byte Reload
	movq	%rax, %rdi
	movq	%rbp, %rsp
	popq	%rbp
	jmp	"_vist-Uprint_ti64"     ## TAILCALL
	.cfi_endproc

	.globl	_sum_mBaz
	.align	4, 0x90
_sum_mBaz:                              ## @sum_mBaz
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, %eax
                                        ## kill: RAX<def> EAX<kill>
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	popq	%rbp
	retq


.subsections_via_symbols
