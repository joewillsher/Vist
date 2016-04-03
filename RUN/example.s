	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_Foo_tInt
	.align	4, 0x90
_Foo_tInt:                              ## @Foo_tInt
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
	movl	$8, %eax
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movl	%eax, %edi
	callq	_vist_allocObject
	movq	%rax, %rdi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	callq	_vist_retainObject
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rdi
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	movq	%rcx, (%rdi)
	leaq	L___unnamed_1(%rip), %rdi
	movl	$9, %edx
	movl	%edx, %esi
	callq	_String_topi64
	movq	%rax, %rdi
	movq	%rdx, %rsi
	callq	_print_tString
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	callq	_vist_releaseUnretainedObject
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rax
	movq	-16(%rbp), %rcx         ## 8-byte Reload
	movl	8(%rcx), %edx
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
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	-16(%rbp), %rax
	movl	$1, %ecx
	movl	%ecx, %edi
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	callq	_Foo_tInt
	movl	%edx, -8(%rbp)
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	_vist_retainObject
	leaq	L___unnamed_2(%rip), %rdi
	movl	$2, %ecx
	movl	%ecx, %esi
	callq	_String_topi64
	movq	%rax, %rdi
	movq	%rdx, %rsi
	callq	_print_tString
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	callq	_vist_retainObject
	leaq	L___unnamed_3(%rip), %rdi
	movl	$4, %ecx
	movl	%ecx, %esi
	callq	_String_topi64
	movq	%rax, %rdi
	movq	%rdx, %rsi
	callq	_print_tString
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	callq	_vist_releaseObject
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	callq	_vist_releaseObject
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L___unnamed_1:                          ## @0
	.asciz	"init end"

L___unnamed_2:                          ## @1
	.asciz	"a"

L___unnamed_3:                          ## @2
	.asciz	"end"


.subsections_via_symbols
