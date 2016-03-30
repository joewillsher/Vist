	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_unbox_Foo
	.align	4, 0x90
_unbox_Foo:                             ## @unbox_Foo
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movslq	%edi, %rax
	movq	(%rcx,%rax), %rax
	movl	%esi, -4(%rbp)          ## 4-byte Spill
	movq	%rdx, -16(%rbp)         ## 8-byte Spill
	popq	%rbp
	retq

	.globl	_Bar.aye_
	.align	4, 0x90
_Bar.aye_:                              ## @Bar.aye_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	testb	$1, 16(%rdi)
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	jne	LBB1_1
	jmp	LBB1_2
LBB1_1:                                 ## %if.0
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	8(%rax), %rax
	popq	%rbp
	retq
LBB1_2:                                 ## %else.1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	(%rax), %rax
	popq	%rbp
	retq

	.globl	_Bar_Int_Int_Bool
	.align	4, 0x90
_Bar_Int_Int_Bool:                      ## @Bar_Int_Int_Bool
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dl, %al
	movb	%al, -1(%rbp)           ## 1-byte Spill
	movq	%rdi, %rax
	movq	%rsi, %rdx
	movb	-1(%rbp), %cl           ## 1-byte Reload
	popq	%rbp
	retq

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %Bar.aye_.exit
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$2, %eax
	movl	%eax, %edi
	callq	"_vist-Uprint_i64"
	movl	$1, %eax
	movl	%eax, %edi
	popq	%rbp
	jmp	"_vist-Uprint_i64"      ## TAILCALL

	.globl	_callAye_Foo
	.align	4, 0x90
_callAye_Foo:                           ## @callAye_Foo
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
	movl	%edi, -4(%rbp)          ## 4-byte Spill
	movq	%rcx, %rdi
	movl	%esi, -8(%rbp)          ## 4-byte Spill
	popq	%rbp
	jmpq	*%rdx  # TAILCALL
	.cfi_endproc


.subsections_via_symbols
