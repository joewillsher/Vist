	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$272, %rsp              ## imm = 0x110
	xorl	%esi, %esi
	movl	$24, %eax
	movl	%eax, %edx
	leaq	l_.str(%rip), %rcx
	leaq	-208(%rbp), %rdi
	movq	%rdi, -176(%rbp)
	movq	%rcx, -184(%rbp)
	movq	-176(%rbp), %rcx
	movq	-184(%rbp), %rdi
	movq	%rcx, -160(%rbp)
	movq	%rdi, -168(%rbp)
	movq	-160(%rbp), %rcx
	movq	%rcx, -152(%rbp)
	movq	-152(%rbp), %rdi
	movq	%rdi, -144(%rbp)
	movq	-144(%rbp), %rdi
	movq	%rdi, -136(%rbp)
	movq	-136(%rbp), %rdi
	movq	%rdi, %r8
	movq	%r8, -128(%rbp)
	movq	%rcx, -232(%rbp)        ## 8-byte Spill
	callq	_memset
	movq	-168(%rbp), %rsi
	movq	-168(%rbp), %rcx
	movq	%rcx, -112(%rbp)
	movq	$0, -120(%rbp)
	movq	%rsi, -240(%rbp)        ## 8-byte Spill
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%esi, %esi
	movq	-112(%rbp), %rax
	movzwl	(%rax), %edi
	callq	__ZNSt3__111char_traitsIDsE2eqEDsDs
	xorb	$-1, %al
	testb	$1, %al
	jne	LBB0_2
	jmp	LBB0_3
