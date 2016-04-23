	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
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

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
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
	movq	-8(%rbp), %rdi
	callq	_print_tI
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_a.globlstorage         ## @a.globlstorage
.zerofill __DATA,__common,_a.globlstorage,8,3

.subsections_via_symbols
