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
	movl	$10, %eax
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
	xorl	%ebx, %ebx
	xorl	%eax, %eax
	callq	_printf
	testb	%bl, %bl
	movl	$0, %ecx
	jne	LBB2_7
## BB#4:                                ## %overflow.checked
	xorl	%ecx, %ecx
	movabsq	$-6148914691236517205, %r8 ## imm = 0xAAAAAAAAAAAAAAAB
	movabsq	$-3689348814741910323, %r9 ## imm = 0xCCCCCCCCCCCCCCCD
	xorl	%eax, %eax
	xorl	%ebx, %ebx
	.align	4, 0x90
LBB2_5:                                 ## %vector.body
                                        ## =>This Inner Loop Header: Depth=1
	movq	%rbx, %r10
	movq	%rax, %rdi
	leaq	1(%rcx), %rsi
	movq	%rcx, %rax
	mulq	%r8
	shrq	%rdx
	leaq	(%rdx,%rdx,2), %rbx
	movq	%rsi, %rax
	mulq	%r8
	shrq	%rdx
	leaq	(%rdx,%rdx,2), %rax
	cmpq	%rbx, %rcx
	setne	%r11b
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
	setne	%sil
	leaq	(%rcx,%rdi), %rax
	leaq	1(%rcx,%r10), %rbx
	testb	%dl, %r11b
	cmovneq	%rdi, %rax
	testb	%sil, %r14b
	cmovneq	%r10, %rbx
	addq	$2, %rcx
	cmpq	$10000, %rcx            ## imm = 0x2710
	jne	LBB2_5
## BB#6:                                ## %middle.block
	addq	%rax, %rbx
	movl	$10000, %ecx            ## imm = 0x2710
	xorl	%eax, %eax
	testb	%al, %al
	jne	LBB2_10
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
	je	LBB2_11
## BB#8:                                ## %loop
                                        ##   in Loop: Header=BB2_7 Depth=1
	shrq	$2, %rdx
	leaq	(%rdx,%rdx,4), %rax
	movq	%rcx, %rdx
	subq	%rax, %rdx
	jne	LBB2_9
LBB2_11:                                ## %then0
                                        ##   in Loop: Header=BB2_7 Depth=1
	addq	%rcx, %rbx
LBB2_9:                                 ## %cont
                                        ##   in Loop: Header=BB2_7 Depth=1
	cmpq	$10001, %rsi            ## imm = 0x2711
	movq	%rsi, %rcx
	jl	LBB2_7
LBB2_10:                                ## %afterloop
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movq	%rbx, %rsi
	callq	_printf
	xorl	%eax, %eax
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_foo
	.align	4, 0x90
_foo:                                   ## @foo
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp11:
	.cfi_def_cfa_offset 16
Ltmp12:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp13:
	.cfi_def_cfa_register %rbp
	leaq	(%rdi,%rsi), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_bar
	.align	4, 0x90
_bar:                                   ## @bar
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp14:
	.cfi_def_cfa_offset 16
Ltmp15:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp16:
	.cfi_def_cfa_register %rbp
	movq	%rdi, %rcx
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movq	%rcx, %rsi
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	_fact
	.align	4, 0x90
_fact:                                  ## @fact
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp17:
	.cfi_def_cfa_offset 16
Ltmp18:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp19:
	.cfi_def_cfa_register %rbp
	movl	$1, %eax
	jmp	LBB5_1
	.align	4, 0x90
LBB5_3:                                 ## %else1
                                        ##   in Loop: Header=BB5_1 Depth=1
	imulq	%rdi, %rax
	decq	%rdi
LBB5_1:                                 ## %tailrecurse
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$1, %rdi
	jg	LBB5_3
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
