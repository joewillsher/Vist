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
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
Ltmp9:
	.cfi_offset %rbx, -48
Ltmp10:
	.cfi_offset %r12, -40
Ltmp11:
	.cfi_offset %r14, -32
Ltmp12:
	.cfi_offset %r15, -24
	movl	$100, %eax
	movl	$1, %esi
	jmp	LBB2_1
	.align	4, 0x90
LBB2_2:                                 ## %cont0.i
                                        ##   in Loop: Header=BB2_1 Depth=1
	imulq	%rax, %rsi
	decq	%rax
LBB2_1:                                 ## %tailrecurse.i
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$2, %rax
	jge	LBB2_2
## BB#3:                                ## %fact.exit
	leaq	L_.str(%rip), %rdi
	xorl	%r15d, %r15d
	xorl	%eax, %eax
	callq	_printf
	testb	%r15b, %r15b
	movl	$0, %ecx
	jne	LBB2_7
## BB#4:                                ## %overflow.checked
	xorl	%ecx, %ecx
	movabsq	$-6148914691236517205, %r8 ## imm = 0xAAAAAAAAAAAAAAAB
	movabsq	$-3689348814741910323, %r9 ## imm = 0xCCCCCCCCCCCCCCCD
	xorl	%eax, %eax
	xorl	%r15d, %r15d
	.align	4, 0x90
LBB2_5:                                 ## %vector.body
                                        ## =>This Inner Loop Header: Depth=1
	movq	%r15, %r10
	movq	%rax, %r12
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
	setne	%r14b
	cmpq	%rax, %rsi
	setne	%r11b
	movq	%rcx, %rax
	mulq	%r9
	shrq	$2, %rdx
	leaq	(%rdx,%rdx,4), %rdi
	movq	%rsi, %rax
	mulq	%r9
	shrq	$2, %rdx
	leaq	(%rdx,%rdx,4), %rax
	cmpq	%rdi, %rcx
	setne	%dl
	cmpq	%rax, %rsi
	setne	%bl
	leaq	(%rcx,%r12), %rax
	leaq	1(%rcx,%r10), %r15
	testb	%dl, %r14b
	cmovneq	%r12, %rax
	testb	%bl, %r11b
	cmovneq	%r10, %r15
	addq	$2, %rcx
	cmpq	$100000000, %rcx        ## imm = 0x5F5E100
	jne	LBB2_5
## BB#6:                                ## %middle.block
	addq	%rax, %r15
	movl	$100000000, %ecx        ## imm = 0x5F5E100
	xorl	%eax, %eax
	testb	%al, %al
	jne	LBB2_11
	.align	4, 0x90
LBB2_7:                                 ## %loop
                                        ## =>This Inner Loop Header: Depth=1
	leaq	1(%rcx), %rsi
	movabsq	$-6148914691236517205, %rdx ## imm = 0xAAAAAAAAAAAAAAAB
	movq	%rcx, %rax
	mulq	%rdx
	shrq	%rdx
	leaq	(%rdx,%rdx,2), %rdi
	movabsq	$-3689348814741910323, %rdx ## imm = 0xCCCCCCCCCCCCCCCD
	movq	%rcx, %rax
	mulq	%rdx
	cmpq	%rdi, %rcx
	je	LBB2_9
## BB#8:                                ## %loop
                                        ##   in Loop: Header=BB2_7 Depth=1
	shrq	$2, %rdx
	leaq	(%rdx,%rdx,4), %rax
	movq	%rcx, %rdx
	subq	%rax, %rdx
	jne	LBB2_10
LBB2_9:                                 ## %then0
                                        ##   in Loop: Header=BB2_7 Depth=1
	addq	%rcx, %r15
LBB2_10:                                ## %cont
                                        ##   in Loop: Header=BB2_7 Depth=1
	cmpq	$100000001, %rsi        ## imm = 0x5F5E101
	movq	%rsi, %rcx
	jl	LBB2_7
LBB2_11:                                ## %afterloop
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movq	%r15, %rsi
	callq	_printf
	cmpq	$1, %r15
	jle	LBB2_14
## BB#12:
	leaq	L_.str(%rip), %r14
	.align	4, 0x90
LBB2_13:                                ## %loop6
                                        ## =>This Inner Loop Header: Depth=1
	movq	%r15, %rbx
	shrq	%rbx
	xorl	%eax, %eax
	movq	%r14, %rdi
	movq	%rbx, %rsi
	callq	_printf
	cmpq	$3, %r15
	movq	%rbx, %r15
	ja	LBB2_13
LBB2_14:                                ## %afterloop7
	xorl	%eax, %eax
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_fact
	.align	4, 0x90
_fact:                                  ## @fact
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp13:
	.cfi_def_cfa_offset 16
Ltmp14:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp15:
	.cfi_def_cfa_register %rbp
	movl	$1, %eax
	jmp	LBB3_1
	.align	4, 0x90
LBB3_3:                                 ## %else1
                                        ##   in Loop: Header=BB3_1 Depth=1
	imulq	%rdi, %rax
	decq	%rdi
LBB3_1:                                 ## %tailrecurse
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$1, %rdi
	jg	LBB3_3
## BB#2:                                ## %then0
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%llu\n"

L_.str1:                                ## @.str1
	.asciz	"%f\n"


.subsections_via_symbols
