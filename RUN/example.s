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
	movl	$2, %eax
	movl	%eax, %edi
	movl	$1, %eax
	movl	%eax, %esi
	callq	"_-P_Int_Int"
	movl	$4, %ecx
	movl	%ecx, %edi
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	addq	$16, %rsp
	popq	%rbp
	jmp	_print_Int              ## TAILCALL
	.cfi_endproc


.subsections_via_symbols
