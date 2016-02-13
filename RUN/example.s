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
	movl	$1, %edi
	callq	__Bool_b
	movl	$4, %edi
                                        ## kill: RDI<def> EDI<kill>
	movb	%al, -53(%rbp)          ## 1-byte Spill
	callq	__Int_i64
	movb	-53(%rbp), %cl          ## 1-byte Reload
	andb	$1, %cl
	movb	%cl, -16(%rbp)
	movq	%rax, -8(%rbp)
	movb	-16(%rbp), %cl
	movl	$2, %edx
	movl	%edx, %edi
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	movb	%cl, -65(%rbp)          ## 1-byte Spill
	callq	__Int_i64
	movl	$8, %edi
	movq	%rax, -80(%rbp)         ## 8-byte Spill
	callq	__Int32_i32
	movl	%eax, %edi
	callq	__print_Int32
	movl	$8, -52(%rbp)
	movl	$8, -32(%rbp)
	movq	-64(%rbp), %rsi         ## 8-byte Reload
	movq	%rsi, -40(%rbp)
	movb	-65(%rbp), %cl          ## 1-byte Reload
	movb	%cl, -48(%rbp)
	leaq	-48(%rbp), %r8
	movq	%r8, -24(%rbp)
	movl	-32(%rbp), %edi
	movq	%r8, %rsi
	movq	-80(%rbp), %rdx         ## 8-byte Reload
	callq	__foo_Eq_Int
	movq	%rax, %rdi
	callq	__print_Int
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__foo_Eq_Int
	.align	4, 0x90
__foo_Eq_Int:                           ## @_foo_Eq_Int
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
	movl	%edi, -16(%rbp)
	movq	%rsi, -8(%rbp)
	movslq	-16(%rbp), %rsi
	movl	%esi, %edi
	movq	%rdx, -24(%rbp)         ## 8-byte Spill
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	callq	__Int32_i32
	movl	%eax, %edi
	callq	__print_Int32
	movq	-8(%rbp), %rdx
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	(%rdx,%rsi), %rdi
	movq	-24(%rbp), %rsi         ## 8-byte Reload
	callq	"__+_Int_Int"
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Bar_Bool_Int
	.align	4, 0x90
__Bar_Bool_Int:                         ## @_Bar_Bool_Int
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
	movb	%dil, %al
	andb	$1, %al
	movb	%al, -16(%rbp)
	movq	%rsi, -8(%rbp)
	movb	-16(%rbp), %al
	movq	%rsi, %rdx
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
