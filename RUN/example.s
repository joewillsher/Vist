	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
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
	subq	$16, %rsp
	movl	$1, %eax
	movl	%eax, %ecx
	movq	%rcx, %rdi
	movq	%rcx, -8(%rbp)          ## 8-byte Spill
	callq	"_-Uprint_i64"
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	callq	_Int_i64
	movq	%rax, %rdi
	callq	"_-Uprint_i64"
	movl	$10, %edx
	movl	%edx, %edi
	callq	_factorial_Int
	movq	%rax, %rdi
	callq	"_-Uprint_i64"
	movl	$4, %edx
	movl	%edx, %eax
	movq	%rax, %rdi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	callq	_factorial_Int
	movq	%rax, %rdi
	callq	"_-Uprint_i64"
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	callq	_factorial_Int
	movq	%rax, %rdi
	callq	"_-Uprint_i64"
	movl	$3, %edx
	movl	%edx, %edi
	callq	_factorial_Int
	movq	%rax, %rdi
	callq	_factorial_Int
	movq	%rax, %rdi
	callq	"_-Uprint_i64"
	movl	$41, %edx
	movl	%edx, %edi
	callq	"_-Uprint_i64"
	movl	$2, %edx
	movl	%edx, %edi
	callq	"_-Uprint_i64"
	movl	$100, %edx
	movl	%edx, %edi
	callq	"_-Uprint_i64"
	movl	$11, %edx
	movl	%edx, %edi
	callq	"_-Uprint_i64"
	movl	$20, %edx
	movl	%edx, %edi
	addq	$16, %rsp
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL
	.cfi_endproc

	.globl	_Foo_Int
	.align	4, 0x90
_Foo_Int:                               ## @Foo_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_Bar_TestC
	.align	4, 0x90
_Bar_TestC:                             ## @Bar_TestC
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, %eax
	movq	%rsi, %rdx
	popq	%rbp
	retq

	.align	4, 0x90
_factorial_Int:                         ## @factorial_Int
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
	movl	$1, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rcx, %rdi
	callq	_Int_i64
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	cmpq	$2, %rcx
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	jge	LBB3_2
## BB#1:                                ## %then.0
	movq	-16(%rbp), %rax         ## 8-byte Reload
	addq	$48, %rsp
	popq	%rbp
	retq
LBB3_2:                                 ## %else.1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	-16(%rbp), %rcx         ## 8-byte Reload
	subq	%rcx, %rax
	seto	%dl
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	movb	%dl, -25(%rbp)          ## 1-byte Spill
	jo	LBB3_3
	jmp	LBB3_4
LBB3_3:                                 ## %inlined.-M_Int_Int.then.0.i
	ud2
LBB3_4:                                 ## %inlined.-M_Int_Int.condFail_b.exit
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	_factorial_Int
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	imulq	%rax, %rdi
	seto	%cl
	movq	%rdi, -40(%rbp)         ## 8-byte Spill
	movb	%cl, -41(%rbp)          ## 1-byte Spill
	jo	LBB3_5
	jmp	LBB3_6
LBB3_5:                                 ## %inlined.-A_Int_Int.then.0.i
	ud2
LBB3_6:                                 ## %inlined.-A_Int_Int.condFail_b.exit
	movq	-40(%rbp), %rax         ## 8-byte Reload
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
