	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	__$print_i64
	.align	4, 0x90
__$print_i64:                           ## @"_$print_i64"
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, %rcx
	movq	%rcx, -8(%rbp)
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movq	%rcx, %rsi
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__$print_i32
	.align	4, 0x90
__$print_i32:                           ## @"_$print_i32"
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, %ecx
	movl	%ecx, -4(%rbp)
	leaq	L_.str1(%rip), %rdi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__$print_FP64
	.align	4, 0x90
__$print_FP64:                          ## @"_$print_FP64"
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movsd	%xmm0, -8(%rbp)
	leaq	L_.str2(%rip), %rdi
	movb	$1, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__$print_FP32
	.align	4, 0x90
__$print_FP32:                          ## @"_$print_FP32"
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movss	%xmm0, -4(%rbp)
	movss	-4(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	L_.str2(%rip), %rdi
	movb	$1, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__$print_b
	.align	4, 0x90
__$print_b:                             ## @"_$print_b"
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movb	%dil, -1(%rbp)
	testb	%dil, %dil
	je	LBB4_2
## BB#1:
	leaq	L_.str3(%rip), %rdi
	jmp	LBB4_3
LBB4_2:
	leaq	L_.str4(%rip), %rdi
LBB4_3:
	xorl	%eax, %eax
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__$fatalError_
	.align	4, 0x90
__$fatalError_:                         ## @"_$fatalError_"
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp15:
	.cfi_def_cfa_offset 16
Ltmp16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp17:
	.cfi_def_cfa_register %rbp
	movl	$6, %edi
	callq	_raise
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Int_S.i64
	.align	4, 0x90
__Int_S.i64:                            ## @_Int_S.i64
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp18:
	.cfi_def_cfa_offset 16
Ltmp19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp20:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rdi, %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Int_i64
	.align	4, 0x90
__Int_i64:                              ## @_Int_i64
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp21:
	.cfi_def_cfa_offset 16
Ltmp22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp23:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rdi, %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Bool_S.b
	.align	4, 0x90
__Bool_S.b:                             ## @_Bool_S.b
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp24:
	.cfi_def_cfa_offset 16
Ltmp25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp26:
	.cfi_def_cfa_register %rbp
	andl	$1, %edi
	movb	%dil, -8(%rbp)
	movb	-8(%rbp), %al
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Bool_b
	.align	4, 0x90
__Bool_b:                               ## @_Bool_b
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp27:
	.cfi_def_cfa_offset 16
Ltmp28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp29:
	.cfi_def_cfa_register %rbp
	andl	$1, %edi
	movb	%dil, -8(%rbp)
	movb	-8(%rbp), %al
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Double_S.FP64
	.align	4, 0x90
__Double_S.FP64:                        ## @_Double_S.FP64
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp30:
	.cfi_def_cfa_offset 16
Ltmp31:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp32:
	.cfi_def_cfa_register %rbp
	movsd	%xmm0, -8(%rbp)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Double_FP64
	.align	4, 0x90
__Double_FP64:                          ## @_Double_FP64
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp33:
	.cfi_def_cfa_offset 16
Ltmp34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp35:
	.cfi_def_cfa_register %rbp
	movsd	%xmm0, -8(%rbp)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__print_S.i64
	.align	4, 0x90
__print_S.i64:                          ## @_print_S.i64
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp36:
	.cfi_def_cfa_offset 16
Ltmp37:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp38:
	.cfi_def_cfa_register %rbp
	callq	__$print_i64
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__print_S.b
	.align	4, 0x90
__print_S.b:                            ## @_print_S.b
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp39:
	.cfi_def_cfa_offset 16
Ltmp40:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp41:
	.cfi_def_cfa_register %rbp
	andl	$1, %edi
	callq	__$print_b
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__print_S.FP64
	.align	4, 0x90
__print_S.FP64:                         ## @_print_S.FP64
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp42:
	.cfi_def_cfa_offset 16
Ltmp43:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp44:
	.cfi_def_cfa_register %rbp
	callq	__$print_FP64
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__assert_S.b
	.align	4, 0x90
__assert_S.b:                           ## @_assert_S.b
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp45:
	.cfi_def_cfa_offset 16
Ltmp46:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp47:
	.cfi_def_cfa_register %rbp
	testb	$1, %dil
	je	LBB15_2
## BB#1:                                ## %then0
	callq	__$fatalError_
LBB15_2:                                ## %cont
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__fatalError_
	.align	4, 0x90
__fatalError_:                          ## @_fatalError_
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp48:
	.cfi_def_cfa_offset 16
Ltmp49:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp50:
	.cfi_def_cfa_register %rbp
	callq	__$fatalError_
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__+_S.FP64S.FP64"
	.align	4, 0x90
"__+_S.FP64S.FP64":                     ## @"_+_S.FP64S.FP64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp51:
	.cfi_def_cfa_offset 16
Ltmp52:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp53:
	.cfi_def_cfa_register %rbp
	addsd	%xmm1, %xmm0
	callq	__Double_FP64
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__+_S.i64S.i64"
	.align	4, 0x90
"__+_S.i64S.i64":                       ## @"_+_S.i64S.i64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp54:
	.cfi_def_cfa_offset 16
Ltmp55:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp56:
	.cfi_def_cfa_register %rbp
	addq	%rsi, %rdi
	callq	__Int_i64
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__-_S.i64S.i64"
	.align	4, 0x90
"__-_S.i64S.i64":                       ## @_-_S.i64S.i64
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp57:
	.cfi_def_cfa_offset 16
Ltmp58:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp59:
	.cfi_def_cfa_register %rbp
	subq	%rsi, %rdi
	callq	__Int_i64
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__*_S.i64S.i64"
	.align	4, 0x90
"__*_S.i64S.i64":                       ## @"_*_S.i64S.i64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp60:
	.cfi_def_cfa_offset 16
Ltmp61:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp62:
	.cfi_def_cfa_register %rbp
	imulq	%rsi, %rdi
	callq	__Int_i64
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__/_S.i64S.i64"
	.align	4, 0x90
"__/_S.i64S.i64":                       ## @"_/_S.i64S.i64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp63:
	.cfi_def_cfa_offset 16
Ltmp64:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp65:
	.cfi_def_cfa_register %rbp
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%rsi
	movq	%rax, %rdi
	callq	__Int_i64
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__%_S.i64S.i64"
	.align	4, 0x90
"__%_S.i64S.i64":                       ## @"_%_S.i64S.i64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp66:
	.cfi_def_cfa_offset 16
Ltmp67:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp68:
	.cfi_def_cfa_register %rbp
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%rsi
	movq	%rdx, %rdi
	callq	__Int_i64
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__<_S.i64S.i64"
	.align	4, 0x90
"__<_S.i64S.i64":                       ## @"_<_S.i64S.i64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp69:
	.cfi_def_cfa_offset 16
Ltmp70:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp71:
	.cfi_def_cfa_register %rbp
	cmpq	%rsi, %rdi
	setl	%al
	movzbl	%al, %edi
	callq	__Bool_b
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__<=_S.i64S.i64"
	.align	4, 0x90
"__<=_S.i64S.i64":                      ## @"_<=_S.i64S.i64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp72:
	.cfi_def_cfa_offset 16
Ltmp73:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp74:
	.cfi_def_cfa_register %rbp
	cmpq	%rsi, %rdi
	setle	%al
	movzbl	%al, %edi
	callq	__Bool_b
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__>_S.i64S.i64"
	.align	4, 0x90
"__>_S.i64S.i64":                       ## @"_>_S.i64S.i64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp75:
	.cfi_def_cfa_offset 16
Ltmp76:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp77:
	.cfi_def_cfa_register %rbp
	cmpq	%rsi, %rdi
	setg	%al
	movzbl	%al, %edi
	callq	__Bool_b
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__>=_S.i64S.i64"
	.align	4, 0x90
"__>=_S.i64S.i64":                      ## @"_>=_S.i64S.i64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp78:
	.cfi_def_cfa_offset 16
Ltmp79:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp80:
	.cfi_def_cfa_register %rbp
	cmpq	%rsi, %rdi
	setge	%al
	movzbl	%al, %edi
	callq	__Bool_b
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__==_S.i64S.i64"
	.align	4, 0x90
"__==_S.i64S.i64":                      ## @"_==_S.i64S.i64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp81:
	.cfi_def_cfa_offset 16
Ltmp82:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp83:
	.cfi_def_cfa_register %rbp
	cmpq	%rsi, %rdi
	sete	%al
	movzbl	%al, %edi
	callq	__Bool_b
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__!=_S.i64S.i64"
	.align	4, 0x90
"__!=_S.i64S.i64":                      ## @"_!=_S.i64S.i64"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp84:
	.cfi_def_cfa_offset 16
Ltmp85:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp86:
	.cfi_def_cfa_register %rbp
	cmpq	%rsi, %rdi
	setne	%al
	movzbl	%al, %edi
	callq	__Bool_b
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__&&_S.bS.b"
	.align	4, 0x90
"__&&_S.bS.b":                          ## @"_&&_S.bS.b"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp87:
	.cfi_def_cfa_offset 16
Ltmp88:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp89:
	.cfi_def_cfa_register %rbp
	andl	%esi, %edi
	callq	__Bool_b
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"__||_S.bS.b"
	.align	4, 0x90
"__||_S.bS.b":                          ## @"_||_S.bS.b"
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp90:
	.cfi_def_cfa_offset 16
Ltmp91:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp92:
	.cfi_def_cfa_register %rbp
	orl	%esi, %edi
	callq	__Bool_b
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%llu\n"

L_.str1:                                ## @.str1
	.asciz	"%i\n"

L_.str2:                                ## @.str2
	.asciz	"%f\n"

L_.str3:                                ## @.str3
	.asciz	"true\n"

L_.str4:                                ## @.str4
	.asciz	"false\n"


.subsections_via_symbols
