	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	__Z17incrementRefCountP16RefcountedObject
	.align	4, 0x90
__Z17incrementRefCountP16RefcountedObject: ## @_Z17incrementRefCountP16RefcountedObject
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
	lock
	incl	8(%rdi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z17decrementRefCountP16RefcountedObject
	.align	4, 0x90
__Z17decrementRefCountP16RefcountedObject: ## @_Z17decrementRefCountP16RefcountedObject
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
	lock
	decl	8(%rdi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist_allocObject
	.align	4, 0x90
_vist_allocObject:                      ## @vist_allocObject
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
	subq	$16, %rsp
	movl	%edi, %edi
                                        ## kill: RDI<def> EDI<kill>
	callq	_malloc
	movl	$16, %ecx
	movl	%ecx, %edi
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	callq	_malloc
	movq	%rax, %rdi
	movq	-8(%rbp), %rdx          ## 8-byte Reload
	movq	%rdx, (%rax)
	movl	$0, 8(%rax)
	movq	%rdi, %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist_deallocObject
	.align	4, 0x90
_vist_deallocObject:                    ## @vist_deallocObject
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
	movq	(%rdi), %rdi
	popq	%rbp
	jmp	_free                   ## TAILCALL
	.cfi_endproc

	.globl	_vist_releaseObject
	.align	4, 0x90
_vist_releaseObject:                    ## @vist_releaseObject
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, %rax
	addq	$8, %rax
	cmpl	$1, 8(%rdi)
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	jne	LBB4_2
## BB#1:                                ## %if.then
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	(%rax), %rdi
	callq	_free
	jmp	LBB4_3
LBB4_2:                                 ## %if.else
	movq	-16(%rbp), %rax         ## 8-byte Reload
	lock
	decl	(%rax)
LBB4_3:                                 ## %if.end
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist_retainObject
	.align	4, 0x90
_vist_retainObject:                     ## @vist_retainObject
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp15:
	.cfi_def_cfa_offset 16
Ltmp16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp17:
	.cfi_def_cfa_register %rbp
	lock
	incl	8(%rdi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist_releaseUnownedObject
	.align	4, 0x90
_vist_releaseUnownedObject:             ## @vist_releaseUnownedObject
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
	lock
	decl	8(%rdi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist_getObjectRefcount
	.align	4, 0x90
_vist_getObjectRefcount:                ## @vist_getObjectRefcount
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
	movl	8(%rdi), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_vist_objectHasUniqueReference
	.align	4, 0x90
_vist_objectHasUniqueReference:         ## @vist_objectHasUniqueReference
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
	cmpl	$1, 8(%rdi)
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	"_vist-Uprint_ti64"
	.align	4, 0x90
"_vist-Uprint_ti64":                    ## @vist-Uprint_ti64
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

	.globl	"_vist-Uprint_ti32"
	.align	4, 0x90
"_vist-Uprint_ti32":                    ## @vist-Uprint_ti32
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

	.globl	"_vist-Uprint_tf64"
	.align	4, 0x90
"_vist-Uprint_tf64":                    ## @vist-Uprint_tf64
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
	leaq	L_.str2(%rip), %rdi
	movb	$1, %al
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	"_vist-Uprint_tf32"
	.align	4, 0x90
"_vist-Uprint_tf32":                    ## @vist-Uprint_tf32
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
	cvtss2sd	%xmm0, %xmm0
	leaq	L_.str2(%rip), %rdi
	movb	$1, %al
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	"_vist-Uprint_tb"
	.align	4, 0x90
"_vist-Uprint_tb":                      ## @vist-Uprint_tb
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp39:
	.cfi_def_cfa_offset 16
Ltmp40:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp41:
	.cfi_def_cfa_register %rbp
	movb	%dil, %al
	leaq	L_.str3(%rip), %rcx
	leaq	L_.str4(%rip), %rdx
	testb	$1, %al
	cmovneq	%rcx, %rdx
	xorl	%edi, %edi
	movb	%dil, %al
	movq	%rdx, %rdi
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	"_vist-Uprint_top"
	.align	4, 0x90
"_vist-Uprint_top":                     ## @vist-Uprint_top
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
	popq	%rbp
	jmp	_puts                   ## TAILCALL
	.cfi_endproc

	.globl	"_-T-O_tII"
	.align	4, 0x90
"_-T-O_tII":                            ## @-T-O_tII
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	orq	%rdi, %rsi
	movq	%rsi, %rax
	popq	%rbp
	retq

	.globl	_Int_ti64
	.align	4, 0x90
_Int_ti64:                              ## @Int_ti64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_String_topi64b
	.align	4, 0x90
_String_topi64b:                        ## @String_topi64b
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp45:
	.cfi_def_cfa_offset 16
Ltmp46:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp47:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movb	%dl, %al
	movl	%esi, %edx
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movl	%edx, %edi
	movq	%rsi, -16(%rbp)         ## 8-byte Spill
	movb	%al, -17(%rbp)          ## 1-byte Spill
	callq	_malloc
	movq	%rax, %rdi
	movq	-8(%rbp), %rsi          ## 8-byte Reload
	movq	-16(%rbp), %rdx         ## 8-byte Reload
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	_memcpy
	movb	-17(%rbp), %cl          ## 1-byte Reload
	testb	$1, %cl
	jne	LBB17_1
	jmp	LBB17_2
LBB17_1:                                ## %if.0
	movq	-16(%rbp), %rax         ## 8-byte Reload
	shlq	$1, %rax
	orq	$1, %rax
	movq	%rax, -40(%rbp)         ## 8-byte Spill
	jmp	LBB17_5
LBB17_2:                                ## %else.1
	movl	$2, %eax
	movl	%eax, %ecx
	movq	-16(%rbp), %rdx         ## 8-byte Reload
	imulq	%rcx, %rdx
	seto	%sil
	movq	%rdx, -48(%rbp)         ## 8-byte Spill
	movb	%sil, -49(%rbp)         ## 1-byte Spill
	jo	LBB17_3
	jmp	LBB17_4
LBB17_3:                                ## %*.trap.i
	ud2
LBB17_4:                                ## %-A_tII.exit
	movq	-48(%rbp), %rax         ## 8-byte Reload
	shlq	$1, %rax
	movq	%rax, -40(%rbp)         ## 8-byte Spill
LBB17_5:                                ## %exit
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	movq	%rcx, %rax
	movq	-16(%rbp), %rdx         ## 8-byte Reload
	movq	-64(%rbp), %rcx         ## 8-byte Reload
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_Bool_tB
	.align	4, 0x90
_Bool_tB:                               ## @Bool_tB
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	popq	%rbp
	retq

	.globl	_Bool_tb
	.align	4, 0x90
_Bool_tb:                               ## @Bool_tb
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	popq	%rbp
	retq

	.globl	_isUTF8Encoded_mString
	.align	4, 0x90
_isUTF8Encoded_mString:                 ## @isUTF8Encoded_mString
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	16(%rdi), %al
	andb	$1, %al
	popq	%rbp
	retq

	.globl	_Bool_t
	.align	4, 0x90
_Bool_t:                                ## @Bool_t
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
	movb	%al, %cl
	movb	%cl, %al
	popq	%rbp
	retq

	.globl	"_-A_tII"
	.align	4, 0x90
"_-A_tII":                              ## @-A_tII
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	imulq	%rsi, %rdi
	seto	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movb	%al, -9(%rbp)           ## 1-byte Spill
	jo	LBB22_2
## BB#1:                                ## %entry.cont
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq
LBB22_2:                                ## %*.trap
	ud2

	.globl	_Int_t
	.align	4, 0x90
_Int_t:                                 ## @Int_t
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
                                        ## kill: RAX<def> EAX<kill>
	popq	%rbp
	retq

	.globl	"_-E-E_tII"
	.align	4, 0x90
"_-E-E_tII":                            ## @-E-E_tII
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	subq	%rsi, %rdi
	sete	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	popq	%rbp
	retq

	.globl	_print_tI
	.align	4, 0x90
_print_tI:                              ## @print_tI
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	jmp	"_vist-Uprint_ti64"     ## TAILCALL

	.globl	_String_topII
	.align	4, 0x90
_String_topII:                          ## @String_topII
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rdx, -8(%rbp)          ## 8-byte Spill
	movq	%rsi, %rdx
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	popq	%rbp
	retq

	.globl	"_-L-L_tII"
	.align	4, 0x90
"_-L-L_tII":                            ## @-L-L_tII
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%sil, %al
	movb	%al, %cl
	shlq	%cl, %rdi
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_Int_tI
	.align	4, 0x90
_Int_tI:                                ## @Int_tI
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	"_-G-G_tII"
	.align	4, 0x90
"_-G-G_tII":                            ## @-G-G_tII
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%sil, %al
	movb	%al, %cl
	sarq	%cl, %rdi
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	_print_tB
	.align	4, 0x90
_print_tB:                              ## @print_tB
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movb	%dil, %al
	movzbl	%al, %edi
	andl	$1, %edi
	popq	%rbp
	jmp	"_vist-Uprint_tb"       ## TAILCALL

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:                                ## %entry
	pushq	%rbp
Ltmp48:
	.cfi_def_cfa_offset 16
Ltmp49:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp50:
	.cfi_def_cfa_register %rbp
	movl	$5, %edi
	callq	_malloc
	movb	$0, 4(%rax)
	movl	$1701668205, (%rax)     ## imm = 0x656D656D
	movl	$11, %edi
                                        ## kill: RDI<def> EDI<kill>
	callq	"_vist-Uprint_ti64"
	movl	$5, %ecx
	movl	%ecx, %edi
	callq	"_vist-Uprint_ti64"
	movl	$1, %edi
	popq	%rbp
	jmp	"_vist-Uprint_tb"       ## TAILCALL
	.cfi_endproc

	.globl	"_-T-N_tII"
	.align	4, 0x90
"_-T-N_tII":                            ## @-T-N_tII
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	andq	%rdi, %rsi
	movq	%rsi, %rax
	popq	%rbp
	retq

	.globl	_bufferCapacity_mString
	.align	4, 0x90
_bufferCapacity_mString:                ## @bufferCapacity_mString
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	16(%rdi), %rdi
	sarq	%rdi
	movq	%rdi, %rax
	popq	%rbp
	retq

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%lli\n"

L_.str1:                                ## @.str1
	.asciz	"%i\n"

L_.str2:                                ## @.str2
	.asciz	"%f\n"

L_.str3:                                ## @.str3
	.asciz	"true\n"

L_.str4:                                ## @.str4
	.asciz	"false\n"

L___unnamed_1:                          ## @0
	.asciz	"meme"


.subsections_via_symbols
