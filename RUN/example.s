	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_Bool_
	.align	4, 0x90
_Bool_:                                 ## @Bool_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
	movb	%al, %cl
	movb	%cl, %al
	popq	%rbp
	retq

	.globl	_print_Bool
	.align	4, 0x90
_print_Bool:                            ## @print_Bool
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
	movb	%dil, %al
	movzbl	%al, %edi
	popq	%rbp
	jmp	"_-Uprint_b"            ## TAILCALL
	.cfi_endproc

	.globl	_condFail_b
	.align	4, 0x90
_condFail_b:                            ## @condFail_b
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	retq

	.globl	"_-E-E_Int_Int"
	.align	4, 0x90
"_-E-E_Int_Int":                        ## @-E-E_Int_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	%rsi, %rdi
	sete	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	popq	%rbp
	retq

	.globl	_Bool_b
	.align	4, 0x90
_Bool_b:                                ## @Bool_b
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	popq	%rbp
	retq

	.globl	_print_Int32
	.align	4, 0x90
_print_Int32:                           ## @print_Int32
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
	popq	%rbp
	jmp	"_-Uprint_i32"          ## TAILCALL
	.cfi_endproc

	.globl	"_-P_Int_Int"
	.align	4, 0x90
"_-P_Int_Int":                          ## @-P_Int_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	addq	%rsi, %rdi
	seto	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movb	%al, -9(%rbp)           ## 1-byte Spill
	jo	LBB6_2
## BB#1:                                ## %entry.cont
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq
LBB6_2:                                 ## %+.trap
	ud2

	.globl	"_-M_Int_Int"
	.align	4, 0x90
"_-M_Int_Int":                          ## @-M_Int_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	%rsi, %rdi
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_Range_Int_Int
	.align	4, 0x90
_Range_Int_Int:                         ## @Range_Int_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq

	.globl	"_-A_Int_Int"
	.align	4, 0x90
"_-A_Int_Int":                          ## @-A_Int_Int
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	imulq	%rdi, %rsi
	movq	%rsi, %rax
	popq	%rbp
	retq

	.globl	_Int_i64
	.align	4, 0x90
_Int_i64:                               ## @Int_i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_print_Double
	.align	4, 0x90
_print_Double:                          ## @print_Double
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
	popq	%rbp
	jmp	"_-Uprint_f64"          ## TAILCALL
	.cfi_endproc

	.globl	_Int32_i32
	.align	4, 0x90
_Int32_i32:                             ## @Int32_i32
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, %eax
	popq	%rbp
	retq

	.globl	_Int_
	.align	4, 0x90
_Int_:                                  ## @Int_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
                                        ## kill: RAX<def> EAX<kill>
	popq	%rbp
	retq

	.globl	_Double_f64
	.align	4, 0x90
_Double_f64:                            ## @Double_f64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	retq

	.globl	"_-Uexpect_Bool_Bool"
	.align	4, 0x90
"_-Uexpect_Bool_Bool":                  ## @-Uexpect_Bool_Bool
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	popq	%rbp
	retq

	.globl	_fatalError_
	.align	4, 0x90
_fatalError_:                           ## @fatalError_
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	retq

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	retq

	.globl	_print_Int
	.align	4, 0x90
_print_Int:                             ## @print_Int
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
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL
	.cfi_endproc

	.globl	_assert_Bool
	.align	4, 0x90
_assert_Bool:                           ## @assert_Bool
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	retq


.subsections_via_symbols
