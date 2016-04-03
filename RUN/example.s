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
	subq	$32, %rsp
	movl	$8, %eax
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movl	%eax, %edi
	callq	_vist_allocObject
	movl	%edx, -8(%rbp)
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	_vist_retainObject
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	%rdi, (%rax)
	leaq	L___unnamed_1(%rip), %rdi
	movl	$9, %edx
	movl	%edx, %esi
	callq	_String_topi64
	movq	%rax, %rdi
	movq	%rdx, %rsi
	callq	_print_tString
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	callq	_vist_releaseUnretainedObject
	movq	-16(%rbp), %rax
	movl	-8(%rbp), %edx
	addq	$32, %rsp
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
	subq	$112, %rsp
	leaq	L___unnamed_2(%rip), %rdi
	movl	$4, %eax
	movl	%eax, %esi
	movl	$1, %eax
	movl	%eax, %ecx
	movq	%rdi, -88(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdi
	movq	%rsi, -96(%rbp)         ## 8-byte Spill
	callq	_Foo_tInt
	movl	%edx, -8(%rbp)
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rdi
	callq	_vist_retainObject
	movq	-16(%rbp), %rax
	movl	-8(%rbp), %edx
	movl	%edx, -24(%rbp)
	movq	%rax, -32(%rbp)
	leaq	L___unnamed_3(%rip), %rdi
	movl	$2, %edx
	movl	%edx, %esi
	callq	_String_topi64
	movq	%rax, %rdi
	movq	%rdx, %rsi
	callq	_print_tString
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	movq	%rax, -104(%rbp)        ## 8-byte Spill
	callq	_vist_retainObject
	movq	-32(%rbp), %rax
	movl	-24(%rbp), %r8d
	movl	%r8d, -40(%rbp)
	movq	%rax, -48(%rbp)
	movq	-104(%rbp), %rdi        ## 8-byte Reload
	callq	_vist_retainObject
	movq	-32(%rbp), %rax
	movl	-24(%rbp), %r8d
	movl	%r8d, -56(%rbp)
	movq	%rax, -64(%rbp)
	movq	-104(%rbp), %rdi        ## 8-byte Reload
	callq	_vist_retainObject
	movq	-32(%rbp), %rax
	movl	-24(%rbp), %r8d
	movl	%r8d, -72(%rbp)
	movq	%rax, -80(%rbp)
	movq	-88(%rbp), %rdi         ## 8-byte Reload
	movq	-96(%rbp), %rsi         ## 8-byte Reload
	callq	_String_topi64
	movq	%rax, %rdi
	movq	%rdx, %rsi
	callq	_print_tString
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	callq	_vist_releaseObject
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	callq	_vist_releaseObject
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	callq	_vist_releaseObject
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	callq	_vist_releaseObject
	addq	$112, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L___unnamed_1:                          ## @0
	.asciz	"init end"

L___unnamed_3:                          ## @1
	.asciz	"a"

L___unnamed_2:                          ## @2
	.asciz	"end"


.subsections_via_symbols
