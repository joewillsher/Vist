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
	subq	$128, %rsp
	movl	$1, %edi
	callq	__Bool_b
	movl	$11, %edi
                                        ## kill: RDI<def> EDI<kill>
	movb	%al, -73(%rbp)          ## 1-byte Spill
	callq	__Int_i64
	movl	$4, %ecx
	movl	%ecx, %edi
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	callq	__Int_i64
	movb	-73(%rbp), %dl          ## 1-byte Reload
	andb	$1, %dl
	movb	%dl, -24(%rbp)
	movq	-88(%rbp), %rdi         ## 8-byte Reload
	movq	%rdi, -16(%rbp)
	movq	%rax, -8(%rbp)
	movb	-24(%rbp), %dl
	movq	-16(%rbp), %rsi
	movl	$2, %ecx
	movl	%ecx, %edi
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	movq	%rsi, -104(%rbp)        ## 8-byte Spill
	movb	%dl, -105(%rbp)         ## 1-byte Spill
	callq	__Int_i64
	movabsq	$34359738384, %rsi      ## imm = 0x800000010
	movq	%rsi, -72(%rbp)
	movl	-72(%rbp), %ecx
	movl	%ecx, -40(%rbp)
	movl	$8, -36(%rbp)
	movq	-96(%rbp), %rsi         ## 8-byte Reload
	movq	%rsi, -48(%rbp)
	movq	-104(%rbp), %rdi        ## 8-byte Reload
	movq	%rdi, -56(%rbp)
	movb	-105(%rbp), %dl         ## 1-byte Reload
	movb	%dl, -64(%rbp)
	leaq	-64(%rbp), %rdi
	movq	%rdi, -32(%rbp)
	movl	-40(%rbp), %ecx
	movl	-36(%rbp), %esi
	movq	%rdi, -120(%rbp)        ## 8-byte Spill
	movl	%ecx, %edi
	movq	-120(%rbp), %rdx        ## 8-byte Reload
	movq	%rax, %rcx
	callq	__foo_Eq_Int
	movq	%rax, %rdi
	callq	__print_Int
	addq	$128, %rsp
	popq	%rbp
	retq
	.cfi_endproc

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
	movl	%esi, -12(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movslq	-12(%rbp), %rax
	movq	(%rdx,%rax), %rdi
	movslq	-16(%rbp), %rax
	movq	(%rdx,%rax), %rsi
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdi
	callq	"__+_Int_Int"
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, %rsi
	callq	"__+_Int_Int"
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Bar_Bool_Int_Int
	.align	4, 0x90
__Bar_Bool_Int_Int:                     ## @_Bar_Bool_Int_Int
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
	movb	%al, -24(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-16(%rbp), %rsi
	movb	-24(%rbp), %al
	movq	%rdx, -32(%rbp)         ## 8-byte Spill
	movq	%rsi, %rdx
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
