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
	movq	%rdi, %rcx
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movq	%rcx, %rsi
	popq	%rbp
	jmp	_printf                 ## TAILCALL
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
	movl	%edi, %ecx
	leaq	L_.str1(%rip), %rdi
	xorl	%eax, %eax
	movl	%ecx, %esi
	popq	%rbp
	jmp	_printf                 ## TAILCALL
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
	leaq	L_.str2(%rip), %rdi
	movb	$1, %al
	popq	%rbp
	jmp	_printf                 ## TAILCALL
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
	cvtss2sd	%xmm0, %xmm0
	leaq	L_.str2(%rip), %rdi
	movb	$1, %al
	popq	%rbp
	jmp	_printf                 ## TAILCALL
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
	testb	%dil, %dil
	je	LBB4_2
## BB#1:
	leaq	L_str1(%rip), %rdi
	popq	%rbp
	jmp	_puts                   ## TAILCALL
LBB4_2:
	leaq	L_str(%rip), %rdi
	popq	%rbp
	jmp	_puts                   ## TAILCALL
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
	callq	_abort
	.cfi_endproc

	.globl	__Int_S.i64
	.align	4, 0x90
__Int_S.i64:                            ## @_Int_S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	__Int_i64
	.align	4, 0x90
__Int_i64:                              ## @_Int_i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	__Bool_S.b
	.align	4, 0x90
__Bool_S.b:                             ## @_Bool_S.b
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	popq	%rbp
	retq

	.globl	__Bool_b
	.align	4, 0x90
__Bool_b:                               ## @_Bool_b
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	popq	%rbp
	retq

	.globl	__Double_S.FP64
	.align	4, 0x90
__Double_S.FP64:                        ## @_Double_S.FP64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	retq

	.globl	__Double_FP64
	.align	4, 0x90
__Double_FP64:                          ## @_Double_FP64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	retq

	.globl	__Range_S.i64S.i64
	.align	4, 0x90
__Range_S.i64S.i64:                     ## @_Range_S.i64S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq

	.globl	__print_S.i64
	.align	4, 0x90
__print_S.i64:                          ## @_print_S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	jmp	__$print_i64            ## TAILCALL

	.globl	__print_S.b
	.align	4, 0x90
__print_S.b:                            ## @_print_S.b
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	andl	$1, %edi
	popq	%rbp
	jmp	__$print_b              ## TAILCALL

	.globl	__print_S.FP64
	.align	4, 0x90
__print_S.FP64:                         ## @_print_S.FP64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	jmp	__$print_FP64           ## TAILCALL

	.globl	__fatalError_
	.align	4, 0x90
__fatalError_:                          ## @_fatalError_
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
	callq	__$fatalError_
	.cfi_endproc

	.globl	__assert_S.b
	.align	4, 0x90
__assert_S.b:                           ## @_assert_S.b
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
	testb	$1, %dil
	je	LBB17_2
## BB#1:                                ## %then0
	popq	%rbp
	retq
LBB17_2:                                ## %else1
	callq	__$fatalError_
	.cfi_endproc

	.globl	"__+_S.i64S.i64"
	.align	4, 0x90
"__+_S.i64S.i64":                       ## @"_+_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	addq	%rsi, %rdi
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	"__-_S.i64S.i64"
	.align	4, 0x90
"__-_S.i64S.i64":                       ## @_-_S.i64S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	%rsi, %rdi
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	"__*_S.i64S.i64"
	.align	4, 0x90
"__*_S.i64S.i64":                       ## @"_*_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	imulq	%rsi, %rdi
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	"__/_S.i64S.i64"
	.align	4, 0x90
"__/_S.i64S.i64":                       ## @"_/_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%rsi
	popq	%rbp
	retq

	.globl	"__%_S.i64S.i64"
	.align	4, 0x90
"__%_S.i64S.i64":                       ## @"_%_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%rsi
	movq	%rdx, %rax
	popq	%rbp
	retq

	.globl	"__<_S.i64S.i64"
	.align	4, 0x90
"__<_S.i64S.i64":                       ## @"_<_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	setl	%al
	popq	%rbp
	retq

	.globl	"__<=_S.i64S.i64"
	.align	4, 0x90
"__<=_S.i64S.i64":                      ## @"_<=_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	setle	%al
	popq	%rbp
	retq

	.globl	"__>_S.i64S.i64"
	.align	4, 0x90
"__>_S.i64S.i64":                       ## @"_>_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	setg	%al
	popq	%rbp
	retq

	.globl	"__>=_S.i64S.i64"
	.align	4, 0x90
"__>=_S.i64S.i64":                      ## @"_>=_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	setge	%al
	popq	%rbp
	retq

	.globl	"__==_S.i64S.i64"
	.align	4, 0x90
"__==_S.i64S.i64":                      ## @"_==_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	sete	%al
	popq	%rbp
	retq

	.globl	"__!=_S.i64S.i64"
	.align	4, 0x90
"__!=_S.i64S.i64":                      ## @"_!=_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	setne	%al
	popq	%rbp
	retq

	.globl	"__&&_S.bS.b"
	.align	4, 0x90
