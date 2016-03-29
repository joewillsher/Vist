	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
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

	.globl	_unbox2_Foo
	.align	4, 0x90
_unbox2_Foo:                            ## @unbox2_Foo
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movslq	%esi, %rax
	movb	(%rdx,%rax), %al
	movl	%edi, -4(%rbp)          ## 4-byte Spill
	popq	%rbp
	retq

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$2, %eax
	movl	%eax, %edi
	callq	"_vist-Uprint_i64"
	xorl	%edi, %edi
	popq	%rbp
	jmp	"_vist-Uprint_b"        ## TAILCALL

	.globl	_unbox_Foo
	.align	4, 0x90
_unbox_Foo:                             ## @unbox_Foo
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movslq	%edi, %rax
	movq	(%rdx,%rax), %rax
	movl	%esi, -4(%rbp)          ## 4-byte Spill
	popq	%rbp
	retq


.subsections_via_symbols
