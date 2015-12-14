	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_printStr
	.align	4, 0x90
_printStr:                              ## @printStr
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_print
	.align	4, 0x90
_print:                                 ## @print
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, %rcx
	movq	%rcx, -8(%rbp)
	leaq	L_.str1(%rip), %rdi
	xorl	%eax, %eax
	movq	%rcx, %rsi
	callq	_printf
	addq	$16, %rsp
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
	movl	$1, %edi
	callq	_foo
	movq	%rax, %rdi
	callq	_print
	callq	_bar
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_foo
	.align	4, 0x90
_foo:                                   ## @foo
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
Ltmp12:
	.cfi_offset %rbx, -24
	movq	%rdi, %rbx
	cmpq	$3, %rbx
	jge	LBB3_1
## BB#5:                                ## %then0
	movq	%rbx, %rdi
	callq	_print
	movq	%rbx, %rax
	jmp	LBB3_4
LBB3_1:                                 ## %cont0
	cmpq	$5, %rbx
	jle	LBB3_3
## BB#2:                                ## %then1
	movl	$2, %edi
	callq	_print
	movl	$2, %eax
	jmp	LBB3_4
LBB3_3:                                 ## %else2
	movl	$3, %eax
LBB3_4:                                 ## %else2
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_bar
	.align	4, 0x90
_bar:                                   ## @bar
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp13:
	.cfi_def_cfa_offset 16
Ltmp14:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp15:
	.cfi_def_cfa_register %rbp
	movl	$7, %edi
	callq	_print
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"sup meme\n"

L_.str1:                                ## @.str1
	.asciz	"%llu\n"


.subsections_via_symbols