"__&&_S.bS.b":                          ## @"_&&_S.bS.b"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	andl	%esi, %edi
	movb	%dil, %al
	popq	%rbp
	retq

	.globl	"__||_S.bS.b"
	.align	4, 0x90
"__||_S.bS.b":                          ## @"_||_S.bS.b"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	orl	%esi, %edi
	movb	%dil, %al
	popq	%rbp
	retq

	.globl	"__+_S.FP64S.FP64"
	.align	4, 0x90
"__+_S.FP64S.FP64":                     ## @"_+_S.FP64S.FP64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	addsd	%xmm1, %xmm0
	popq	%rbp
	retq

	.globl	"__-_S.FP64S.FP64"
	.align	4, 0x90
"__-_S.FP64S.FP64":                     ## @_-_S.FP64S.FP64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subsd	%xmm1, %xmm0
	popq	%rbp
	retq

	.globl	"__*_S.FP64S.FP64"
	.align	4, 0x90
"__*_S.FP64S.FP64":                     ## @"_*_S.FP64S.FP64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	mulsd	%xmm1, %xmm0
	popq	%rbp
	retq

	.globl	"__/_S.FP64S.FP64"
	.align	4, 0x90
"__/_S.FP64S.FP64":                     ## @"_/_S.FP64S.FP64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	divsd	%xmm1, %xmm0
	popq	%rbp
	retq

	.globl	"__%_S.FP64S.FP64"
	.align	4, 0x90
"__%_S.FP64S.FP64":                     ## @"_%_S.FP64S.FP64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	jmp	_fmod                   ## TAILCALL

	.globl	"__<_S.FP64S.FP64"
	.align	4, 0x90
"__<_S.FP64S.FP64":                     ## @"_<_S.FP64S.FP64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ucomisd	%xmm0, %xmm1
	seta	%al
	popq	%rbp
	retq

	.globl	"__<=_S.FP64S.FP64"
	.align	4, 0x90
"__<=_S.FP64S.FP64":                    ## @"_<=_S.FP64S.FP64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ucomisd	%xmm0, %xmm1
	setae	%al
	popq	%rbp
	retq

	.globl	"__>_S.FP64S.FP64"
	.align	4, 0x90
"__>_S.FP64S.FP64":                     ## @"_>_S.FP64S.FP64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ucomisd	%xmm1, %xmm0
	seta	%al
	popq	%rbp
	retq

	.globl	"__>=_S.FP64S.FP64"
	.align	4, 0x90
"__>=_S.FP64S.FP64":                    ## @"_>=_S.FP64S.FP64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ucomisd	%xmm1, %xmm0
	setae	%al
	popq	%rbp
	retq

	.globl	"__==_S.FP64S.FP64"
	.align	4, 0x90
"__==_S.FP64S.FP64":                    ## @"_==_S.FP64S.FP64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpeqsd	%xmm1, %xmm0
	movd	%xmm0, %rax
	andl	$1, %eax
                                        ## kill: AL<def> AL<kill> RAX<kill>
	popq	%rbp
	retq

	.globl	"__!=_S.FP64S.FP64"
	.align	4, 0x90
"__!=_S.FP64S.FP64":                    ## @"_!=_S.FP64S.FP64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ucomisd	%xmm1, %xmm0
	setne	%al
	popq	%rbp
	retq

	.globl	__..._S.i64S.i64
	.align	4, 0x90
__..._S.i64S.i64:                       ## @_..._S.i64S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq

	.globl	"__..<_S.i64S.i64"
	.align	4, 0x90
"__..<_S.i64S.i64":                     ## @"_..<_S.i64S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	leaq	-1(%rsi), %rdx
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r14
	pushq	%rbx
	movl	$4, %ebx
	.align	4, 0x90
LBB44_1:                                ## %loop
                                        ## =>This Inner Loop Header: Depth=1
	movq	%rbx, %rdi
	leaq	1(%rbx), %rbx
	callq	__$print_i64
	cmpq	$100, %rbx
	jl	LBB44_1
## BB#2:                                ## %afterloop
	movq	%rsp, %rax
	leaq	-16(%rax), %r14
	movq	%r14, %rsp
	movq	$1000, -16(%rax)        ## imm = 0x3E8
	.align	4, 0x90
LBB44_3:                                ## %loop5
                                        ## =>This Inner Loop Header: Depth=1
	movq	(%r14), %rbx
	movq	%rbx, %rdi
	callq	__$print_i64
	addq	$-100, %rbx
	movq	%rbx, (%r14)
	testq	%rbx, %rbx
	jg	LBB44_3
## BB#4:                                ## %afterloop6
	cmpq	$1000, (%r14)           ## imm = 0x3E8
	jge	LBB44_6
## BB#5:                                ## %then0
	movl	$100000, %edi           ## imm = 0x186A0
	callq	__$print_i64
LBB44_6:                                ## %cont
	xorl	%eax, %eax
	leaq	-16(%rbp), %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%lli\n"

L_.str1:                                ## @.str1
	.asciz	"%i\n"

L_.str2:                                ## @.str2
	.asciz	"%f\n"

L_str:                                  ## @str
	.asciz	"false"

L_str1:                                 ## @str1
	.asciz	"true"


.subsections_via_symbols
