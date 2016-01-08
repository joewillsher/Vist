	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	__print_i64
	.align	4, 0x90
__print_i64:                            ## @_print_i64
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
	movq	%rdi, %rcx
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movq	%rcx, %rsi
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	__print_i32
	.align	4, 0x90
__print_i32:                            ## @_print_i32
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
	movl	%edi, %ecx
	leaq	L_.str1(%rip), %rdi
	xorl	%eax, %eax
	movl	%ecx, %esi
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	__print_FP64
	.align	4, 0x90
__print_FP64:                           ## @_print_FP64
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
	leaq	L_.str2(%rip), %rdi
	movb	$1, %al
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	__print_FP32
	.align	4, 0x90
__print_FP32:                           ## @_print_FP32
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
	cvtss2sd	%xmm0, %xmm0
	leaq	L_.str2(%rip), %rdi
	movb	$1, %al
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	__print_b
	.align	4, 0x90
__print_b:                              ## @_print_b
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
	testb	%dil, %dil
	je	LBB4_2
## BB#1:
	leaq	L_str1(%rip), %rdi
	popq	%rbp
	jmp	_puts                   ## TAILCALL
LBB4_2:
	leaq	L_str(%rip), %rdi
	popq	%rbp
	jmp	_puts                   ## TAILCALL
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%edi, %edi
	callq	__print_i64
	movl	$1, %edi
	callq	__print_i64
	movl	$2, %edi
	callq	__print_i64
	movl	$3, %edi
	callq	__print_i64
	movl	$4, %edi
	callq	__print_i64
	movl	$5, %edi
	callq	__print_i64
	movl	$6, %edi
	callq	__print_i64
	movl	$7, %edi
	callq	__print_i64
	movl	$8, %edi
	callq	__print_i64
	movl	$9, %edi
	callq	__print_i64
	movl	$10, %edi
	callq	__print_i64
	movl	$7, %edi
	callq	__print_i64
	xorl	%eax, %eax
	popq	%rbp
	retq

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%llu\n"

L_.str1:                                ## @.str1
	.asciz	"%i\n"

L_.str2:                                ## @.str2
	.asciz	"%f\n"

L_str:                                  ## @str
	.asciz	"false"

L_str1:                                 ## @str1
	.asciz	"true"


.subsections_via_symbols
