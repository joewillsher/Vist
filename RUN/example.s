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
	subq	$160, %rsp
	movl	$10, %eax
	movl	%eax, %ecx
	movq	%rcx, %rdi
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	callq	__Int_i64
	movq	%rax, -24(%rbp)
	movl	$20, %edx
	movl	%edx, %edi
	callq	__Int_i64
	movq	%rax, -16(%rbp)
	movl	$40, %edx
	movl	%edx, %edi
	callq	__Int_i64
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rdi
	movq	-16(%rbp), %rcx
	movl	$1, %edx
	movl	%edx, %esi
	movq	%rdi, -40(%rbp)         ## 8-byte Spill
	movq	%rsi, %rdi
	movq	%rax, -48(%rbp)         ## 8-byte Spill
	movq	%rsi, -56(%rbp)         ## 8-byte Spill
	movq	%rcx, -64(%rbp)         ## 8-byte Spill
	callq	__Int_i64
	movl	$2, %edx
	movl	%edx, %ecx
	movq	%rcx, %rdi
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movq	%rcx, -80(%rbp)         ## 8-byte Spill
	callq	__Int_i64
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	callq	__Int_i64
	movq	-72(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, %rsi
	callq	"__+_S.i64_S.i64"
	movq	%rax, %rdi
	movq	-88(%rbp), %rsi         ## 8-byte Reload
	callq	"__+_S.i64_S.i64"
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	callq	__Int_i64
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, -104(%rbp)        ## 8-byte Spill
	callq	__Int_i64
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	movq	-48(%rbp), %rsi         ## 8-byte Reload
	movq	%rax, -112(%rbp)        ## 8-byte Spill
	callq	"__+_S.i64_S.i64"
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, %rsi
	callq	"__+_S.i64_S.i64"
	movq	%rax, %rdi
	movq	-112(%rbp), %rsi        ## 8-byte Reload
	callq	"__*_S.i64_S.i64"
	movq	-104(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	"__+_S.i64_S.i64"
	movq	%rax, %rdi
	callq	__print_S.i64
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	callq	__Int_i64
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, -120(%rbp)        ## 8-byte Spill
	callq	__Int_i64
	movq	-120(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	"__+_S.i64_S.i64"
	movq	%rax, %rdi
	callq	__print_S.i64
	xorl	%edx, %edx
	movl	%edx, %edi
	callq	__Int_i64
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	callq	__Int_i64
	movq	-128(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	__..._S.i64_S.i64
	movq	%rdx, -136(%rbp)        ## 8-byte Spill
	movq	%rax, -144(%rbp)        ## 8-byte Spill
LBB0_1:                                 ## %loop.header
                                        ## =>This Inner Loop Header: Depth=1
	movq	-144(%rbp), %rax        ## 8-byte Reload
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rax, %rdi
	movq	%rcx, -152(%rbp)        ## 8-byte Spill
	callq	__Int_i64
	movq	%rax, %rdi
	callq	__print_S.i64
	movq	-152(%rbp), %rax        ## 8-byte Reload
	movq	-136(%rbp), %rcx        ## 8-byte Reload
	cmpq	%rcx, %rax
	movq	%rax, -144(%rbp)        ## 8-byte Spill
	jle	LBB0_1
## BB#2:                                ## %loop.exit
	xorl	%eax, %eax
                                        ## kill: RAX<def> EAX<kill>
	addq	$160, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Foo_
	.align	4, 0x90
__Foo_:                                 ## @_Foo_
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
	movl	$10, %eax
	movl	%eax, %edi
	callq	__Int_i64
	movq	%rax, -24(%rbp)
	movl	$20, %ecx
	movl	%ecx, %edi
	callq	__Int_i64
	movq	%rax, -16(%rbp)
	movl	$40, %ecx
	movl	%ecx, %edi
	callq	__Int_i64
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rdi
	movq	-16(%rbp), %rdx
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	movq	%rdi, %rax
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Foo.sumTimes_S.i64
	.align	4, 0x90
__Foo.sumTimes_S.i64:                   ## @_Foo.sumTimes_S.i64
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rsi, %rdi
	movq	%rdx, %rsi
	movq	%rcx, -16(%rbp)         ## 8-byte Spill
	callq	"__+_S.i64_S.i64"
	movq	-8(%rbp), %rdi          ## 8-byte Reload
	movq	%rax, %rsi
	callq	"__+_S.i64_S.i64"
	movq	%rax, %rdi
	movq	-16(%rbp), %rsi         ## 8-byte Reload
	addq	$16, %rsp
	popq	%rbp
	jmp	"__*_S.i64_S.i64"       ## TAILCALL
	.cfi_endproc

	.globl	__Foo.printA_S.b
	.align	4, 0x90
__Foo.printA_S.b:                       ## @_Foo.printA_S.b
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movb	%cl, %al
	testb	$1, %al
	movq	%rsi, -8(%rbp)          ## 8-byte Spill
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	movq	%rdx, -24(%rbp)         ## 8-byte Spill
	jne	LBB3_2
LBB3_1:                                 ## %cont.stmt
	addq	$32, %rsp
	popq	%rbp
	retq
LBB3_2:                                 ## %then.0
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__print_S.i64
	jmp	LBB3_1
	.cfi_endproc

	.globl	__add_S.i64_S.i64
	.align	4, 0x90
__add_S.i64_S.i64:                      ## @_add_S.i64_S.i64
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp14:
	.cfi_def_cfa_register %rbp
	popq	%rbp
	jmp	"__+_S.i64_S.i64"       ## TAILCALL
	.cfi_endproc


.subsections_via_symbols
