	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %foo_Eq_Int.exit
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$240, %rsp
	movl	$17, %eax
	movl	%eax, %edi
	callq	"_-Uprint_i64"
	movl	$0, -28(%rbp)
	movl	$0, -24(%rbp)
	movq	$1, -8(%rbp)
	leaq	-8(%rbp), %rdi
	movq	%rdi, -16(%rbp)
	movl	-24(%rbp), %eax
	movq	%rdi, -40(%rbp)
	movl	%eax, -48(%rbp)
	movq	-40(%rbp), %rdi
	movslq	-48(%rbp), %rcx
	movq	(%rdi,%rcx), %rdi
	callq	"_-Uprint_i64"
	movl	$0, -76(%rbp)
	movl	$0, -72(%rbp)
	movq	$12, -56(%rbp)
	leaq	-56(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movslq	-72(%rbp), %rcx
	movq	-56(%rbp,%rcx), %rdi
	movq	%rcx, -224(%rbp)        ## 8-byte Spill
	callq	"_-Uprint_i64"
	movq	-224(%rbp), %rcx        ## 8-byte Reload
	movq	-56(%rbp,%rcx), %rdi
	callq	"_-Uprint_i64"
	movq	-224(%rbp), %rcx        ## 8-byte Reload
	movq	-56(%rbp,%rcx), %rdi
	callq	"_-Uprint_i64"
	movq	-224(%rbp), %rcx        ## 8-byte Reload
	movq	-56(%rbp,%rcx), %rdi
	callq	"_-Uprint_i64"
	movl	$0, -108(%rbp)
	movl	$0, -104(%rbp)
	movq	$1, -88(%rbp)
	leaq	-88(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movl	-104(%rbp), %eax
	movq	%rcx, -120(%rbp)
	movl	%eax, -128(%rbp)
	movq	-120(%rbp), %rcx
	movslq	-128(%rbp), %rdi
	movq	$2, (%rcx,%rdi)
	movl	$2, %eax
	movl	%eax, %edi
	callq	"_-Uprint_i64"
	movl	-128(%rbp), %eax
	movq	-120(%rbp), %rcx
	movq	$1, -152(%rbp)
	movq	%rcx, -136(%rbp)
	movl	%eax, -144(%rbp)
	movq	-152(%rbp), %rcx
	movl	-144(%rbp), %eax
	movq	-136(%rbp), %rdi
	movq	%rdi, -168(%rbp)
	movl	%eax, -176(%rbp)
	movq	%rcx, -184(%rbp)
	movq	$2, -160(%rbp)
	movq	-184(%rbp), %rcx
	movl	-176(%rbp), %eax
	movq	-168(%rbp), %rdi
	movq	%rdi, -200(%rbp)
	movl	%eax, -208(%rbp)
	movq	%rcx, -216(%rbp)
	movq	$2, -192(%rbp)
	movq	-192(%rbp), %rdi
	callq	"_-Uprint_i64"
	movq	-216(%rbp), %rdi
	callq	"_-Uprint_i64"
	movq	-200(%rbp), %rcx
	movslq	-208(%rbp), %rdi
	movq	(%rcx,%rdi), %rdx
	movq	%rdi, -232(%rbp)        ## 8-byte Spill
	movq	%rdx, %rdi
	movq	%rcx, -240(%rbp)        ## 8-byte Spill
	callq	"_-Uprint_i64"
	movq	-240(%rbp), %rcx        ## 8-byte Reload
	movq	-232(%rbp), %rdx        ## 8-byte Reload
	movq	$11, (%rcx,%rdx)
	movl	$11, %eax
	movl	%eax, %edi
	addq	$240, %rsp
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL

	.globl	_Bar_Bool_Int_Int
	.align	4, 0x90
_Bar_Bool_Int_Int:                      ## @Bar_Bool_Int_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	movq	%rdx, -8(%rbp)          ## 8-byte Spill
	movq	%rsi, %rdx
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	popq	%rbp
	retq

	.globl	_Foo_Int
	.align	4, 0x90
_Foo_Int:                               ## @Foo_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_Baz_TestC
	.align	4, 0x90
_Baz_TestC:                             ## @Baz_TestC
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, %eax
	movq	%rsi, %rdx
	popq	%rbp
	retq

	.globl	_Baq_Int
	.align	4, 0x90
_Baq_Int:                               ## @Baq_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_I_Int
	.align	4, 0x90
_I_Int:                                 ## @I_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_A_I
	.align	4, 0x90
_A_I:                                   ## @A_I
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_B_X
	.align	4, 0x90
_B_X:                                   ## @B_X
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, %eax
	movq	%rsi, %rdx
	popq	%rbp
	retq


.subsections_via_symbols
