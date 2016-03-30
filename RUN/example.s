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
	callq	"_vist-Uprint_i64"
	movl	$1, %eax
	movl	%eax, %edi
	callq	"_vist-Uprint_i64"
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_foo_
	.align	4, 0x90
_foo_:                                  ## @foo_
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
	movl	$1, %eax
	movl	%eax, %edi
	callq	"_vist-Uprint_i64"
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
