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

	.globl	__$print_f64
	.align	4, 0x90
__$print_f64:                           ## @"_$print_f64"
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

	.globl	__$print_f32
	.align	4, 0x90
__$print_f32:                           ## @"_$print_f32"
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

	.globl	__Int_
	.align	4, 0x90
__Int_:                                 ## @_Int_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
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

	.globl	__Bool_
	.align	4, 0x90
__Bool_:                                ## @_Bool_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
	popq	%rbp
	retq

	.globl	__Double_S.f64
	.align	4, 0x90
__Double_S.f64:                         ## @_Double_S.f64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	retq

	.globl	__Double_f64
	.align	4, 0x90
__Double_f64:                           ## @_Double_f64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	retq

	.globl	__Range_S.i64_S.i64
	.align	4, 0x90
__Range_S.i64_S.i64:                    ## @_Range_S.i64_S.i64
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

	.globl	__print_S.f64
	.align	4, 0x90
__print_S.f64:                          ## @_print_S.f64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	jmp	__$print_f64            ## TAILCALL

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
	je	LBB19_2
## BB#1:                                ## %then0
	popq	%rbp
	retq
LBB19_2:                                ## %else1
	callq	__$fatalError_
	.cfi_endproc

	.globl	__condFail_b
	.align	4, 0x90
__condFail_b:                           ## @_condFail_b
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
	testb	$1, %dil
	jne	LBB20_2
## BB#1:                                ## %cont
	popq	%rbp
	retq
LBB20_2:                                ## %then0
	callq	__$fatalError_
	.cfi_endproc

	.globl	"__+_S.i64_S.i64"
	.align	4, 0x90
"__+_S.i64_S.i64":                      ## @"_+_S.i64_S.i64"
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
	addq	%rsi, %rdi
	jo	LBB21_2
## BB#1:                                ## %_condFail_b.exit
	movq	%rdi, %rax
	popq	%rbp
	retq
LBB21_2:                                ## %then0.i
	callq	__$fatalError_
	.cfi_endproc

	.globl	"__-_S.i64_S.i64"
	.align	4, 0x90
"__-_S.i64_S.i64":                      ## @_-_S.i64_S.i64
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
	subq	%rsi, %rdi
	jo	LBB22_2
## BB#1:                                ## %_condFail_b.exit
	movq	%rdi, %rax
	popq	%rbp
	retq
LBB22_2:                                ## %then0.i
	callq	__$fatalError_
	.cfi_endproc

	.globl	"__*_S.i64_S.i64"
	.align	4, 0x90
"__*_S.i64_S.i64":                      ## @"_*_S.i64_S.i64"
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
	imulq	%rsi, %rdi
	jo	LBB23_2
## BB#1:                                ## %_condFail_b.exit
	movq	%rdi, %rax
	popq	%rbp
	retq
LBB23_2:                                ## %then0.i
	callq	__$fatalError_
	.cfi_endproc

	.globl	"__/_S.i64_S.i64"
	.align	4, 0x90
"__/_S.i64_S.i64":                      ## @"_/_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%rsi
	popq	%rbp
	retq

	.globl	"__%_S.i64_S.i64"
	.align	4, 0x90
"__%_S.i64_S.i64":                      ## @"_%_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%rsi
	movq	%rdx, %rax
	popq	%rbp
	retq

	.globl	"__<_S.i64_S.i64"
	.align	4, 0x90
"__<_S.i64_S.i64":                      ## @"_<_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	setl	%al
	popq	%rbp
	retq

	.globl	"__<=_S.i64_S.i64"
	.align	4, 0x90
"__<=_S.i64_S.i64":                     ## @"_<=_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	setle	%al
	popq	%rbp
	retq

	.globl	"__>_S.i64_S.i64"
	.align	4, 0x90
"__>_S.i64_S.i64":                      ## @"_>_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	setg	%al
	popq	%rbp
	retq

	.globl	"__>=_S.i64_S.i64"
	.align	4, 0x90
"__>=_S.i64_S.i64":                     ## @"_>=_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	setge	%al
	popq	%rbp
	retq

	.globl	"__==_S.i64_S.i64"
	.align	4, 0x90
"__==_S.i64_S.i64":                     ## @"_==_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	sete	%al
	popq	%rbp
	retq

	.globl	"__!=_S.i64_S.i64"
	.align	4, 0x90
"__!=_S.i64_S.i64":                     ## @"_!=_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rsi, %rdi
	setne	%al
	popq	%rbp
	retq

	.globl	"__&&_S.b_S.b"
	.align	4, 0x90
"__&&_S.b_S.b":                         ## @"_&&_S.b_S.b"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	andl	%esi, %edi
	movb	%dil, %al
	popq	%rbp
	retq

	.globl	"__||_S.b_S.b"
	.align	4, 0x90
"__||_S.b_S.b":                         ## @"_||_S.b_S.b"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	orl	%esi, %edi
	movb	%dil, %al
	popq	%rbp
	retq

	.globl	"__+_S.f64_S.f64"
	.align	4, 0x90
