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
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	movq	%rcx, (%rax)
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
	subq	$16, %rsp
	movl	$8, %edi
	callq	_vist_allocObject
	movq	$1, (%rax)
	movl	$1, %edi
                                        ## kill: RDI<def> EDI<kill>
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	movl	%edx, -12(%rbp)         ## 4-byte Spill
	callq	"_vist-Uprint_ti64"
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	$2, (%rax)
	movl	$2, %edx
	movl	%edx, %edi
	callq	"_vist-Uprint_ti64"
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	(%rax), %rdi
	addq	$16, %rsp
	popq	%rbp
	jmp	"_vist-Uprint_ti64"     ## TAILCALL
	.cfi_endproc


.subsections_via_symbols
