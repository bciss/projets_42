	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_ft_strdup
	.align	4, 0x90
_ft_strdup:                             ## @ft_strdup
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp2:
	.cfi_def_cfa_register rbp
	push	rbx
	push	rax
Ltmp3:
	.cfi_offset rbx, -24
	mov	rbx, rdi
                                        ## kill: RDI<def> RBX<kill>
	call	_ft_strlen
	shl	rax, 32
	movabs	rdi, 4294967296
	add	rdi, rax
	sar	rdi, 32
	call	_malloc
	xor	ecx, ecx
	test	rax, rax
	je	LBB0_5
## BB#1:                                ## %.preheader
	mov	cl, byte ptr [rbx]
	test	cl, cl
	mov	rdx, rax
	je	LBB0_4
## BB#2:                                ## %.lr.ph.preheader
	inc	rbx
	mov	rdx, rax
	.align	4, 0x90
LBB0_3:                                 ## %.lr.ph
                                        ## =>This Inner Loop Header: Depth=1
	mov	byte ptr [rdx], cl
	mov	cl, byte ptr [rbx]
	inc	rbx
	inc	rdx
	test	cl, cl
	jne	LBB0_3
LBB0_4:                                 ## %._crit_edge
	mov	byte ptr [rdx], 0
	mov	rcx, rax
LBB0_5:
	mov	rax, rcx
	add	rsp, 8
	pop	rbx
	pop	rbp
	ret
	.cfi_endproc


.subsections_via_symbols
