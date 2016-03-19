	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$41, %eax
	movl	%eax, %edi
	callq	"_-Uprint_i64"
	movl	$2, %eax
	movl	%eax, %edi
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL

	.globl	_void_
	.align	4, 0x90
_void_:                                 ## @void_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$41, %eax
	movl	%eax, %edi
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL

	.globl	_two_
	.align	4, 0x90
_two_:                                  ## @two_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$2, %eax
                                        ## kill: RAX<def> EAX<kill>
	popq	%rbp
	retq


.subsections_via_symbols
