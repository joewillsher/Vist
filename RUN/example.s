	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_Foo_Int
	.align	4, 0x90
_Foo_Int:                               ## @Foo_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_Foo.foo_Int
	.align	4, 0x90
_Foo.foo_Int:                           ## @Foo.foo_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	(%rdi), %rdi
	imulq	%rdi, %rsi
	seto	%al
	movq	%rsi, -8(%rbp)          ## 8-byte Spill
	movb	%al, -9(%rbp)           ## 1-byte Spill
	jo	LBB1_1
	jmp	LBB1_2
LBB1_1:                                 ## %inlined.-A_Int_Int.then.0.i
	ud2
LBB1_2:                                 ## %inlined.-A_Int_Int.condFail_b.exit
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$6, %eax
	movl	%eax, %edi
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL


.subsections_via_symbols