LBB0_2:                                 ##   in Loop: Header=BB0_1 Depth=1
	movq	-120(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -120(%rbp)
	movq	-112(%rbp), %rax
	addq	$2, %rax
	movq	%rax, -112(%rbp)
	jmp	LBB0_1
LBB0_3:                                 ## %_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEEC1EPKDs.exit
	movq	-120(%rbp), %rdx
	movq	-232(%rbp), %rdi        ## 8-byte Reload
	movq	-240(%rbp), %rsi        ## 8-byte Reload
	callq	__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEE6__initEPKDsm
	leaq	-208(%rbp), %rdx
	movq	%rdx, -104(%rbp)
	movq	-104(%rbp), %rdx
	movq	%rdx, -96(%rbp)
	movq	-96(%rbp), %rdx
	movq	%rdx, -88(%rbp)
	movq	-88(%rbp), %rsi
	movq	%rsi, -80(%rbp)
	movq	-80(%rbp), %rsi
	movq	%rsi, -72(%rbp)
	movq	-72(%rbp), %rsi
	movzbl	(%rsi), %eax
	andl	$1, %eax
	cmpl	$0, %eax
	movq	%rdx, -248(%rbp)        ## 8-byte Spill
	je	LBB0_5
## BB#4:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -256(%rbp)        ## 8-byte Spill
	jmp	LBB0_6
LBB0_5:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	addq	$2, %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -256(%rbp)        ## 8-byte Spill
LBB0_6:                                 ## %_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEE5frontEv.exit
	movq	-256(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -264(%rbp)        ## 8-byte Spill
## BB#7:
	movq	-264(%rbp), %rax        ## 8-byte Reload
	movzwl	(%rax), %esi
Ltmp0:
	leaq	L_.str.1(%rip), %rdi
	xorl	%ecx, %ecx
	movb	%cl, %dl
	movb	%dl, %al
	callq	_printf
Ltmp1:
	movl	%eax, -268(%rbp)        ## 4-byte Spill
	jmp	LBB0_8
LBB0_8:
	leaq	-208(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED1Ev
	xorl	%eax, %eax
	addq	$272, %rsp              ## imm = 0x110
	popq	%rbp
	retq
LBB0_9:
Ltmp2:
	leaq	-208(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -216(%rbp)
	movl	%ecx, -220(%rbp)
	callq	__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED1Ev
## BB#10:
	movq	-216(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.align	2
GCC_except_table0:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset0 = Lfunc_begin0-Lfunc_begin0       ## >> Call Site 1 <<
	.long	Lset0
Lset1 = Ltmp0-Lfunc_begin0              ##   Call between Lfunc_begin0 and Ltmp0
	.long	Lset1
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset2 = Ltmp0-Lfunc_begin0              ## >> Call Site 2 <<
	.long	Lset2
Lset3 = Ltmp1-Ltmp0                     ##   Call between Ltmp0 and Ltmp1
	.long	Lset3
Lset4 = Ltmp2-Lfunc_begin0              ##     jumps to Ltmp2
	.long	Lset4
	.byte	0                       ##   On action: cleanup
Lset5 = Ltmp1-Lfunc_begin0              ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Lfunc_end0-Ltmp1                ##   Call between Ltmp1 and Lfunc_end0
	.long	Lset6
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.align	2

	.section	__TEXT,__textcoal_nt,coalesced,pure_instructions
	.globl	__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED1Ev
	.align	4, 0x90
__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED1Ev: ## @_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED2Ev
	.align	4, 0x90
__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED2Ev: ## @_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	subq	$176, %rsp
	movq	%rdi, -160(%rbp)
	movq	-160(%rbp), %rdi
	movq	%rdi, -152(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -144(%rbp)
	movq	-144(%rbp), %rax
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rax
	movzbl	(%rax), %ecx
	andl	$1, %ecx
	cmpl	$0, %ecx
	movq	%rdi, -168(%rbp)        ## 8-byte Spill
	je	LBB2_2
## BB#1:
	movq	-168(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	16(%rdx), %rdx
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rsi
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rsi
	movq	(%rsi), %rsi
	andq	$-2, %rsi
	movq	%rcx, -112(%rbp)
	movq	%rdx, -120(%rbp)
	movq	%rsi, -128(%rbp)
	movq	-112(%rbp), %rcx
	movq	-120(%rbp), %rdx
	movq	-128(%rbp), %rsi
	movq	%rcx, -88(%rbp)
	movq	%rdx, -96(%rbp)
	movq	%rsi, -104(%rbp)
	movq	-96(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rdi
	callq	__ZdlPv
LBB2_2:
	addq	$176, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.private_extern	___clang_call_terminate
	.globl	___clang_call_terminate
	.weak_def_can_be_hidden	___clang_call_terminate
	.align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## BB#0:
	pushq	%rax
	callq	___cxa_begin_catch
	movq	%rax, (%rsp)            ## 8-byte Spill
	callq	__ZSt9terminatev

	.globl	__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEE6__initEPKDsm
	.weak_def_can_be_hidden	__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEE6__initEPKDsm
	.align	4, 0x90
__ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEE6__initEPKDsm: ## @_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEE6__initEPKDsm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$448, %rsp              ## imm = 0x1C0
	movabsq	$9223372036854775807, %rax ## imm = 0x7FFFFFFFFFFFFFFF
	movq	%rdi, -392(%rbp)
	movq	%rsi, -400(%rbp)
	movq	%rdx, -408(%rbp)
	movq	-392(%rbp), %rdx
	movq	-408(%rbp), %rsi
	movq	%rdx, -376(%rbp)
	movq	-376(%rbp), %rdi
	movq	%rdi, -368(%rbp)
	movq	-368(%rbp), %rdi
	movq	%rdi, -360(%rbp)
	movq	-360(%rbp), %rdi
	movq	%rdi, -352(%rbp)
	movq	-352(%rbp), %rdi
	movq	%rdi, -328(%rbp)
	movq	-328(%rbp), %rdi
	movq	%rdi, -320(%rbp)
	movq	-320(%rbp), %rdi
	movq	%rdi, -304(%rbp)
	movq	%rax, -384(%rbp)
	movq	-384(%rbp), %rax
	subq	$16, %rax
	cmpq	%rax, %rsi
	movq	%rdx, -440(%rbp)        ## 8-byte Spill
	jbe	LBB4_2
## BB#1:
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZNKSt3__121__basic_string_commonILb1EE20__throw_length_errorEv
LBB4_2:
	cmpq	$11, -408(%rbp)
	jae	LBB4_4
## BB#3:
	movq	-408(%rbp), %rax
	movq	-440(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -288(%rbp)
	movq	%rax, -296(%rbp)
	movq	-288(%rbp), %rax
	movq	-296(%rbp), %rdx
	shlq	$1, %rdx
	movb	%dl, %sil
	movq	%rax, -280(%rbp)
	movq	-280(%rbp), %rax
	movq	%rax, -272(%rbp)
	movq	-272(%rbp), %rax
	movb	%sil, (%rax)
	movq	%rcx, -232(%rbp)
	movq	-232(%rbp), %rax
	movq	%rax, -224(%rbp)
	movq	-224(%rbp), %rax
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rax
	addq	$2, %rax
	movq	%rax, -208(%rbp)
	movq	-208(%rbp), %rax
	movq	%rax, -200(%rbp)
	movq	-200(%rbp), %rax
	movq	%rax, -416(%rbp)
	jmp	LBB4_8
LBB4_4:
	movq	-408(%rbp), %rax
	movq	%rax, -40(%rbp)
	cmpq	$11, -40(%rbp)
	jae	LBB4_6
## BB#5:
	movl	$11, %eax
	movl	%eax, %ecx
	movq	%rcx, -448(%rbp)        ## 8-byte Spill
	jmp	LBB4_7
LBB4_6:
	movq	-40(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	addq	$7, %rax
	andq	$-8, %rax
	movq	%rax, -448(%rbp)        ## 8-byte Spill
LBB4_7:                                 ## %_ZNSt3__112basic_stringIDsNS_11char_traitsIDsEENS_9allocatorIDsEEE11__recommendEm.exit
	movq	-448(%rbp), %rax        ## 8-byte Reload
	subq	$1, %rax
	movq	%rax, -424(%rbp)
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	-424(%rbp), %rdx
	addq	$1, %rdx
	movq	%rcx, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	-80(%rbp), %rcx
	movq	-88(%rbp), %rdx
	movq	%rcx, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	$0, -72(%rbp)
	movq	-64(%rbp), %rcx
	shlq	$1, %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rdi
	callq	__Znwm
	movq	%rax, -416(%rbp)
	movq	-416(%rbp), %rax
	movq	-440(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -112(%rbp)
	movq	%rax, -120(%rbp)
	movq	-112(%rbp), %rax
	movq	-120(%rbp), %rdx
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	-424(%rbp), %rax
	addq	$1, %rax
	movq	%rcx, -144(%rbp)
	movq	%rax, -152(%rbp)
	movq	-144(%rbp), %rax
	movq	-152(%rbp), %rdx
	orq	$1, %rdx
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, -128(%rbp)
	movq	-128(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-408(%rbp), %rax
	movq	%rcx, -176(%rbp)
	movq	%rax, -184(%rbp)
	movq	-176(%rbp), %rax
	movq	-184(%rbp), %rdx
	movq	%rax, -168(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rax
	movq	%rdx, 8(%rax)
LBB4_8:
	movq	-416(%rbp), %rax
	movq	%rax, -192(%rbp)
	movq	-192(%rbp), %rax
	movq	-400(%rbp), %rcx
	movq	-408(%rbp), %rdx
	movq	%rax, -240(%rbp)
	movq	%rcx, -248(%rbp)
	movq	%rdx, -256(%rbp)
	movq	-240(%rbp), %rax
	movq	%rax, -264(%rbp)
LBB4_9:                                 ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -256(%rbp)
	je	LBB4_11
## BB#10:                               ##   in Loop: Header=BB4_9 Depth=1
	movq	-240(%rbp), %rdi
	movq	-248(%rbp), %rsi
	callq	__ZNSt3__111char_traitsIDsE6assignERDsRKDs
	movq	-256(%rbp), %rsi
	addq	$-1, %rsi
	movq	%rsi, -256(%rbp)
	movq	-240(%rbp), %rsi
	addq	$2, %rsi
	movq	%rsi, -240(%rbp)
	movq	-248(%rbp), %rsi
	addq	$2, %rsi
	movq	%rsi, -248(%rbp)
	jmp	LBB4_9
LBB4_11:                                ## %_ZNSt3__111char_traitsIDsE4copyEPDsPKDsm.exit
	leaq	-426(%rbp), %rsi
	movq	-408(%rbp), %rax
	shlq	$1, %rax
	addq	-416(%rbp), %rax
	movw	$0, -426(%rbp)
	movq	%rax, %rdi
	callq	__ZNSt3__111char_traitsIDsE6assignERDsRKDs
	addq	$448, %rsp              ## imm = 0x1C0
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__111char_traitsIDsE6assignERDsRKDs
	.weak_def_can_be_hidden	__ZNSt3__111char_traitsIDsE6assignERDsRKDs
	.align	4, 0x90
__ZNSt3__111char_traitsIDsE6assignERDsRKDs: ## @_ZNSt3__111char_traitsIDsE6assignERDsRKDs
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp15:
	.cfi_def_cfa_offset 16
Ltmp16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp17:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movw	(%rsi), %ax
	movq	-8(%rbp), %rsi
	movw	%ax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__111char_traitsIDsE2eqEDsDs
	.weak_def_can_be_hidden	__ZNSt3__111char_traitsIDsE2eqEDsDs
	.align	4, 0x90
__ZNSt3__111char_traitsIDsE2eqEDsDs:    ## @_ZNSt3__111char_traitsIDsE2eqEDsDs
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp18:
	.cfi_def_cfa_offset 16
Ltmp19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp20:
	.cfi_def_cfa_register %rbp
	movw	%si, %ax
	movw	%di, %cx
	movw	%cx, -2(%rbp)
	movw	%ax, -4(%rbp)
	movzwl	-2(%rbp), %esi
	movzwl	-4(%rbp), %edi
	cmpl	%edi, %esi
	sete	%dl
	andb	$1, %dl
	movzbl	%dl, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__ustring
	.align	1                       ## @.str
l_.str:
	.short	97                      ## 0x61
	.short	97                      ## 0x61
	.short	55358                   ## 0xd83e
	.short	56596                   ## 0xdd14
	.short	0                       ## 0x0

	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	"%s"


.subsections_via_symbols
