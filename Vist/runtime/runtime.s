	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_vist_allocObject
	.align	4, 0x90
_vist_allocObject:                      ## @vist_allocObject
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
	movl	%edi, -4(%rbp)
	movslq	-4(%rbp), %rdi
	callq	_malloc
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist_deallocObject
	.align	4, 0x90
_vist_deallocObject:                    ## @vist_deallocObject
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
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_free
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist_retain
	.align	4, 0x90
_vist_retain:                           ## @vist_retain
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
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_free
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist_release
	.align	4, 0x90
_vist_release:                          ## @vist_release
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
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_free
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist$Uprint_ti64
	.align	4, 0x90
_vist$Uprint_ti64:                      ## @"vist$Uprint_ti64"
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
	leaq	L_.str(%rip), %rax
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rsi
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist$Uprint_ti32
	.align	4, 0x90
_vist$Uprint_ti32:                      ## @"vist$Uprint_ti32"
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
	subq	$16, %rsp
	leaq	L_.str.1(%rip), %rax
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %esi
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist$Uprint_tf64
	.align	4, 0x90
_vist$Uprint_tf64:                      ## @"vist$Uprint_tf64"
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp18:
	.cfi_def_cfa_offset 16
Ltmp19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp20:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str.2(%rip), %rdi
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0         ## xmm0 = mem[0],zero
	movb	$1, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist$Uprint_tf32
	.align	4, 0x90
_vist$Uprint_tf32:                      ## @"vist$Uprint_tf32"
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp21:
	.cfi_def_cfa_offset 16
Ltmp22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp23:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str.2(%rip), %rdi
	movss	%xmm0, -4(%rbp)
	cvtss2sd	-4(%rbp), %xmm0
	movb	$1, %al
	callq	_printf
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist$Uprint_tb
	.align	4, 0x90
_vist$Uprint_tb:                        ## @"vist$Uprint_tb"
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp24:
	.cfi_def_cfa_offset 16
Ltmp25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp26:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movb	%dil, %al
	leaq	L_.str.4(%rip), %rcx
	leaq	L_.str.3(%rip), %rdx
	andb	$1, %al
	movb	%al, -1(%rbp)
	movb	-1(%rbp), %al
	testb	$1, %al
	cmovneq	%rdx, %rcx
	movq	%rcx, %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist$Uprint_top
	.align	4, 0x90
_vist$Uprint_top:                       ## @"vist$Uprint_top"
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp27:
	.cfi_def_cfa_offset 16
Ltmp28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp29:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str.5(%rip), %rax
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rsi
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%lli\n"

L_.str.1:                               ## @.str.1
	.asciz	"%i\n"

L_.str.2:                               ## @.str.2
	.asciz	"%f\n"

L_.str.3:                               ## @.str.3
	.asciz	"true\n"

L_.str.4:                               ## @.str.4
	.asciz	"false\n"

L_.str.5:                               ## @.str.5
	.asciz	"%s\n"


.subsections_via_symbols
