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
	leaq	L_.str(%rip), %rax
	xorl	%ecx, %ecx
	movb	%cl, %dl
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rax, %rdi
	movq	-8(%rbp), %rsi          ## 8-byte Reload
	movb	%dl, %al
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
	leaq	L_.str1(%rip), %rax
	xorl	%ecx, %ecx
	movb	%cl, %dl
	movl	%edi, -4(%rbp)          ## 4-byte Spill
	movq	%rax, %rdi
	movl	-4(%rbp), %esi          ## 4-byte Reload
	movb	%dl, %al
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
	subq	$16, %rsp
	movb	%dil, %al
	testb	$1, %al
	jne	LBB4_1
	jmp	LBB4_2
LBB4_1:
	leaq	L_str1(%rip), %rdi
	callq	_puts
	movl	%eax, -4(%rbp)          ## 4-byte Spill
	jmp	LBB4_3
LBB4_2:
	leaq	L_str(%rip), %rdi
	callq	_puts
	movl	%eax, -8(%rbp)          ## 4-byte Spill
LBB4_3:
	addq	$16, %rsp
	popq	%rbp
	retq
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
                                        ## kill: RAX<def> EAX<kill>
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
	movb	%al, %cl
	movb	%cl, %al
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
	movb	%dil, %al
	movzbl	%al, %edi
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
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	ud2

	.globl	__assert_S.b
	.align	4, 0x90
__assert_S.b:                           ## @_assert_S.b
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	testb	$1, %al
	jne	LBB18_1
	jmp	LBB18_2
LBB18_1:                                ## %then0
	popq	%rbp
	retq
LBB18_2:                                ## %else1
	ud2

	.globl	__condFail_b
	.align	4, 0x90
__condFail_b:                           ## @_condFail_b
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	testb	$1, %al
	jne	LBB19_2
	jmp	LBB19_1
LBB19_1:                                ## %cont
	popq	%rbp
	retq
LBB19_2:                                ## %then0
	ud2

	.globl	"__+_S.i64_S.i64"
	.align	4, 0x90
"__+_S.i64_S.i64":                      ## @"_+_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	addq	%rsi, %rdi
	seto	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movb	%al, -9(%rbp)           ## 1-byte Spill
	jo	LBB20_1
	jmp	LBB20_2
LBB20_1:                                ## %then0.i
	ud2
LBB20_2:                                ## %_condFail_b.exit
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq

	.globl	"__-_S.i64_S.i64"
	.align	4, 0x90
"__-_S.i64_S.i64":                      ## @_-_S.i64_S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	%rsi, %rdi
	seto	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movb	%al, -9(%rbp)           ## 1-byte Spill
	jo	LBB21_1
	jmp	LBB21_2
LBB21_1:                                ## %then0.i
	ud2
LBB21_2:                                ## %_condFail_b.exit
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq

	.globl	"__*_S.i64_S.i64"
	.align	4, 0x90
"__*_S.i64_S.i64":                      ## @"_*_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	imulq	%rsi, %rdi
	seto	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movb	%al, -9(%rbp)           ## 1-byte Spill
	jo	LBB22_1
	jmp	LBB22_2
LBB22_1:                                ## %then0.i
	ud2
LBB22_2:                                ## %_condFail_b.exit
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq

	.globl	"__/_S.i64_S.i64"
	.align	4, 0x90
"__/_S.i64_S.i64":                      ## @"_/_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
	movl	%eax, %edx
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
	xorl	%eax, %eax
	movl	%eax, %edx
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
	subq	%rsi, %rdi
	setl	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	popq	%rbp
	retq

	.globl	"__<=_S.i64_S.i64"
	.align	4, 0x90
"__<=_S.i64_S.i64":                     ## @"_<=_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	%rsi, %rdi
	setle	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	popq	%rbp
	retq

	.globl	"__>_S.i64_S.i64"
	.align	4, 0x90
"__>_S.i64_S.i64":                      ## @"_>_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	%rsi, %rdi
	setg	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	popq	%rbp
	retq

	.globl	"__>=_S.i64_S.i64"
	.align	4, 0x90
"__>=_S.i64_S.i64":                     ## @"_>=_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	%rsi, %rdi
	setge	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	popq	%rbp
	retq

	.globl	"__==_S.i64_S.i64"
	.align	4, 0x90
"__==_S.i64_S.i64":                     ## @"_==_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	%rsi, %rdi
	sete	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	popq	%rbp
	retq

	.globl	"__!=_S.i64_S.i64"
	.align	4, 0x90
"__!=_S.i64_S.i64":                     ## @"_!=_S.i64_S.i64"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	%rsi, %rdi
	setne	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	popq	%rbp
	retq

	.globl	"__&&_S.b_S.b"
	.align	4, 0x90
"__&&_S.b_S.b":                         ## @"_&&_S.b_S.b"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%sil, %al
	movb	%dil, %cl
	andb	%al, %cl
	movb	%cl, %al
	popq	%rbp
	retq

	.globl	"__||_S.b_S.b"
	.align	4, 0x90
"__||_S.b_S.b":                         ## @"_||_S.b_S.b"
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%sil, %al
	movb	%dil, %cl
	orb	%al, %cl
	movb	%cl, %al
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
	movl	%eax, %ecx
	andl	$1, %ecx
	movb	%cl, %dl
	movb	%dl, %al
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
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	decq	%rsi
	seto	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rsi, -16(%rbp)         ## 8-byte Spill
	movb	%al, -17(%rbp)          ## 1-byte Spill
	jo	LBB45_1
	jmp	LBB45_2
LBB45_1:                                ## %then0.i.i
	ud2
LBB45_2:                                ## %_-_S.i64_S.i64.exit
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	-16(%rbp), %rdx         ## 8-byte Reload
	popq	%rbp
	retq

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movl	$1, %eax
	movl	%eax, %ecx
	movq	%rcx, -8(%rbp)          ## 8-byte Spill
	jmp	LBB46_1
LBB46_1:                                ## %loop.header
                                        ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movl	$2, %ecx
	movl	%ecx, %edx
	movq	%rax, %rsi
	imulq	%rdx, %rsi
	seto	%dil
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	movq	%rsi, -24(%rbp)         ## 8-byte Spill
	movb	%dil, -25(%rbp)         ## 1-byte Spill
	jo	LBB46_2
	jmp	LBB46_3
LBB46_2:                                ## %then0.i.i
	ud2
LBB46_3:                                ## %_*_S.i64_S.i64.exit
                                        ##   in Loop: Header=BB46_1 Depth=1
	movq	-16(%rbp), %rax         ## 8-byte Reload
	addq	$1, %rax
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, -40(%rbp)         ## 8-byte Spill
	callq	__$print_i64
	movq	-16(%rbp), %rax         ## 8-byte Reload
	cmpq	$999999, %rax           ## imm = 0xF423F
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	jle	LBB46_1
## BB#4:                                ## %loop.exit
	xorl	%eax, %eax
                                        ## kill: RAX<def> EAX<kill>
	addq	$48, %rsp
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
