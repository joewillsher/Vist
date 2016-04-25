	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main.loop_thunk
	.align	4, 0x90
_main.loop_thunk:                       ## @main.loop_thunk
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movl	$3, %eax
	movl	%eax, %ecx
	movq	%rdi, %rax
	cqto
	idivq	%rcx
	cmpq	$0, %rdx
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	jne	LBB0_4
## BB#1:                                ## %if.0
	movl	$3, %eax
	movl	%eax, %ecx
	movq	-8(%rbp), %rdx          ## 8-byte Reload
	imulq	%rcx, %rdx
	seto	%sil
	movq	%rdx, -16(%rbp)         ## 8-byte Spill
	movb	%sil, -17(%rbp)         ## 1-byte Spill
	jo	LBB0_3
## BB#2:                                ## %i.-A_tII.entry.cont
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	callq	"_vist-Uprint_ti64"
	jmp	LBB0_7
LBB0_3:                                 ## %i.-A_tII.*.trap
	ud2
LBB0_4:                                 ## %fail.0
	movl	$1000, %eax             ## imm = 0x3E8
	movl	%eax, %ecx
	movq	-8(%rbp), %rax          ## 8-byte Reload
	cqto
	idivq	%rcx
	cmpq	$0, %rdx
	jne	LBB0_6
## BB#5:                                ## %if.1
	movl	$1000000, %eax          ## imm = 0xF4240
	movl	%eax, %edi
	callq	"_vist-Uprint_ti64"
	jmp	LBB0_7
LBB0_6:                                 ## %else.2
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	callq	"_vist-Uprint_ti64"
LBB0_7:                                 ## %exit
	addq	$32, %rsp
	popq	%rbp
	retq

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
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
	leaq	_main.loop_thunk(%rip), %rdx
	xorl	%eax, %eax
	movl	%eax, %edi
	movl	$5000, %eax             ## imm = 0x1388
	movl	%eax, %esi
	popq	%rbp
	jmp	_generate_mRPtI         ## TAILCALL
	.cfi_endproc


.subsections_via_symbols
