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

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$6, %edi
	callq	__print_i64
	xorl	%eax, %eax
	popq	%rbp
	retq

	.globl	__Int_S.i64_RS.i64
	.align	4, 0x90
__Int_S.i64_RS.i64:                     ## @_Int_S.i64_RS.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	__Int_i64_RS.i64
	.align	4, 0x90
__Int_i64_RS.i64:                       ## @_Int_i64_RS.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	__print_S.i64
	.align	4, 0x90
__print_S.i64:                          ## @_print_S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	jmp	__print_i64             ## TAILCALL

	.globl	__foo_S.i64S.i64_RS.i64
	.align	4, 0x90
__foo_S.i64S.i64_RS.i64:                ## @_foo_S.i64S.i64_RS.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	addq	%rsi, %rdi
	movq	%rdi, %rax
	popq	%rbp
	retq

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%llu\n"

L_.str1:                                ## @.str1
	.asciz	"%i\n"

L_.str2:                                ## @.str2
	.asciz	"%f\n"


.subsections_via_symbols
