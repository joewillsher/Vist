	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_print
	.align	4, 0x90
_print:                                 ## @print
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

	.globl	_printd
	.align	4, 0x90
_printd:                                ## @printd
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
	leaq	L_.str1(%rip), %rdi
	movb	$1, %al
	popq	%rbp
	jmp	_printf                 ## TAILCALL
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
	pushq	%r14
	pushq	%rbx
Ltmp9:
	.cfi_offset %rbx, -32
Ltmp10:
	.cfi_offset %r14, -24
	xorl	%esi, %esi
	testb	%sil, %sil
	movl	$0, %ecx
	jne	LBB2_4
## BB#1:                                ## %overflow.checked
	xorl	%ecx, %ecx
	movabsq	$-6148914691236517205, %r8 ## imm = 0xAAAAAAAAAAAAAAAB
	movabsq	$-3689348814741910323, %r9 ## imm = 0xCCCCCCCCCCCCCCCD
	xorl	%eax, %eax
	xorl	%esi, %esi
	.align	4, 0x90
LBB2_2:                                 ## %vector.body
                                        ## =>This Inner Loop Header: Depth=1
	movq	%rsi, %r10
	movq	%rax, %r11
	leaq	1(%rcx), %rsi
	movq	%rcx, %rax
	mulq	%r8
	shrq	%rdx
	leaq	(%rdx,%rdx,2), %rdi
	movq	%rsi, %rax
	mulq	%r8
	shrq	%rdx
	leaq	(%rdx,%rdx,2), %rax
	cmpq	%rdi, %rcx
	setne	%dil
	cmpq	%rax, %rsi
	setne	%r14b
	movq	%rcx, %rax
	mulq	%r9
	shrq	$2, %rdx
	leaq	(%rdx,%rdx,4), %rbx
	movq	%rsi, %rax
	mulq	%r9
	shrq	$2, %rdx
	leaq	(%rdx,%rdx,4), %rax
	cmpq	%rbx, %rcx
	setne	%dl
	cmpq	%rax, %rsi
	setne	%bl
	leaq	(%rcx,%r11), %rax
	leaq	1(%rcx,%r10), %rsi
	testb	%dl, %dil
	cmovneq	%r11, %rax
	testb	%bl, %r14b
	cmovneq	%r10, %rsi
	addq	$2, %rcx
	cmpq	$100000000, %rcx        ## imm = 0x5F5E100
	jne	LBB2_2
## BB#3:                                ## %middle.block
	addq	%rax, %rsi
	movl	$100000000, %ecx        ## imm = 0x5F5E100
	xorl	%eax, %eax
	testb	%al, %al
	jne	LBB2_7
	.align	4, 0x90
LBB2_4:                                 ## %loop
                                        ## =>This Inner Loop Header: Depth=1
	leaq	1(%rcx), %rdi
	movabsq	$-6148914691236517205, %rdx ## imm = 0xAAAAAAAAAAAAAAAB
	movq	%rcx, %rax
	mulq	%rdx
	shrq	%rdx
	leaq	(%rdx,%rdx,2), %rbx
	movabsq	$-3689348814741910323, %rdx ## imm = 0xCCCCCCCCCCCCCCCD
	movq	%rcx, %rax
	mulq	%rdx
	cmpq	%rbx, %rcx
	je	LBB2_8
## BB#5:                                ## %loop
                                        ##   in Loop: Header=BB2_4 Depth=1
	shrq	$2, %rdx
	leaq	(%rdx,%rdx,4), %rax
	movq	%rcx, %rdx
	subq	%rax, %rdx
	jne	LBB2_6
LBB2_8:                                 ## %then0
                                        ##   in Loop: Header=BB2_4 Depth=1
	addq	%rcx, %rsi
LBB2_6:                                 ## %cont
                                        ##   in Loop: Header=BB2_4 Depth=1
	cmpq	$100000001, %rdi        ## imm = 0x5F5E101
	movq	%rdi, %rcx
	jl	LBB2_4
LBB2_7:                                 ## %afterloop
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%llu\n"

L_.str1:                                ## @.str1
	.asciz	"%f\n"


.subsections_via_symbols
