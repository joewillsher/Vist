	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_HalfOpenRange_tII
	.align	4, 0x90
_HalfOpenRange_tII:                     ## @HalfOpenRange_tII
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq

	.globl	_main.loop_thunk
	.align	4, 0x90
_main.loop_thunk:                       ## @main.loop_thunk
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
	subq	$16, %rsp
	movq	_a.globlstorage(%rip), %rax
	movq	(%rax), %rsi
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	callq	"_-A_tII"
	movq	%rax, %rsi
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	movq	%rax, (%rdi)
	movq	%rsi, %rdi
	addq	$16, %rsp
	popq	%rbp
	jmp	_print_tI               ## TAILCALL
	.cfi_endproc

	.globl	_generate_mHalfOpenRangePtI
	.align	4, 0x90
_generate_mHalfOpenRangePtI:            ## @generate_mHalfOpenRangePtI
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rsi, -16(%rbp)         ## 8-byte Spill
	movq	%rdx, -24(%rbp)         ## 8-byte Spill
	callq	"_-L_tII"
	testb	$1, %al
	jne	LBB2_1
	jmp	LBB2_4
LBB2_1:                                 ## %loop.preheader
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	jmp	LBB2_2
LBB2_2:                                 ## %loop
                                        ## =>This Inner Loop Header: Depth=1
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	movq	%rax, -40(%rbp)         ## 8-byte Spill
	callq	*%rcx
	movl	$1, %edx
	movl	%edx, %esi
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	callq	"_-P_tII"
	movq	%rax, %rcx
	movq	%rax, %rdi
	movq	-16(%rbp), %rsi         ## 8-byte Reload
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	callq	"_-L_tII"
	testb	$1, %al
	movq	-48(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	jne	LBB2_2
	jmp	LBB2_3
LBB2_3:                                 ## %loop.exit.loopexit
	jmp	LBB2_4
LBB2_4:                                 ## %loop.exit
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	$1, -8(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, _a.globlstorage(%rip)
	movl	$1, %ecx
	movl	%ecx, %edi
	movl	$10, %ecx
	movl	%ecx, %esi
	callq	"_-D-D-D_tII"
	leaq	_main.loop_thunk(%rip), %rsi
	movq	%rax, %rdi
	movq	%rsi, -16(%rbp)         ## 8-byte Spill
	movq	%rdx, %rsi
	movq	-16(%rbp), %rdx         ## 8-byte Reload
	callq	_generate_mRPtI
	leaq	L___unnamed_1(%rip), %rdi
	movl	$4, %ecx
	movl	%ecx, %esi
	movl	$1, %edx
	callq	_String_topi64b
	movq	%rax, %rdi
	movq	%rdx, %rsi
	movq	%rcx, %rdx
	callq	_print_tString
	movq	-8(%rbp), %rdi
	callq	_print_tI
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_a.globlstorage         ## @a.globlstorage
.zerofill __DATA,__common,_a.globlstorage,8,3
	.section	__TEXT,__cstring,cstring_literals
L___unnamed_1:                          ## @0
	.asciz	"out"


.subsections_via_symbols
