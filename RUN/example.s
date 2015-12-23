	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_printStr
	.align	4, 0x90
_printStr:                              ## @printStr
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
	leaq	L_str(%rip), %rdi
	popq	%rbp
	jmp	_puts                   ## TAILCALL
	.cfi_endproc

	.globl	_print
	.align	4, 0x90
_print:                                 ## @print
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
	movq	%rdi, %rcx
	leaq	L_.str1(%rip), %rdi
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

	.globl	_memcpy
	.align	4, 0x90
_memcpy:                                ## @memcpy
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
	pushq	%rbx
	pushq	%rax
Ltmp12:
	.cfi_offset %rbx, -24
	movq	%rdi, %rbx
                                        ## kill: RDI<def> RBX<kill>
	callq	_memcpy
	movq	%rbx, %rax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
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
	pushq	%r14
	pushq	%rbx
	subq	$80, %rsp
Ltmp16:
	.cfi_offset %rbx, -32
Ltmp17:
	.cfi_offset %r14, -24
	movq	___stack_chk_guard@GOTPCREL(%rip), %r14
	movq	(%r14), %r14
	movq	%r14, -24(%rbp)
	movq	$0, -96(%rbp)
	movq	$1, -88(%rbp)
	movq	$2, -80(%rbp)
	movq	$3, -72(%rbp)
	movq	$4, -64(%rbp)
	movq	$5, -56(%rbp)
	movq	$6, -48(%rbp)
	movq	$7, -40(%rbp)
	movq	$8, -32(%rbp)
	xorl	%eax, %eax
	movl	$1, %ecx
	jmp	LBB4_1
	.align	4, 0x90
LBB4_2:                                 ## %cont0.i
                                        ##   in Loop: Header=BB4_1 Depth=1
	imulq	%rax, %rcx
	decq	%rax
LBB4_1:                                 ## %tailrecurse.i
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$2, %rax
	jge	LBB4_2
## BB#3:                                ## %fact.exit
	movq	%rcx, -96(%rbp)
	movl	$1, %eax
	movl	$1, %ecx
	jmp	LBB4_4
	.align	4, 0x90
LBB4_5:                                 ## %cont0.i5
                                        ##   in Loop: Header=BB4_4 Depth=1
	imulq	%rcx, %rax
	decq	%rcx
LBB4_4:                                 ## %tailrecurse.i4
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$2, %rcx
	jge	LBB4_5
## BB#6:                                ## %fact.exit8
	movq	%rax, -88(%rbp)
	movl	$2, %eax
	movl	$1, %ecx
	jmp	LBB4_7
	.align	4, 0x90
LBB4_8:                                 ## %cont0.i13
                                        ##   in Loop: Header=BB4_7 Depth=1
	imulq	%rax, %rcx
	decq	%rax
LBB4_7:                                 ## %tailrecurse.i12
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$2, %rax
	jge	LBB4_8
## BB#9:                                ## %fact.exit16
	movq	%rcx, -80(%rbp)
	movl	$3, %eax
	movl	$1, %ecx
	jmp	LBB4_10
	.align	4, 0x90
LBB4_11:                                ## %cont0.i21
                                        ##   in Loop: Header=BB4_10 Depth=1
	imulq	%rax, %rcx
	decq	%rax
LBB4_10:                                ## %tailrecurse.i20
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$2, %rax
	jge	LBB4_11
## BB#12:                               ## %fact.exit24
	movq	%rcx, -72(%rbp)
	movl	$4, %eax
	movl	$1, %ecx
	jmp	LBB4_13
	.align	4, 0x90
LBB4_14:                                ## %cont0.i29
                                        ##   in Loop: Header=BB4_13 Depth=1
	imulq	%rax, %rcx
	decq	%rax
LBB4_13:                                ## %tailrecurse.i28
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$2, %rax
	jge	LBB4_14
## BB#15:                               ## %fact.exit32
	movq	%rcx, -64(%rbp)
	movl	$5, %eax
	movl	$1, %ecx
	jmp	LBB4_16
	.align	4, 0x90
LBB4_17:                                ## %cont0.i37
                                        ##   in Loop: Header=BB4_16 Depth=1
	imulq	%rax, %rcx
	decq	%rax
LBB4_16:                                ## %tailrecurse.i36
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$2, %rax
	jge	LBB4_17
## BB#18:                               ## %fact.exit40
	movq	%rcx, -56(%rbp)
	movl	$6, %eax
	movl	$1, %ecx
	jmp	LBB4_19
	.align	4, 0x90
LBB4_20:                                ## %cont0.i45
                                        ##   in Loop: Header=BB4_19 Depth=1
	imulq	%rax, %rcx
	decq	%rax
LBB4_19:                                ## %tailrecurse.i44
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$2, %rax
	jge	LBB4_20
## BB#21:                               ## %fact.exit48
	movq	%rcx, -48(%rbp)
	movl	$7, %eax
	movl	$1, %ecx
	jmp	LBB4_22
	.align	4, 0x90
LBB4_23:                                ## %cont0.i53
                                        ##   in Loop: Header=BB4_22 Depth=1
	imulq	%rax, %rcx
	decq	%rax
LBB4_22:                                ## %tailrecurse.i52
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$2, %rax
	jge	LBB4_23
## BB#24:                               ## %fact.exit56
	movq	%rcx, -40(%rbp)
	movl	$8, %eax
	movl	$1, %ecx
	jmp	LBB4_25
	.align	4, 0x90
LBB4_26:                                ## %cont0.i61
                                        ##   in Loop: Header=BB4_25 Depth=1
	imulq	%rax, %rcx
	decq	%rax
LBB4_25:                                ## %tailrecurse.i60
                                        ## =>This Inner Loop Header: Depth=1
	cmpq	$2, %rax
	jge	LBB4_26
## BB#27:                               ## %loop2
	movq	%rcx, -32(%rbp)
	movq	-96(%rbp), %rsi
	leaq	L_.str1(%rip), %rbx
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movq	-88(%rbp), %rsi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movq	-80(%rbp), %rsi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movq	-72(%rbp), %rsi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movq	-64(%rbp), %rsi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movq	-56(%rbp), %rsi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movq	-48(%rbp), %rsi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movq	-40(%rbp), %rsi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	movq	-32(%rbp), %rsi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	cmpq	-24(%rbp), %r14
	jne	LBB4_29
## BB#28:                               ## %loop2
	xorl	%eax, %eax
	addq	$80, %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
LBB4_29:                                ## %loop2
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_fact
	.align	4, 0x90
_fact:                                  ## @fact
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
	.asciz	"sup meme\n"

L_.str1:                                ## @.str1
	.asciz	"%llu\n"

L_.str2:                                ## @.str2
	.asciz	"%f\n"

L_str:                                  ## @str
	.asciz	"sup meme"


.subsections_via_symbols
