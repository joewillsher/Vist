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
	subq	$80, %rsp
	leaq	L___unnamed_1(%rip), %rdi
	movl	$9, %eax
	movl	%eax, %esi
	xorl	%edx, %edx
	callq	_String_topi64b
	movq	%rdx, %rsi
	movq	%rdx, %rdi
	movq	%rsi, -56(%rbp)         ## 8-byte Spill
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	movq	%rcx, -72(%rbp)         ## 8-byte Spill
	callq	_print_tI
	leaq	-24(%rbp), %rdi
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-56(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, -16(%rbp)
	movq	-72(%rbp), %rdx         ## 8-byte Reload
	movq	%rdx, -8(%rbp)
	callq	_bufferCapacity_mString
	movq	%rax, %rdi
	callq	_print_tI
	leaq	-48(%rbp), %rdi
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -48(%rbp)
	movq	-56(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, -40(%rbp)
	movq	-72(%rbp), %rdx         ## 8-byte Reload
	movq	%rdx, -32(%rbp)
	callq	_isUTF8Encoded_mString
	movzbl	%al, %edi
	callq	_print_tB
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	movq	-56(%rbp), %rsi         ## 8-byte Reload
	movq	-72(%rbp), %rdx         ## 8-byte Reload
	callq	_print_tString
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L___unnamed_1:                          ## @0
	.asciz	"aaaa\360\237\244\224"


.subsections_via_symbols