"__+_S.f64_S.f64":                      ## @"_+_S.f64_S.f64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	addsd	%xmm1, %xmm0
	popq	%rbp
	retq

	.globl	"__-_S.f64_S.f64"
	.align	4, 0x90
"__-_S.f64_S.f64":                      ## @_-_S.f64_S.f64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subsd	%xmm1, %xmm0
	popq	%rbp
	retq

	.globl	"__*_S.f64_S.f64"
	.align	4, 0x90
"__*_S.f64_S.f64":                      ## @"_*_S.f64_S.f64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	mulsd	%xmm1, %xmm0
	popq	%rbp
	retq

	.globl	"__/_S.f64_S.f64"
	.align	4, 0x90
"__/_S.f64_S.f64":                      ## @"_/_S.f64_S.f64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	divsd	%xmm1, %xmm0
	popq	%rbp
	retq

	.globl	"__%_S.f64_S.f64"
	.align	4, 0x90
"__%_S.f64_S.f64":                      ## @"_%_S.f64_S.f64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	jmp	_fmod                   ## TAILCALL

	.globl	"__<_S.f64_S.f64"
	.align	4, 0x90
"__<_S.f64_S.f64":                      ## @"_<_S.f64_S.f64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ucomisd	%xmm0, %xmm1
	seta	%al
	popq	%rbp
	retq

	.globl	"__<=_S.f64_S.f64"
	.align	4, 0x90
"__<=_S.f64_S.f64":                     ## @"_<=_S.f64_S.f64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ucomisd	%xmm0, %xmm1
	setae	%al
	popq	%rbp
	retq

	.globl	"__>_S.f64_S.f64"
	.align	4, 0x90
"__>_S.f64_S.f64":                      ## @"_>_S.f64_S.f64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ucomisd	%xmm1, %xmm0
	seta	%al
	popq	%rbp
	retq

	.globl	"__>=_S.f64_S.f64"
	.align	4, 0x90
"__>=_S.f64_S.f64":                     ## @"_>=_S.f64_S.f64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ucomisd	%xmm1, %xmm0
	setae	%al
	popq	%rbp
	retq

	.globl	"__==_S.f64_S.f64"
	.align	4, 0x90
"__==_S.f64_S.f64":                     ## @"_==_S.f64_S.f64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	cmpeqsd	%xmm1, %xmm0
	movd	%xmm0, %rax
	andl	$1, %eax
                                        ## kill: AL<def> AL<kill> RAX<kill>
	popq	%rbp
	retq

	.globl	"__!=_S.f64_S.f64"
	.align	4, 0x90
"__!=_S.f64_S.f64":                     ## @"_!=_S.f64_S.f64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ucomisd	%xmm1, %xmm0
	setne	%al
	popq	%rbp
	retq

	.globl	__..._S.i64_S.i64
	.align	4, 0x90
__..._S.i64_S.i64:                      ## @_..._S.i64_S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq

	.globl	"__..<_S.i64_S.i64"
	.align	4, 0x90
"__..<_S.i64_S.i64":                    ## @"_..<_S.i64_S.i64"
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
	decq	%rsi
	jo	LBB46_2
## BB#1:                                ## %_-_S.i64_S.i64.exit
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq
LBB46_2:                                ## %then0.i.i
	callq	__$fatalError_
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:                                ## %_Foo.sum_S.i64.exit
	pushq	%rbp
Ltmp39:
	.cfi_def_cfa_offset 16
Ltmp40:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp41:
	.cfi_def_cfa_register %rbp
	movl	$10, %edi
	callq	__$print_i64
	movl	$140, %edi
	callq	__$print_i64
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Foo_
	.align	4, 0x90
__Foo_:                                 ## @_Foo_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$10, %eax
	movl	$20, %edx
	movl	$40, %ecx
	popq	%rbp
	retq

	.globl	__Foo.sum_S.i64
	.align	4, 0x90
__Foo.sum_S.i64:                        ## @_Foo.sum_S.i64
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
	addq	%rdx, %rsi
	jo	LBB49_4
## BB#1:                                ## %_+_S.i64_S.i64.exit
	addq	%rsi, %rdi
	jo	LBB49_4
## BB#2:                                ## %_+_S.i64_S.i64.exit8
	imulq	%rcx, %rdi
	jo	LBB49_4
## BB#3:                                ## %_*_S.i64_S.i64.exit
	movq	%rdi, %rax
	popq	%rbp
	retq
LBB49_4:                                ## %then0.i.i11
	callq	__$fatalError_
	.cfi_endproc

	.globl	__Foo.sum_S.b
	.align	4, 0x90
__Foo.sum_S.b:                          ## @_Foo.sum_S.b
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	testb	$1, %cl
	je	LBB50_1
## BB#2:                                ## %then0
	popq	%rbp
	jmp	__$print_i64            ## TAILCALL
LBB50_1:                                ## %cont
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
