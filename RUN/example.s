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
	movl	$1, %eax
	movl	%eax, %edi
	movl	$2, %eax
	movl	%eax, %esi
	callq	"__+_S.i64_S.i64"
	movq	%rax, %rdi
	callq	__print_S.i64
	xorl	%ecx, %ecx
	movl	%ecx, %eax
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
