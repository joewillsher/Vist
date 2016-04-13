	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_Gen_tI
	.align	4, 0x90
_Gen_tI:                                ## @Gen_tI
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_generate_mGenPtI
	.align	4, 0x90
_generate_mGenPtI:                      ## @generate_mGenPtI
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
	movq	(%rdi), %rdi
	popq	%rbp
	jmpq	*%rsi  # TAILCALL
	.cfi_endproc

	.globl	_loop_thunk
	.align	4, 0x90
_loop_thunk:                            ## @loop_thunk
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
	jmp	_print_tI               ## TAILCALL
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
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
	movl	$1, %eax
	movl	%eax, %edi
	popq	%rbp
	jmp	_print_tI               ## TAILCALL
	.cfi_endproc


.subsections_via_symbols
