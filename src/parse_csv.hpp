/*******************************************************************************
 * Copyright (c) 2017 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: parse_csv.hpp
 *
 * Description:
 *      description
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2017-01-09   wm              Initial version
 *
 ******************************************************************************/

#ifndef SRC_PARSE_CSV_HPP_
#define SRC_PARSE_CSV_HPP_

#include <cstddef>

bool parse_csv(const char * first, std::size_t sz, float * optr);

// version with qi::ascii::space
//asm(R"(
//	.section	.rodata.str1.1,"aMS",@progbits,1
//parse_csv_.LC0:
//	.string	"NAN"
//parse_csv_.LC1:
//	.string	"nan"
//parse_csv_.LC2:
//	.string	"INF"
//parse_csv_.LC3:
//	.string	"inf"
//parse_csv_.LC4:
//	.string	"INITY"
//parse_csv_.LC5:
//	.string	"inity"
//	.section	.text.unlikely,"ax",@progbits
//parse_csv_.LCOLDB15:
//	.text
//parse_csv_.LHOTB15:
//	.p2align 4,,15
//	.globl	_Z9parse_csvPKcmPf
//	.type	_Z9parse_csvPKcmPf, @function
//_Z9parse_csvPKcmPf:
//parse_csv_.LFB13901:
//	.cfi_startproc
//	pushq	%r14
//	.cfi_def_cfa_offset 16
//	.cfi_offset 14, -16
//	pushq	%r13
//	.cfi_def_cfa_offset 24
//	.cfi_offset 13, -24
//	pushq	%r12
//	.cfi_def_cfa_offset 32
//	.cfi_offset 12, -32
//	pushq	%rbp
//	.cfi_def_cfa_offset 40
//	.cfi_offset 6, -40
//	pushq	%rbx
//	.cfi_def_cfa_offset 48
//	.cfi_offset 3, -48
//	leaq	(%rdi,%rsi), %rbx
//	subq	$144, %rsp
//	.cfi_def_cfa_offset 192
//	movq	%fs:40, %rax
//	movq	%rax, 136(%rsp)
//	xorl	%eax, %eax
//	leaq	40(%rsp), %rax
//	movq	%rdx, 40(%rsp)
//	movq	%rax, 64(%rsp)
//	movq	%rax, 48(%rsp)
//	movq	%rax, 88(%rsp)
//	movq	%rax, 104(%rsp)
//	movb	$44, 120(%rsp)
//	cmpq	%rdi, %rbx
//	je	parse_csv_.L2
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L549:
//	movsbq	(%rdi), %rdx
//	movq	%rdx, %rax
//	testb	$64, _ZN5boost6spirit13char_encodingL16ascii_char_typesE(%rdx)
//	je	parse_csv_.L3
//	addq	$1, %rdi
//	cmpq	%rdi, %rbx
//	jne	parse_csv_.L549
//parse_csv_.L2:
//	movq	%rbx, %rdi
//parse_csv_.L114:
//	movq	40(%rsp), %rax
//	leaq	4(%rax), %rdx
//	movl	$0x7fc00000, (%rax)
//	movq	%rdx, 40(%rsp)
//parse_csv_.L252:
//	vmovsd	parse_csv_.LC14(%rip), %xmm5
//	vmovsd	parse_csv_.LC12(%rip), %xmm4
//parse_csv_.L117:
//	cmpq	%rdi, %rbx
//	je	parse_csv_.L115
//parse_csv_.L550:
//	movsbq	(%rdi), %rdx
//	testb	$64, _ZN5boost6spirit13char_encodingL16ascii_char_typesE(%rdx)
//	je	parse_csv_.L116
//	addq	$1, %rdi
//	cmpq	%rdi, %rbx
//	jne	parse_csv_.L550
//parse_csv_.L115:
//	movq	136(%rsp), %rsi
//	xorq	%fs:40, %rsi
//	movl	$1, %eax
//	jne	parse_csv_.L551
//	addq	$144, %rsp
//	.cfi_remember_state
//	.cfi_def_cfa_offset 48
//	popq	%rbx
//	.cfi_def_cfa_offset 40
//	popq	%rbp
//	.cfi_def_cfa_offset 32
//	popq	%r12
//	.cfi_def_cfa_offset 24
//	popq	%r13
//	.cfi_def_cfa_offset 16
//	popq	%r14
//	.cfi_def_cfa_offset 8
//	ret
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L116:
//	.cfi_restore_state
//	cmpb	%dl, 120(%rsp)
//	jne	parse_csv_.L115
//parse_csv_.L521:
//	addq	$1, %rdi
//	cmpq	%rdi, %rbx
//	je	parse_csv_.L118
//	movsbq	(%rdi), %rax
//	movq	%rax, %rdx
//	testb	$64, _ZN5boost6spirit13char_encodingL16ascii_char_typesE(%rax)
//	jne	parse_csv_.L521
//	movq	%rdi, %r10
//	xorl	%ebp, %ebp
//	leal	-43(%rax), %eax
//	testb	$-3, %al
//	je	parse_csv_.L552
//parse_csv_.L121:
//	cmpb	$48, %dl
//	jne	parse_csv_.L123
//	movq	%r10, %rax
//	jmp	parse_csv_.L125
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L128:
//	movzbl	(%rax), %ecx
//	cmpb	$48, %cl
//	jne	parse_csv_.L553
//parse_csv_.L125:
//	addq	$1, %rax
//	movq	%rax, %rsi
//	subq	%r10, %rsi
//	cmpq	%rax, %rbx
//	jne	parse_csv_.L128
//parse_csv_.L126:
//	testq	%rsi, %rsi
//	je	parse_csv_.L129
//	vxorpd	%xmm2, %xmm2, %xmm2
//parse_csv_.L130:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L350
//	movzbl	(%rax), %edx
//	movl	$1, %esi
//	cmpb	$46, %dl
//	je	parse_csv_.L554
//parse_csv_.L156:
//	testb	%sil, %sil
//	je	parse_csv_.L235
//	andl	$-33, %edx
//	cmpb	$69, %dl
//	jne	parse_csv_.L167
//	addq	$1, %rax
//	xorl	%ecx, %ecx
//parse_csv_.L166:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L235
//	movzbl	(%rax), %esi
//	leal	-43(%rsi), %r8d
//	movsbl	%sil, %edx
//	andl	$253, %r8d
//	je	parse_csv_.L555
//parse_csv_.L168:
//	cmpb	$48, %dl
//	jne	parse_csv_.L188
//	movq	%rax, %r12
//	jmp	parse_csv_.L191
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L503:
//	movsbl	(%r12), %edx
//	cmpb	$48, %dl
//	jne	parse_csv_.L190
//parse_csv_.L191:
//	addq	$1, %r12
//	movq	%r12, %rsi
//	subq	%rax, %rsi
//	cmpq	%r12, %rbx
//	jne	parse_csv_.L503
//parse_csv_.L535:
//	testq	%rsi, %rsi
//	je	parse_csv_.L235
//parse_csv_.L528:
//	xorl	%eax, %eax
//parse_csv_.L187:
//	subl	%ecx, %eax
//	jns	parse_csv_.L556
//	vmovsd	%xmm4, 16(%rsp)
//	vmovaps	%xmm5, (%rsp)
//	cmpl	$-307, %eax
//	jl	parse_csv_.L557
//	vmovsd	%xmm2, 32(%rsp)
//	negl	%eax
//parse_csv_.L524:
//	vmovsd	parse_csv_.LC12(%rip), %xmm0
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	call	pow
//	vmovsd	32(%rsp), %xmm2
//	movq	%r12, %rdi
//	vmovapd	(%rsp), %xmm5
//	vdivsd	%xmm0, %xmm2, %xmm2
//	vmovsd	16(%rsp), %xmm4
//	jmp	parse_csv_.L204
//parse_csv_.L123:
//	leal	-48(%rdx), %eax
//	cmpb	$9, %al
//	jbe	parse_csv_.L558
//parse_csv_.L129:
//	cmpq	%r10, %rbx
//	je	parse_csv_.L235
//	andl	$-33, %edx
//	movq	%r10, %rax
//	cmpb	$78, %dl
//	jne	parse_csv_.L135
//	movl	$parse_csv_.LC0, %ecx
//	movl	$parse_csv_.LC1, %edx
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L139:
//	addq	$1, %rdx
//	movzbl	(%rdx), %r8d
//	addq	$1, %rcx
//	addq	$1, %rax
//	testb	%r8b, %r8b
//	je	parse_csv_.L137
//	movzbl	(%rcx), %esi
//	testb	%sil, %sil
//	je	parse_csv_.L137
//	cmpq	%rax, %rbx
//	je	parse_csv_.L313
//	movzbl	(%rax), %r9d
//	cmpb	%r9b, %sil
//	je	parse_csv_.L139
//	cmpb	%r9b, %r8b
//	je	parse_csv_.L139
//parse_csv_.L313:
//	movq	%r10, %rax
//parse_csv_.L135:
//	movzbl	(%rax), %edx
//	andl	$-33, %edx
//	cmpb	$73, %dl
//	jne	parse_csv_.L315
//	movq	%rax, %r10
//	movl	$parse_csv_.LC2, %ecx
//	movl	$parse_csv_.LC3, %edx
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L149:
//	addq	$1, %rdx
//	movzbl	(%rdx), %esi
//	addq	$1, %rcx
//	addq	$1, %r10
//	testb	%sil, %sil
//	je	parse_csv_.L146
//	movzbl	(%rcx), %r9d
//	testb	%r9b, %r9b
//	je	parse_csv_.L146
//	cmpq	%r10, %rbx
//	je	parse_csv_.L147
//	movzbl	(%r10), %r8d
//	cmpb	%r8b, %sil
//	je	parse_csv_.L149
//	cmpb	%r8b, %r9b
//	je	parse_csv_.L149
//parse_csv_.L315:
//	xorl	%esi, %esi
//	vxorpd	%xmm2, %xmm2, %xmm2
//parse_csv_.L584:
//	movzbl	(%rax), %edx
//	cmpb	$46, %dl
//	jne	parse_csv_.L156
//parse_csv_.L554:
//	leaq	1(%rax), %rcx
//	cmpq	%rcx, %rbx
//	je	parse_csv_.L157
//	movsbl	1(%rax), %edx
//	leal	-48(%rdx), %r8d
//	cmpb	$9, %r8b
//	jbe	parse_csv_.L559
//	testb	%sil, %sil
//	je	parse_csv_.L235
//	andl	$-33, %edx
//	cmpb	$69, %dl
//	je	parse_csv_.L560
//	movq	%rcx, %rdi
//parse_csv_.L253:
//	vmovsd	parse_csv_.LC7(%rip), %xmm0
//	vucomisd	%xmm0, %xmm2
//	jp	parse_csv_.L204
//	je	parse_csv_.L561
//parse_csv_.L204:
//	testb	%bpl, %bpl
//	je	parse_csv_.L232
//parse_csv_.L578:
//	vxorpd	%xmm5, %xmm2, %xmm2
//	vcvtsd2ss	%xmm2, %xmm2, %xmm2
//parse_csv_.L233:
//	movq	88(%rsp), %rdx
//	movq	(%rdx), %rax
//	leaq	4(%rax), %rcx
//	vmovss	%xmm2, (%rax)
//	movq	%rcx, (%rdx)
//	jmp	parse_csv_.L117
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L562:
//	addq	$1, %rdi
//	cmpq	%rdi, %rbx
//	je	parse_csv_.L118
//parse_csv_.L235:
//	movsbq	(%rdi), %rax
//	testb	$64, _ZN5boost6spirit13char_encodingL16ascii_char_typesE(%rax)
//	jne	parse_csv_.L562
//parse_csv_.L234:
//	movq	104(%rsp), %rdx
//	movq	(%rdx), %rax
//	leaq	4(%rax), %rcx
//	movl	$0x7fc00000, (%rax)
//	movq	%rcx, (%rdx)
//	jmp	parse_csv_.L117
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L118:
//	movq	%rbx, %rdi
//	jmp	parse_csv_.L234
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L553:
//	leal	-48(%rcx), %r8d
//	cmpb	$9, %r8b
//	ja	parse_csv_.L126
//parse_csv_.L127:
//	movsbl	%cl, %edx
//	vxorpd	%xmm2, %xmm2, %xmm2
//	subl	$48, %edx
//	vcvtsi2sd	%edx, %xmm2, %xmm2
//	vaddsd	parse_csv_.LC6(%rip), %xmm2, %xmm2
//	leaq	1(%rax), %rdx
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L308
//	movsbl	1(%rax), %ecx
//	leal	-48(%rcx), %esi
//	cmpb	$9, %sil
//	ja	parse_csv_.L310
//	vxorpd	%xmm1, %xmm1, %xmm1
//	leaq	2(%rax), %rsi
//	subl	$48, %ecx
//	vmovsd	parse_csv_.LC12(%rip), %xmm0
//	vcvtsi2sd	%ecx, %xmm1, %xmm1
//	vfmadd132sd	%xmm0, %xmm1, %xmm2
//	cmpq	%rsi, %rbx
//	je	parse_csv_.L308
//	movsbl	2(%rax), %ecx
//	leal	-48(%rcx), %eax
//	cmpb	$9, %al
//	ja	parse_csv_.L563
//	leaq	-2(%rbx), %rsi
//	vmovapd	%xmm0, %xmm3
//	leaq	-1(%rbx), %r8
//	jmp	parse_csv_.L133
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L564:
//	movsbl	2(%rdx), %ecx
//	leal	-48(%rcx), %r9d
//	cmpb	$9, %r9b
//	ja	parse_csv_.L130
//	subl	$48, %ecx
//	vxorpd	%xmm1, %xmm1, %xmm1
//	addq	$3, %rdx
//	vcvtsi2sd	%ecx, %xmm1, %xmm1
//	vfmadd132sd	%xmm3, %xmm1, %xmm2
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L308
//	movsbl	(%rdx), %eax
//	leal	-48(%rax), %ecx
//	cmpb	$9, %cl
//	ja	parse_csv_.L310
//	subl	$48, %eax
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	leaq	1(%rdx), %rax
//	vfmadd132sd	%xmm3, %xmm1, %xmm2
//	cmpq	%rdx, %r8
//	je	parse_csv_.L130
//	movsbl	1(%rdx), %ecx
//	leal	-48(%rcx), %r9d
//	cmpb	$9, %r9b
//	ja	parse_csv_.L130
//parse_csv_.L133:
//	vxorpd	%xmm1, %xmm1, %xmm1
//	leaq	2(%rdx), %rax
//	subl	$48, %ecx
//	vcvtsi2sd	%ecx, %xmm1, %xmm1
//	vfmadd132sd	%xmm0, %xmm1, %xmm2
//	cmpq	%rdx, %rsi
//	jne	parse_csv_.L564
//	jmp	parse_csv_.L130
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L3:
//	leal	-43(%rdx), %edx
//	xorl	%ebp, %ebp
//	movq	%rdi, %r10
//	andl	$253, %edx
//	je	parse_csv_.L565
//parse_csv_.L5:
//	movq	%r10, %r8
//	xorl	%ecx, %ecx
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L9:
//	movzbl	(%r8), %edx
//	cmpb	$48, %dl
//	jne	parse_csv_.L7
//	addq	$1, %r8
//	addq	$1, %rcx
//	cmpq	%r8, %rbx
//	jne	parse_csv_.L9
//	testq	%rcx, %rcx
//	jne	parse_csv_.L566
//parse_csv_.L237:
//	andl	$-33, %eax
//	cmpb	$78, %al
//	jne	parse_csv_.L16
//	movq	%r10, %rax
//	movl	$parse_csv_.LC0, %ecx
//	movl	$parse_csv_.LC1, %edx
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L19:
//	addq	$1, %rdx
//	movzbl	(%rdx), %esi
//	addq	$1, %rcx
//	addq	$1, %rax
//	testb	%sil, %sil
//	je	parse_csv_.L15
//	movzbl	(%rcx), %r8d
//	testb	%r8b, %r8b
//	je	parse_csv_.L15
//	cmpq	%rax, %rbx
//	je	parse_csv_.L16
//	movzbl	(%rax), %r9d
//	cmpb	%r9b, %sil
//	je	parse_csv_.L19
//	cmpb	%r9b, %r8b
//	je	parse_csv_.L19
//parse_csv_.L17:
//	cmpq	%r10, %rbx
//	je	parse_csv_.L47
//parse_csv_.L288:
//	movq	%r10, %r8
//	vxorpd	%xmm2, %xmm2, %xmm2
//	xorl	%edx, %edx
//	jmp	parse_csv_.L26
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L552:
//	leaq	1(%rdi), %r10
//	cmpb	$45, %dl
//	sete	%bpl
//	cmpq	%r10, %rbx
//	je	parse_csv_.L235
//	movzbl	1(%rdi), %edx
//	jmp	parse_csv_.L121
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L7:
//	leal	-48(%rdx), %esi
//	cmpb	$9, %sil
//	ja	parse_csv_.L567
//	movsbl	%dl, %eax
//	vxorpd	%xmm2, %xmm2, %xmm2
//	leaq	1(%r8), %rdx
//	subl	$48, %eax
//	vcvtsi2sd	%eax, %xmm2, %xmm2
//	vaddsd	parse_csv_.LC6(%rip), %xmm2, %xmm2
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L284
//	movsbl	1(%r8), %eax
//	leal	-48(%rax), %ecx
//	cmpb	$9, %cl
//	ja	parse_csv_.L286
//	vxorpd	%xmm1, %xmm1, %xmm1
//	leaq	2(%r8), %rcx
//	subl	$48, %eax
//	vmovsd	parse_csv_.LC12(%rip), %xmm0
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	vfmadd132sd	%xmm0, %xmm1, %xmm2
//	cmpq	%rcx, %rbx
//	je	parse_csv_.L284
//	movsbl	2(%r8), %eax
//	leal	-48(%rax), %esi
//	cmpb	$9, %sil
//	ja	parse_csv_.L568
//	leaq	-2(%rbx), %rcx
//	vmovapd	%xmm0, %xmm3
//	leaq	-1(%rbx), %rsi
//	jmp	parse_csv_.L12
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L569:
//	movsbl	2(%rdx), %eax
//	leal	-48(%rax), %r9d
//	cmpb	$9, %r9b
//	ja	parse_csv_.L14
//	subl	$48, %eax
//	vxorpd	%xmm1, %xmm1, %xmm1
//	addq	$3, %rdx
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	vfmadd132sd	%xmm3, %xmm1, %xmm2
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L284
//	movsbl	(%rdx), %eax
//	leal	-48(%rax), %r8d
//	cmpb	$9, %r8b
//	ja	parse_csv_.L286
//	vxorpd	%xmm1, %xmm1, %xmm1
//	leaq	1(%rdx), %r8
//	subl	$48, %eax
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	vfmadd132sd	%xmm3, %xmm1, %xmm2
//	cmpq	%rdx, %rsi
//	je	parse_csv_.L14
//	movsbl	1(%rdx), %eax
//	leal	-48(%rax), %r9d
//	cmpb	$9, %r9b
//	ja	parse_csv_.L14
//parse_csv_.L12:
//	vxorpd	%xmm1, %xmm1, %xmm1
//	leaq	2(%rdx), %r8
//	subl	$48, %eax
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	vfmadd132sd	%xmm0, %xmm1, %xmm2
//	cmpq	%rdx, %rcx
//	jne	parse_csv_.L569
//parse_csv_.L14:
//	cmpq	%r8, %rbx
//	je	parse_csv_.L349
//	movl	$1, %edx
//parse_csv_.L26:
//	movzbl	(%r8), %eax
//	cmpb	$46, %al
//	je	parse_csv_.L273
//	testb	%dl, %dl
//	jne	parse_csv_.L570
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L47:
//	movsbq	(%rdi), %rax
//	testb	$64, _ZN5boost6spirit13char_encodingL16ascii_char_typesE(%rax)
//	je	parse_csv_.L114
//	addq	$1, %rdi
//	cmpq	%rdi, %rbx
//	jne	parse_csv_.L47
//	jmp	parse_csv_.L2
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L567:
//	testq	%rcx, %rcx
//	je	parse_csv_.L237
//	vxorpd	%xmm2, %xmm2, %xmm2
//	jmp	parse_csv_.L14
//parse_csv_.L565:
//	leaq	1(%rdi), %r10
//	cmpb	$45, %al
//	sete	%bpl
//	cmpq	%r10, %rbx
//	je	parse_csv_.L47
//	movzbl	1(%rdi), %eax
//	jmp	parse_csv_.L5
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L287:
//	movq	%rax, %r10
//parse_csv_.L16:
//	cmpq	%r10, %rbx
//	je	parse_csv_.L47
//	movzbl	(%r10), %r11d
//	movl	%r11d, %eax
//	andl	$-33, %eax
//	cmpb	$73, %al
//	jne	parse_csv_.L17
//	movq	%r10, %rax
//	movl	$parse_csv_.LC2, %ecx
//	movl	$parse_csv_.LC3, %edx
//parse_csv_.L29:
//	addq	$1, %rdx
//	movzbl	(%rdx), %r8d
//	addq	$1, %rcx
//	addq	$1, %rax
//	testb	%r8b, %r8b
//	je	parse_csv_.L25
//	movzbl	(%rcx), %esi
//	testb	%sil, %sil
//	je	parse_csv_.L25
//	cmpq	%rax, %rbx
//	je	parse_csv_.L288
//	movzbl	(%rax), %r9d
//	cmpb	%r9b, %sil
//	je	parse_csv_.L29
//	cmpb	%r9b, %r8b
//	je	parse_csv_.L29
//	movq	%r10, %r8
//	vxorpd	%xmm2, %xmm2, %xmm2
//	xorl	%edx, %edx
//	cmpb	$46, %r11b
//	jne	parse_csv_.L47
//parse_csv_.L273:
//	leaq	1(%r8), %rcx
//	cmpq	%rcx, %rbx
//	je	parse_csv_.L37
//	movsbl	1(%r8), %eax
//	leal	-48(%rax), %esi
//	cmpb	$9, %sil
//	ja	parse_csv_.L38
//	vmovsd	parse_csv_.LC12(%rip), %xmm0
//	subl	$48, %eax
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	leaq	2(%r8), %rax
//	vfmadd132sd	%xmm0, %xmm1, %xmm2
//	cmpq	%rax, %rbx
//	je	parse_csv_.L39
//	movsbl	2(%r8), %edx
//	leal	-48(%rdx), %esi
//	cmpb	$9, %sil
//	ja	parse_csv_.L40
//	vxorpd	%xmm1, %xmm1, %xmm1
//	leaq	3(%r8), %rsi
//	subl	$48, %edx
//	vcvtsi2sd	%edx, %xmm1, %xmm1
//	vfmadd132sd	%xmm0, %xmm1, %xmm2
//	cmpq	%rsi, %rbx
//	je	parse_csv_.L291
//	movsbl	3(%r8), %edx
//	leal	-48(%rdx), %r8d
//	cmpb	$9, %r8b
//	ja	parse_csv_.L571
//	leaq	-2(%rbx), %rsi
//	vmovapd	%xmm0, %xmm3
//	leaq	-1(%rbx), %r8
//	jmp	parse_csv_.L43
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L572:
//	movsbl	2(%rax), %edx
//	leal	-48(%rdx), %r9d
//	cmpb	$9, %r9b
//	ja	parse_csv_.L42
//	subl	$48, %edx
//	vxorpd	%xmm1, %xmm1, %xmm1
//	addq	$3, %rax
//	vcvtsi2sd	%edx, %xmm1, %xmm1
//	vfmadd132sd	%xmm3, %xmm1, %xmm2
//	cmpq	%rax, %rbx
//	je	parse_csv_.L39
//	movsbl	(%rax), %edx
//	leal	-48(%rdx), %r9d
//	cmpb	$9, %r9b
//	ja	parse_csv_.L40
//	vxorpd	%xmm1, %xmm1, %xmm1
//	leaq	1(%rax), %r12
//	subl	$48, %edx
//	vcvtsi2sd	%edx, %xmm1, %xmm1
//	vfmadd132sd	%xmm3, %xmm1, %xmm2
//	cmpq	%r8, %rax
//	je	parse_csv_.L42
//	movsbl	1(%rax), %edx
//	leal	-48(%rdx), %r9d
//	cmpb	$9, %r9b
//	ja	parse_csv_.L42
//parse_csv_.L43:
//	vxorpd	%xmm1, %xmm1, %xmm1
//	leaq	2(%rax), %r12
//	subl	$48, %edx
//	vcvtsi2sd	%edx, %xmm1, %xmm1
//	vfmadd132sd	%xmm0, %xmm1, %xmm2
//	cmpq	%rax, %rsi
//	jne	parse_csv_.L572
//parse_csv_.L42:
//	movl	%r12d, %edx
//	subl	%ecx, %edx
//	cmpq	%r12, %rbx
//	je	parse_csv_.L45
//parse_csv_.L274:
//	movzbl	(%r12), %eax
//	andl	$-33, %eax
//	cmpb	$69, %al
//	jne	parse_csv_.L45
//	movq	%r12, %r8
//	jmp	parse_csv_.L275
//parse_csv_.L559:
//	subl	$48, %edx
//	vxorpd	%xmm0, %xmm0, %xmm0
//	vcvtsi2sd	%edx, %xmm0, %xmm0
//	leaq	2(%rax), %rdx
//	vfmadd132sd	%xmm4, %xmm0, %xmm2
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L159
//	movsbl	2(%rax), %esi
//	leal	-48(%rsi), %r8d
//	cmpb	$9, %r8b
//	ja	parse_csv_.L160
//	subl	$48, %esi
//	vxorpd	%xmm0, %xmm0, %xmm0
//	vcvtsi2sd	%esi, %xmm0, %xmm0
//	leaq	3(%rax), %rsi
//	vfmadd132sd	%xmm4, %xmm0, %xmm2
//	cmpq	%rsi, %rbx
//	je	parse_csv_.L318
//	movsbl	3(%rax), %eax
//	leal	-48(%rax), %r8d
//	cmpb	$9, %r8b
//	ja	parse_csv_.L573
//	leaq	-2(%rbx), %rsi
//	leaq	-1(%rbx), %r8
//	jmp	parse_csv_.L163
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L574:
//	movsbl	2(%rdx), %eax
//	leal	-48(%rax), %r9d
//	cmpb	$9, %r9b
//	ja	parse_csv_.L162
//	subl	$48, %eax
//	vxorpd	%xmm0, %xmm0, %xmm0
//	addq	$3, %rdx
//	vcvtsi2sd	%eax, %xmm0, %xmm0
//	vfmadd132sd	%xmm4, %xmm0, %xmm2
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L159
//	movsbl	(%rdx), %eax
//	leal	-48(%rax), %r9d
//	cmpb	$9, %r9b
//	ja	parse_csv_.L160
//	vxorpd	%xmm0, %xmm0, %xmm0
//	leaq	1(%rdx), %r12
//	subl	$48, %eax
//	vcvtsi2sd	%eax, %xmm0, %xmm0
//	vfmadd132sd	%xmm4, %xmm0, %xmm2
//	cmpq	%r8, %rdx
//	je	parse_csv_.L162
//	movsbl	1(%rdx), %eax
//	leal	-48(%rax), %r9d
//	cmpb	$9, %r9b
//	ja	parse_csv_.L162
//parse_csv_.L163:
//	vxorpd	%xmm0, %xmm0, %xmm0
//	leaq	2(%rdx), %r12
//	subl	$48, %eax
//	vcvtsi2sd	%eax, %xmm0, %xmm0
//	vfmadd132sd	%xmm4, %xmm0, %xmm2
//	cmpq	%rdx, %rsi
//	jne	parse_csv_.L574
//parse_csv_.L162:
//	movl	%r12d, %eax
//	subl	%ecx, %eax
//	movl	%eax, %ecx
//	cmpq	%r12, %rbx
//	je	parse_csv_.L165
//parse_csv_.L276:
//	movzbl	(%r12), %eax
//	andl	$-33, %eax
//	cmpb	$69, %al
//	je	parse_csv_.L575
//parse_csv_.L165:
//	movq	%r12, %rdi
//	testl	%ecx, %ecx
//	je	parse_csv_.L253
//	movl	%ecx, %eax
//	vmovaps	%xmm5, 16(%rsp)
//	negl	%eax
//	testl	%eax, %eax
//	jns	parse_csv_.L576
//	cmpl	$-307, %eax
//	jl	parse_csv_.L577
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vcvtsi2sdq	%rcx, %xmm1, %xmm1
//	vmovsd	%xmm2, (%rsp)
//parse_csv_.L523:
//	vmovapd	%xmm4, %xmm0
//	vmovsd	%xmm4, 32(%rsp)
//	call	pow
//	vmovsd	(%rsp), %xmm2
//	movq	%r12, %rdi
//	vmovsd	32(%rsp), %xmm4
//	vdivsd	%xmm0, %xmm2, %xmm2
//	vmovapd	16(%rsp), %xmm5
//	testb	%bpl, %bpl
//	jne	parse_csv_.L578
//parse_csv_.L232:
//	vcvtsd2ss	%xmm2, %xmm2, %xmm2
//	jmp	parse_csv_.L233
//parse_csv_.L157:
//	testb	%sil, %sil
//	je	parse_csv_.L235
//parse_csv_.L350:
//	movq	%rbx, %rdi
//	jmp	parse_csv_.L253
//parse_csv_.L570:
//	andl	$-33, %eax
//	cmpb	$69, %al
//	je	parse_csv_.L579
//	movq	%r8, %rdi
//	jmp	parse_csv_.L238
//parse_csv_.L167:
//	vmovsd	parse_csv_.LC7(%rip), %xmm0
//	movq	%rax, %rdi
//	vucomisd	%xmm0, %xmm2
//	jp	parse_csv_.L204
//	jne	parse_csv_.L204
//parse_csv_.L278:
//	movzbl	(%rdi), %eax
//	andl	$-33, %eax
//	cmpb	$78, %al
//	jne	parse_csv_.L213
//	movq	%rdi, %rax
//	movl	$parse_csv_.LC0, %ecx
//	movl	$parse_csv_.LC1, %edx
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L217:
//	addq	$1, %rdx
//	movzbl	(%rdx), %esi
//	addq	$1, %rcx
//	addq	$1, %rax
//	testb	%sil, %sil
//	je	parse_csv_.L215
//	movzbl	(%rcx), %r9d
//	testb	%r9b, %r9b
//	je	parse_csv_.L215
//	cmpq	%rax, %rbx
//	je	parse_csv_.L522
//	movzbl	(%rax), %r8d
//	cmpb	%r8b, %sil
//	je	parse_csv_.L217
//	cmpb	%r8b, %r9b
//	je	parse_csv_.L217
//parse_csv_.L213:
//	movzbl	(%rdi), %eax
//	andl	$-33, %eax
//	cmpb	$73, %al
//	jne	parse_csv_.L522
//	movq	%rdi, %r9
//	movl	$parse_csv_.LC2, %edx
//	movl	$parse_csv_.LC3, %eax
//parse_csv_.L225:
//	addq	$1, %rax
//	movzbl	(%rax), %esi
//	addq	$1, %rdx
//	addq	$1, %r9
//	testb	%sil, %sil
//	je	parse_csv_.L223
//	movzbl	(%rdx), %ecx
//	testb	%cl, %cl
//	je	parse_csv_.L223
//	cmpq	%r9, %rbx
//	je	parse_csv_.L522
//	movzbl	(%r9), %r8d
//	cmpb	%r8b, %cl
//	je	parse_csv_.L225
//	cmpb	%r8b, %sil
//	je	parse_csv_.L225
//parse_csv_.L522:
//	vmovapd	%xmm0, %xmm2
//	jmp	parse_csv_.L204
//parse_csv_.L566:
//	movq	%rbx, %rdi
//	vxorpd	%xmm2, %xmm2, %xmm2
//parse_csv_.L238:
//	vucomisd	parse_csv_.LC7(%rip), %xmm2
//	jp	parse_csv_.L83
//	je	parse_csv_.L580
//parse_csv_.L83:
//	testb	%bpl, %bpl
//	je	parse_csv_.L112
//	vmovsd	parse_csv_.LC14(%rip), %xmm0
//	vxorpd	%xmm0, %xmm2, %xmm2
//	vcvtsd2ss	%xmm2, %xmm2, %xmm2
//parse_csv_.L113:
//	movq	40(%rsp), %rax
//	leaq	4(%rax), %rdx
//	vmovss	%xmm2, (%rax)
//	movq	%rdx, 40(%rsp)
//	jmp	parse_csv_.L252
//parse_csv_.L575:
//	movq	%r12, %rax
//parse_csv_.L277:
//	addq	$1, %rax
//	jmp	parse_csv_.L166
//parse_csv_.L38:
//	testb	%dl, %dl
//	je	parse_csv_.L47
//	andl	$-33, %eax
//	cmpb	$69, %al
//	jne	parse_csv_.L346
//	movq	%rcx, %r8
//	xorl	%edx, %edx
//parse_csv_.L275:
//	addq	$1, %r8
//parse_csv_.L46:
//	cmpq	%r8, %rbx
//	je	parse_csv_.L47
//	movzbl	(%r8), %ecx
//	leal	-43(%rcx), %esi
//	movsbl	%cl, %eax
//	andl	$253, %esi
//	je	parse_csv_.L581
//parse_csv_.L48:
//	cmpb	$48, %al
//	jne	parse_csv_.L67
//	movq	%r8, %r12
//	jmp	parse_csv_.L70
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L492:
//	movsbl	(%r12), %eax
//	cmpb	$48, %al
//	jne	parse_csv_.L69
//parse_csv_.L70:
//	addq	$1, %r12
//	movq	%r12, %rcx
//	subq	%r8, %rcx
//	cmpq	%r12, %rbx
//	jne	parse_csv_.L492
//parse_csv_.L71:
//	xorl	%eax, %eax
//	testq	%rcx, %rcx
//	je	parse_csv_.L47
//parse_csv_.L66:
//	subl	%edx, %eax
//	jns	parse_csv_.L582
//	cmpl	$-307, %eax
//	jl	parse_csv_.L583
//	vmovsd	%xmm2, 32(%rsp)
//	negl	%eax
//parse_csv_.L520:
//	vmovsd	parse_csv_.LC12(%rip), %xmm0
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	call	pow
//	vmovsd	32(%rsp), %xmm2
//	movq	%r12, %rdi
//	vdivsd	%xmm0, %xmm2, %xmm2
//	jmp	parse_csv_.L83
//parse_csv_.L560:
//	movq	%rcx, %rax
//	xorl	%ecx, %ecx
//	jmp	parse_csv_.L277
//parse_csv_.L579:
//	addq	$1, %r8
//	xorl	%edx, %edx
//	jmp	parse_csv_.L46
//parse_csv_.L576:
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	vmovapd	%xmm4, %xmm0
//	vmovsd	%xmm2, (%rsp)
//	vmovsd	%xmm4, 32(%rsp)
//	call	pow
//	vmovsd	(%rsp), %xmm2
//	movq	%r12, %rdi
//	vmovsd	32(%rsp), %xmm4
//	vmulsd	%xmm0, %xmm2, %xmm2
//	vmovapd	16(%rsp), %xmm5
//	jmp	parse_csv_.L204
//parse_csv_.L147:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L235
//	vxorpd	%xmm2, %xmm2, %xmm2
//	xorl	%esi, %esi
//	jmp	parse_csv_.L584
//parse_csv_.L112:
//	vcvtsd2ss	%xmm2, %xmm2, %xmm2
//	jmp	parse_csv_.L113
//parse_csv_.L137:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L219
//	cmpb	$40, (%rax)
//	je	parse_csv_.L585
//parse_csv_.L219:
//	vmovss	parse_csv_.LC8(%rip), %xmm0
//	movq	%rax, %rdi
//	vmovss	parse_csv_.LC9(%rip), %xmm2
//parse_csv_.L264:
//	testb	%bpl, %bpl
//	jne	parse_csv_.L233
//	vmovaps	%xmm0, %xmm2
//	jmp	parse_csv_.L233
//parse_csv_.L291:
//	movq	%rbx, %rax
//parse_csv_.L39:
//	movl	%eax, %edx
//	movq	%rax, %r12
//	subl	%ecx, %edx
//parse_csv_.L45:
//	movq	%r12, %rdi
//	testl	%edx, %edx
//	je	parse_csv_.L238
//	movl	%edx, %eax
//	negl	%eax
//	testl	%eax, %eax
//	jns	parse_csv_.L586
//	cmpl	$-307, %eax
//	jl	parse_csv_.L587
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vcvtsi2sdq	%rdx, %xmm1, %xmm1
//	vmovsd	%xmm2, 32(%rsp)
//	call	pow
//	vmovsd	32(%rsp), %xmm2
//	movq	%r12, %rdi
//	vdivsd	%xmm0, %xmm2, %xmm2
//	jmp	parse_csv_.L83
//parse_csv_.L555:
//	leaq	1(%rax), %r12
//	cmpb	$45, %sil
//	jne	parse_csv_.L169
//	cmpq	%r12, %rbx
//	je	parse_csv_.L235
//	movsbl	1(%rax), %eax
//	cmpb	$48, %al
//	jne	parse_csv_.L171
//	xorl	%edx, %edx
//	jmp	parse_csv_.L174
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L501:
//	movsbl	(%r12), %eax
//	cmpb	$48, %al
//	jne	parse_csv_.L173
//parse_csv_.L174:
//	addq	$1, %r12
//	addq	$1, %rdx
//	cmpq	%r12, %rbx
//	jne	parse_csv_.L501
//parse_csv_.L533:
//	testq	%rdx, %rdx
//	jne	parse_csv_.L528
//	jmp	parse_csv_.L235
//parse_csv_.L173:
//	leal	-48(%rax), %esi
//	cmpb	$9, %sil
//	ja	parse_csv_.L533
//parse_csv_.L260:
//	leaq	1(%r12), %rdx
//	subl	$48, %eax
//	negl	%eax
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L321
//	movsbl	1(%r12), %esi
//	leal	-48(%rsi), %r8d
//	cmpb	$9, %r8b
//	ja	parse_csv_.L323
//	leaq	-2(%rbx), %r10
//	xorl	%r8d, %r8d
//	leaq	-1(%rbx), %r9
//	jmp	parse_csv_.L179
//parse_csv_.L588:
//	leal	(%rax,%rax,4), %eax
//	subl	$48, %esi
//	addl	%eax, %eax
//	subl	%esi, %eax
//parse_csv_.L181:
//	leaq	1(%rdx), %r13
//	cmpq	%r9, %rdx
//	je	parse_csv_.L327
//	movsbl	1(%rdx), %esi
//	leal	-48(%rsi), %r11d
//	cmpb	$9, %r11b
//	ja	parse_csv_.L327
//	movq	%rdx, %r11
//	subq	%r12, %r11
//	cmpq	$7, %r11
//	ja	parse_csv_.L182
//	leal	(%rax,%rax,4), %eax
//	subl	$48, %esi
//	addl	%eax, %eax
//	subl	%esi, %eax
//parse_csv_.L183:
//	leaq	2(%rdx), %r13
//	cmpq	%rdx, %r10
//	je	parse_csv_.L327
//	movsbl	2(%rdx), %esi
//	leal	-48(%rsi), %r11d
//	cmpb	$9, %r11b
//	ja	parse_csv_.L327
//	leaq	2(%r8), %r11
//	cmpq	$7, %r11
//	ja	parse_csv_.L184
//	leal	(%rax,%rax,4), %eax
//	subl	$48, %esi
//	addl	%eax, %eax
//	subl	%esi, %eax
//parse_csv_.L185:
//	addq	$3, %rdx
//	addq	$3, %r8
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L321
//	movsbl	(%rdx), %esi
//	leal	-48(%rsi), %r11d
//	cmpb	$9, %r11b
//	ja	parse_csv_.L323
//parse_csv_.L179:
//	cmpq	$7, %r8
//	jbe	parse_csv_.L588
//	cmpl	$-214748364, %eax
//	jl	parse_csv_.L235
//	leal	(%rax,%rax,4), %eax
//	leal	-48(%rsi), %r11d
//	addl	%eax, %eax
//	addl	$2147483600, %esi
//	cmpl	%esi, %eax
//	jl	parse_csv_.L235
//	subl	%r11d, %eax
//	jmp	parse_csv_.L181
//parse_csv_.L190:
//	leal	-48(%rdx), %eax
//	cmpb	$9, %al
//	ja	parse_csv_.L535
//parse_csv_.L261:
//	leaq	1(%r12), %rsi
//	subl	$48, %edx
//	cmpq	%rsi, %rbx
//	je	parse_csv_.L328
//	movsbl	1(%r12), %eax
//	leal	-48(%rax), %r8d
//	cmpb	$9, %r8b
//	ja	parse_csv_.L330
//	leaq	-2(%rbx), %r10
//	xorl	%r8d, %r8d
//	movl	$2147483647, %r11d
//	leaq	-1(%rbx), %r9
//	jmp	parse_csv_.L196
//parse_csv_.L589:
//	leal	(%rdx,%rdx,4), %edx
//	leal	-48(%rax,%rdx,2), %edx
//parse_csv_.L198:
//	leaq	1(%rsi), %r14
//	cmpq	%rsi, %r9
//	je	parse_csv_.L334
//	movsbl	1(%rsi), %eax
//	leal	-48(%rax), %r13d
//	cmpb	$9, %r13b
//	ja	parse_csv_.L334
//	movq	%rsi, %r13
//	subq	%r12, %r13
//	cmpq	$7, %r13
//	ja	parse_csv_.L199
//	leal	(%rdx,%rdx,4), %edx
//	leal	-48(%rax,%rdx,2), %edx
//parse_csv_.L200:
//	leaq	2(%rsi), %r14
//	cmpq	%rsi, %r10
//	je	parse_csv_.L334
//	movsbl	2(%rsi), %eax
//	leal	-48(%rax), %r13d
//	cmpb	$9, %r13b
//	ja	parse_csv_.L334
//	leaq	2(%r8), %r13
//	cmpq	$7, %r13
//	ja	parse_csv_.L201
//	leal	(%rdx,%rdx,4), %edx
//	leal	-48(%rax,%rdx,2), %edx
//parse_csv_.L202:
//	addq	$3, %rsi
//	addq	$3, %r8
//	cmpq	%rsi, %rbx
//	je	parse_csv_.L328
//	movsbl	(%rsi), %eax
//	leal	-48(%rax), %r13d
//	cmpb	$9, %r13b
//	ja	parse_csv_.L330
//parse_csv_.L196:
//	cmpq	$7, %r8
//	jbe	parse_csv_.L589
//	cmpl	$214748364, %edx
//	jg	parse_csv_.L235
//	leal	(%rdx,%rdx,4), %edx
//	subl	$48, %eax
//	movl	%r11d, %r13d
//	addl	%edx, %edx
//	subl	%eax, %r13d
//	cmpl	%r13d, %edx
//	jg	parse_csv_.L235
//	addl	%eax, %edx
//	jmp	parse_csv_.L198
//parse_csv_.L37:
//	testb	%dl, %dl
//	je	parse_csv_.L47
//parse_csv_.L349:
//	movq	%rbx, %rdi
//	jmp	parse_csv_.L238
//parse_csv_.L561:
//	cmpq	%rdi, %rbx
//	jne	parse_csv_.L278
//	jmp	parse_csv_.L204
//parse_csv_.L308:
//	movq	%rbx, %rax
//	jmp	parse_csv_.L130
//parse_csv_.L184:
//	cmpl	$-214748364, %eax
//	jl	parse_csv_.L235
//	leal	(%rax,%rax,4), %eax
//	leal	-48(%rsi), %r11d
//	addl	%eax, %eax
//	addl	$2147483600, %esi
//	cmpl	%esi, %eax
//	jl	parse_csv_.L235
//	subl	%r11d, %eax
//	jmp	parse_csv_.L185
//parse_csv_.L182:
//	cmpl	$-214748364, %eax
//	jl	parse_csv_.L235
//	leal	(%rax,%rax,4), %eax
//	leal	-48(%rsi), %r11d
//	addl	%eax, %eax
//	addl	$2147483600, %esi
//	cmpl	%esi, %eax
//	jl	parse_csv_.L235
//	subl	%r11d, %eax
//	jmp	parse_csv_.L183
//parse_csv_.L15:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L99
//	cmpb	$40, (%rax)
//	je	parse_csv_.L590
//parse_csv_.L99:
//	vmovss	parse_csv_.LC8(%rip), %xmm0
//	movq	%rax, %rdi
//	vmovss	parse_csv_.LC9(%rip), %xmm2
//parse_csv_.L251:
//	testb	%bpl, %bpl
//	jne	parse_csv_.L113
//	vmovaps	%xmm0, %xmm2
//	jmp	parse_csv_.L113
//parse_csv_.L310:
//	movq	%rdx, %rax
//	jmp	parse_csv_.L130
//parse_csv_.L201:
//	cmpl	$214748364, %edx
//	jg	parse_csv_.L235
//	leal	(%rdx,%rdx,4), %edx
//	subl	$48, %eax
//	movl	%r11d, %r13d
//	addl	%edx, %edx
//	subl	%eax, %r13d
//	cmpl	%r13d, %edx
//	jg	parse_csv_.L235
//	addl	%eax, %edx
//	jmp	parse_csv_.L202
//parse_csv_.L199:
//	cmpl	$214748364, %edx
//	jg	parse_csv_.L235
//	leal	(%rdx,%rdx,4), %edx
//	subl	$48, %eax
//	movl	%r11d, %r13d
//	addl	%edx, %edx
//	subl	%eax, %r13d
//	cmpl	%r13d, %edx
//	jg	parse_csv_.L235
//	addl	%eax, %edx
//	jmp	parse_csv_.L200
//parse_csv_.L580:
//	cmpq	%rdi, %rbx
//	je	parse_csv_.L83
//	movzbl	(%rdi), %eax
//	andl	$-33, %eax
//	cmpb	$78, %al
//	jne	parse_csv_.L93
//	movq	%rdi, %rax
//	movl	$parse_csv_.LC0, %ecx
//	movl	$parse_csv_.LC1, %edx
//parse_csv_.L97:
//	addq	$1, %rdx
//	movzbl	(%rdx), %esi
//	addq	$1, %rcx
//	addq	$1, %rax
//	testb	%sil, %sil
//	je	parse_csv_.L95
//	movzbl	(%rcx), %r9d
//	testb	%r9b, %r9b
//	je	parse_csv_.L95
//	cmpq	%rax, %rbx
//	je	parse_csv_.L93
//	movzbl	(%rax), %r8d
//	cmpb	%r8b, %sil
//	je	parse_csv_.L97
//	cmpb	%r8b, %r9b
//	je	parse_csv_.L97
//	jmp	parse_csv_.L83
//parse_csv_.L573:
//	movq	%rsi, %rdx
//parse_csv_.L160:
//	movl	%edx, %eax
//	movq	%rdx, %r12
//	subl	%ecx, %eax
//	movl	%eax, %ecx
//	jmp	parse_csv_.L276
//parse_csv_.L581:
//	leaq	1(%r8), %r12
//	cmpb	$45, %cl
//	jne	parse_csv_.L49
//	cmpq	%r12, %rbx
//	je	parse_csv_.L47
//	movsbl	1(%r8), %eax
//	cmpb	$48, %al
//	jne	parse_csv_.L50
//	xorl	%ecx, %ecx
//	jmp	parse_csv_.L53
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L490:
//	movsbl	(%r12), %eax
//	cmpb	$48, %al
//	jne	parse_csv_.L52
//parse_csv_.L53:
//	addq	$1, %r12
//	addq	$1, %rcx
//	cmpq	%r12, %rbx
//	jne	parse_csv_.L490
//	jmp	parse_csv_.L71
//parse_csv_.L346:
//	movq	%rcx, %rdi
//	jmp	parse_csv_.L238
//parse_csv_.L318:
//	movq	%rbx, %rdx
//parse_csv_.L159:
//	movl	%edx, %eax
//	movq	%rdx, %r12
//	subl	%ecx, %eax
//	movl	%eax, %ecx
//	jmp	parse_csv_.L165
//parse_csv_.L52:
//	leal	-48(%rax), %esi
//	cmpb	$9, %sil
//	ja	parse_csv_.L71
//parse_csv_.L246:
//	leaq	1(%r12), %rsi
//	subl	$48, %eax
//	negl	%eax
//	cmpq	%rsi, %rbx
//	je	parse_csv_.L73
//	movsbl	1(%r12), %ecx
//	leal	-48(%rcx), %r8d
//	cmpb	$9, %r8b
//	ja	parse_csv_.L73
//	leaq	-2(%rbx), %r10
//	xorl	%r8d, %r8d
//	leaq	-1(%rbx), %r9
//	jmp	parse_csv_.L58
//parse_csv_.L591:
//	leal	(%rax,%rax,4), %eax
//	subl	$48, %ecx
//	addl	%eax, %eax
//	subl	%ecx, %eax
//parse_csv_.L60:
//	leaq	1(%rsi), %r11
//	cmpq	%r9, %rsi
//	je	parse_csv_.L297
//	movsbl	1(%rsi), %ecx
//	leal	-48(%rcx), %r13d
//	cmpb	$9, %r13b
//	ja	parse_csv_.L297
//	movq	%rsi, %r11
//	subq	%r12, %r11
//	cmpq	$7, %r11
//	ja	parse_csv_.L61
//	leal	(%rax,%rax,4), %eax
//	subl	$48, %ecx
//	addl	%eax, %eax
//	subl	%ecx, %eax
//parse_csv_.L62:
//	leaq	2(%rsi), %r11
//	cmpq	%r10, %rsi
//	je	parse_csv_.L297
//	movsbl	2(%rsi), %ecx
//	leal	-48(%rcx), %r13d
//	cmpb	$9, %r13b
//	ja	parse_csv_.L297
//	leaq	2(%r8), %r11
//	cmpq	$7, %r11
//	ja	parse_csv_.L63
//	leal	(%rax,%rax,4), %eax
//	subl	$48, %ecx
//	addl	%eax, %eax
//	subl	%ecx, %eax
//parse_csv_.L64:
//	addq	$3, %rsi
//	addq	$3, %r8
//	cmpq	%rsi, %rbx
//	je	parse_csv_.L73
//	movsbl	(%rsi), %ecx
//	leal	-48(%rcx), %r11d
//	cmpb	$9, %r11b
//	ja	parse_csv_.L73
//parse_csv_.L58:
//	cmpq	$7, %r8
//	jbe	parse_csv_.L591
//	cmpl	$-214748364, %eax
//	jl	parse_csv_.L47
//	leal	(%rax,%rax,4), %eax
//	leal	-48(%rcx), %r11d
//	addl	%eax, %eax
//	addl	$2147483600, %ecx
//	cmpl	%ecx, %eax
//	jl	parse_csv_.L47
//	subl	%r11d, %eax
//	jmp	parse_csv_.L60
//parse_csv_.L284:
//	movq	%rbx, %r8
//	jmp	parse_csv_.L14
//parse_csv_.L69:
//	leal	-48(%rax), %esi
//	cmpb	$9, %sil
//	ja	parse_csv_.L247
//parse_csv_.L248:
//	leaq	1(%r12), %rsi
//	subl	$48, %eax
//	cmpq	%rsi, %rbx
//	je	parse_csv_.L73
//	movsbl	1(%r12), %ecx
//	leal	-48(%rcx), %r8d
//	cmpb	$9, %r8b
//	ja	parse_csv_.L73
//	leaq	-2(%rbx), %r11
//	xorl	%r8d, %r8d
//	movl	$2147483647, %r9d
//	leaq	-1(%rbx), %r10
//	jmp	parse_csv_.L75
//parse_csv_.L592:
//	leal	(%rax,%rax,4), %eax
//	leal	-48(%rcx,%rax,2), %eax
//parse_csv_.L77:
//	leaq	1(%rsi), %rcx
//	cmpq	%r10, %rsi
//	je	parse_csv_.L301
//	movzbl	1(%rsi), %r13d
//	leal	-48(%r13), %r14d
//	cmpb	$9, %r14b
//	ja	parse_csv_.L301
//	movq	%rsi, %rcx
//	subq	%r12, %rcx
//	cmpq	$7, %rcx
//	ja	parse_csv_.L78
//	leal	(%rax,%rax,4), %ecx
//	movsbl	%r13b, %eax
//	leal	-48(%rax,%rcx,2), %eax
//parse_csv_.L79:
//	leaq	2(%rsi), %rcx
//	cmpq	%r11, %rsi
//	je	parse_csv_.L301
//	movzbl	2(%rsi), %r13d
//	leal	-48(%r13), %r14d
//	cmpb	$9, %r14b
//	ja	parse_csv_.L301
//	leaq	2(%r8), %rcx
//	cmpq	$7, %rcx
//	ja	parse_csv_.L80
//	leal	(%rax,%rax,4), %ecx
//	movsbl	%r13b, %eax
//	leal	-48(%rax,%rcx,2), %eax
//parse_csv_.L81:
//	addq	$3, %rsi
//	addq	$3, %r8
//	cmpq	%rsi, %rbx
//	je	parse_csv_.L73
//	movsbl	(%rsi), %ecx
//	leal	-48(%rcx), %r13d
//	cmpb	$9, %r13b
//	ja	parse_csv_.L73
//parse_csv_.L75:
//	cmpq	$7, %r8
//	jbe	parse_csv_.L592
//	cmpl	$214748364, %eax
//	jg	parse_csv_.L47
//	leal	(%rax,%rax,4), %eax
//	leal	(%rax,%rax), %r13d
//	leal	-48(%rcx), %eax
//	movl	%r9d, %ecx
//	subl	%eax, %ecx
//	cmpl	%ecx, %r13d
//	jg	parse_csv_.L47
//	addl	%r13d, %eax
//	jmp	parse_csv_.L77
//parse_csv_.L577:
//	leal	-307(%rcx), %eax
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vdivsd	parse_csv_.LC13(%rip), %xmm2, %xmm2
//	vmovsd	%xmm2, (%rsp)
//	vcvtsi2sdq	%rax, %xmm1, %xmm1
//	jmp	parse_csv_.L523
//parse_csv_.L556:
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	vmovaps	%xmm5, (%rsp)
//	vmovsd	parse_csv_.LC12(%rip), %xmm0
//	vmovsd	%xmm4, 16(%rsp)
//	vmovsd	%xmm2, 32(%rsp)
//	call	pow
//	vmovsd	32(%rsp), %xmm2
//	movq	%r12, %rdi
//	vmovapd	(%rsp), %xmm5
//	vmulsd	%xmm0, %xmm2, %xmm2
//	vmovsd	16(%rsp), %xmm4
//	jmp	parse_csv_.L204
//parse_csv_.L146:
//	cmpq	%r10, %rbx
//	je	parse_csv_.L151
//	movzbl	(%r10), %eax
//	andl	$-33, %eax
//	cmpb	$73, %al
//	jne	parse_csv_.L151
//	movq	%r10, %rax
//	movl	$parse_csv_.LC4, %ecx
//	movl	$parse_csv_.LC5, %edx
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L154:
//	addq	$1, %rdx
//	movzbl	(%rdx), %edi
//	addq	$1, %rcx
//	addq	$1, %rax
//	testb	%dil, %dil
//	je	parse_csv_.L317
//	movzbl	(%rcx), %esi
//	testb	%sil, %sil
//	je	parse_csv_.L317
//	cmpq	%rax, %rbx
//	je	parse_csv_.L151
//	movzbl	(%rax), %r8d
//	cmpb	%r8b, %sil
//	je	parse_csv_.L154
//	cmpb	%r8b, %dil
//	je	parse_csv_.L154
//parse_csv_.L151:
//	vmovss	parse_csv_.LC10(%rip), %xmm0
//	movq	%r10, %rdi
//	vmovss	parse_csv_.LC11(%rip), %xmm2
//	jmp	parse_csv_.L264
//parse_csv_.L215:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L219
//	cmpb	$40, (%rax)
//	jne	parse_csv_.L219
//	movq	%rax, %rdx
//parse_csv_.L221:
//	addq	$1, %rdx
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L220
//	cmpb	$41, (%rdx)
//	jne	parse_csv_.L221
//	leaq	1(%rdx), %rax
//	jmp	parse_csv_.L219
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L286:
//	movq	%rdx, %r8
//	jmp	parse_csv_.L14
//parse_csv_.L586:
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	vmovsd	%xmm2, 32(%rsp)
//	call	pow
//	vmovsd	32(%rsp), %xmm2
//	movq	%r12, %rdi
//	vmulsd	%xmm0, %xmm2, %xmm2
//	jmp	parse_csv_.L83
//parse_csv_.L557:
//	vdivsd	parse_csv_.LC13(%rip), %xmm2, %xmm2
//	movl	$-307, %edx
//	vmovsd	%xmm2, 32(%rsp)
//	subl	%eax, %edx
//	movl	%edx, %eax
//	jmp	parse_csv_.L524
//parse_csv_.L247:
//	xorl	%eax, %eax
//	testq	%rcx, %rcx
//	jne	parse_csv_.L66
//	jmp	parse_csv_.L47
//parse_csv_.L587:
//	leal	-307(%rdx), %eax
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vdivsd	parse_csv_.LC13(%rip), %xmm2, %xmm2
//	vmovsd	%xmm2, 32(%rsp)
//	vcvtsi2sdq	%rax, %xmm1, %xmm1
//	call	pow
//	vmovsd	32(%rsp), %xmm2
//	movq	%r12, %rdi
//	vdivsd	%xmm0, %xmm2, %xmm2
//	jmp	parse_csv_.L83
//parse_csv_.L100:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L302
//	movq	%rax, %rdi
//parse_csv_.L93:
//	movzbl	(%rdi), %eax
//	andl	$-33, %eax
//	cmpb	$73, %al
//	jne	parse_csv_.L83
//	movq	%rdi, %rdx
//	movl	$parse_csv_.LC2, %ecx
//	movl	$parse_csv_.LC3, %eax
//parse_csv_.L105:
//	addq	$1, %rax
//	movzbl	(%rax), %esi
//	addq	$1, %rcx
//	addq	$1, %rdx
//	testb	%sil, %sil
//	je	parse_csv_.L103
//	movzbl	(%rcx), %r9d
//	testb	%r9b, %r9b
//	je	parse_csv_.L103
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L83
//	movzbl	(%rdx), %r8d
//	cmpb	%r8b, %r9b
//	je	parse_csv_.L105
//	cmpb	%r8b, %sil
//	je	parse_csv_.L105
//	jmp	parse_csv_.L83
//	.p2align 4,,10
//	.p2align 3
//parse_csv_.L558:
//	movq	%r10, %rax
//	movl	%edx, %ecx
//	jmp	parse_csv_.L127
//parse_csv_.L583:
//	vdivsd	parse_csv_.LC13(%rip), %xmm2, %xmm2
//	movl	$-307, %edx
//	vmovsd	%xmm2, 32(%rsp)
//	subl	%eax, %edx
//	movl	%edx, %eax
//	jmp	parse_csv_.L520
//parse_csv_.L563:
//	movq	%rsi, %rax
//	jmp	parse_csv_.L130
//parse_csv_.L188:
//	leal	-48(%rdx), %esi
//	movq	%rax, %r12
//	cmpb	$9, %sil
//	jbe	parse_csv_.L261
//	jmp	parse_csv_.L235
//parse_csv_.L297:
//	movq	%r11, %rsi
//parse_csv_.L73:
//	movq	%rsi, %r12
//	jmp	parse_csv_.L66
//parse_csv_.L80:
//	cmpl	$214748364, %eax
//	jg	parse_csv_.L47
//	leal	(%rax,%rax,4), %ecx
//	movsbl	%r13b, %eax
//	movl	%r9d, %r13d
//	subl	$48, %eax
//	addl	%ecx, %ecx
//	subl	%eax, %r13d
//	cmpl	%r13d, %ecx
//	jg	parse_csv_.L47
//	addl	%ecx, %eax
//	jmp	parse_csv_.L81
//parse_csv_.L63:
//	cmpl	$-214748364, %eax
//	jl	parse_csv_.L47
//	leal	(%rax,%rax,4), %eax
//	leal	-48(%rcx), %r11d
//	addl	%eax, %eax
//	addl	$2147483600, %ecx
//	cmpl	%ecx, %eax
//	jl	parse_csv_.L47
//	subl	%r11d, %eax
//	jmp	parse_csv_.L64
//parse_csv_.L78:
//	cmpl	$214748364, %eax
//	jg	parse_csv_.L47
//	leal	(%rax,%rax,4), %ecx
//	movsbl	%r13b, %eax
//	movl	%r9d, %r13d
//	subl	$48, %eax
//	addl	%ecx, %ecx
//	subl	%eax, %r13d
//	cmpl	%r13d, %ecx
//	jg	parse_csv_.L47
//	addl	%ecx, %eax
//	jmp	parse_csv_.L79
//parse_csv_.L61:
//	cmpl	$-214748364, %eax
//	jl	parse_csv_.L47
//	leal	(%rax,%rax,4), %eax
//	leal	-48(%rcx), %r11d
//	addl	%eax, %eax
//	addl	$2147483600, %ecx
//	cmpl	%ecx, %eax
//	jl	parse_csv_.L47
//	subl	%r11d, %eax
//	jmp	parse_csv_.L62
//parse_csv_.L585:
//	movq	%rax, %rdx
//parse_csv_.L143:
//	addq	$1, %rdx
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L142
//	cmpb	$41, (%rdx)
//	jne	parse_csv_.L143
//	leaq	1(%rdx), %rax
//	jmp	parse_csv_.L219
//parse_csv_.L95:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L99
//	cmpb	$40, (%rax)
//	jne	parse_csv_.L99
//	movq	%rax, %rdx
//parse_csv_.L101:
//	addq	$1, %rdx
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L100
//	cmpb	$41, (%rdx)
//	jne	parse_csv_.L101
//parse_csv_.L536:
//	leaq	1(%rdx), %rax
//	jmp	parse_csv_.L99
//parse_csv_.L317:
//	movq	%rax, %r10
//	jmp	parse_csv_.L151
//parse_csv_.L334:
//	movq	%r14, %r12
//	movl	%edx, %eax
//	jmp	parse_csv_.L187
//parse_csv_.L327:
//	movq	%r13, %r12
//	jmp	parse_csv_.L187
//parse_csv_.L582:
//	vxorpd	%xmm1, %xmm1, %xmm1
//	vcvtsi2sd	%eax, %xmm1, %xmm1
//	vmovsd	%xmm2, 32(%rsp)
//	vmovsd	parse_csv_.LC12(%rip), %xmm0
//	call	pow
//	vmovsd	32(%rsp), %xmm2
//	movq	%r12, %rdi
//	vmulsd	%xmm0, %xmm2, %xmm2
//	jmp	parse_csv_.L83
//parse_csv_.L590:
//	movq	%rax, %rdx
//parse_csv_.L23:
//	addq	$1, %rdx
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L287
//	cmpb	$41, (%rdx)
//	jne	parse_csv_.L23
//	jmp	parse_csv_.L536
//parse_csv_.L25:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L31
//	movzbl	(%rax), %edx
//	andl	$-33, %edx
//	cmpb	$73, %dl
//	jne	parse_csv_.L31
//	movq	%rax, %rdx
//	movl	$parse_csv_.LC4, %esi
//	movl	$parse_csv_.LC5, %ecx
//parse_csv_.L34:
//	addq	$1, %rcx
//	movzbl	(%rcx), %r8d
//	addq	$1, %rsi
//	addq	$1, %rdx
//	testb	%r8b, %r8b
//	je	parse_csv_.L290
//	movzbl	(%rsi), %edi
//	testb	%dil, %dil
//	je	parse_csv_.L290
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L31
//	movzbl	(%rdx), %r9d
//	cmpb	%r9b, %dil
//	je	parse_csv_.L34
//	cmpb	%r9b, %r8b
//	je	parse_csv_.L34
//parse_csv_.L31:
//	vmovss	parse_csv_.LC10(%rip), %xmm0
//	movq	%rax, %rdi
//	vmovss	parse_csv_.LC11(%rip), %xmm2
//	jmp	parse_csv_.L251
//parse_csv_.L571:
//	movq	%rsi, %rax
//parse_csv_.L40:
//	movl	%eax, %edx
//	movq	%rax, %r12
//	subl	%ecx, %edx
//	jmp	parse_csv_.L274
//parse_csv_.L290:
//	movq	%rdx, %rax
//	jmp	parse_csv_.L31
//parse_csv_.L223:
//	cmpq	%r9, %rbx
//	je	parse_csv_.L227
//	movzbl	(%r9), %eax
//	andl	$-33, %eax
//	cmpb	$73, %al
//	jne	parse_csv_.L227
//	movq	%r9, %rax
//	movl	$parse_csv_.LC4, %ecx
//	movl	$parse_csv_.LC5, %edx
//parse_csv_.L230:
//	addq	$1, %rdx
//	movzbl	(%rdx), %edi
//	addq	$1, %rcx
//	addq	$1, %rax
//	testb	%dil, %dil
//	je	parse_csv_.L340
//	movzbl	(%rcx), %esi
//	testb	%sil, %sil
//	je	parse_csv_.L340
//	cmpq	%rax, %rbx
//	je	parse_csv_.L227
//	movzbl	(%rax), %r8d
//	cmpb	%r8b, %sil
//	je	parse_csv_.L230
//	cmpb	%r8b, %dil
//	je	parse_csv_.L230
//parse_csv_.L227:
//	vmovss	parse_csv_.LC10(%rip), %xmm0
//	movq	%r9, %rdi
//	vmovss	parse_csv_.LC11(%rip), %xmm2
//	jmp	parse_csv_.L264
//parse_csv_.L340:
//	movq	%rax, %r9
//	jmp	parse_csv_.L227
//parse_csv_.L568:
//	movq	%rcx, %r8
//	jmp	parse_csv_.L14
//parse_csv_.L103:
//	cmpq	%rdx, %rbx
//	je	parse_csv_.L107
//	movzbl	(%rdx), %eax
//	andl	$-33, %eax
//	cmpb	$73, %al
//	jne	parse_csv_.L107
//	movq	%rdx, %rax
//	movl	$parse_csv_.LC4, %esi
//	movl	$parse_csv_.LC5, %ecx
//parse_csv_.L110:
//	addq	$1, %rcx
//	movzbl	(%rcx), %edi
//	addq	$1, %rsi
//	addq	$1, %rax
//	testb	%dil, %dil
//	je	parse_csv_.L304
//	movzbl	(%rsi), %r9d
//	testb	%r9b, %r9b
//	je	parse_csv_.L304
//	cmpq	%rax, %rbx
//	je	parse_csv_.L107
//	movzbl	(%rax), %r8d
//	cmpb	%r8b, %dil
//	je	parse_csv_.L110
//	cmpb	%r8b, %r9b
//	je	parse_csv_.L110
//parse_csv_.L107:
//	vmovss	parse_csv_.LC10(%rip), %xmm0
//	movq	%rdx, %rdi
//	vmovss	parse_csv_.LC11(%rip), %xmm2
//	jmp	parse_csv_.L251
//parse_csv_.L330:
//	movq	%rsi, %r12
//	movl	%edx, %eax
//	jmp	parse_csv_.L187
//parse_csv_.L328:
//	movq	%rbx, %r12
//	movl	%edx, %eax
//	jmp	parse_csv_.L187
//parse_csv_.L323:
//	movq	%rdx, %r12
//	jmp	parse_csv_.L187
//parse_csv_.L321:
//	movq	%rbx, %r12
//	jmp	parse_csv_.L187
//parse_csv_.L171:
//	leal	-48(%rax), %edx
//	cmpb	$9, %dl
//	jbe	parse_csv_.L260
//	jmp	parse_csv_.L235
//parse_csv_.L169:
//	cmpq	%r12, %rbx
//	je	parse_csv_.L235
//	movsbl	1(%rax), %edx
//	movq	%r12, %rax
//	jmp	parse_csv_.L168
//parse_csv_.L220:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L344
//	movq	%rax, %rdi
//	jmp	parse_csv_.L213
//parse_csv_.L304:
//	movq	%rax, %rdx
//	jmp	parse_csv_.L107
//parse_csv_.L344:
//	movq	%rbx, %rdi
//	jmp	parse_csv_.L522
//parse_csv_.L551:
//	call	__stack_chk_fail
//parse_csv_.L142:
//	cmpq	%rax, %rbx
//	je	parse_csv_.L235
//	jmp	parse_csv_.L135
//parse_csv_.L302:
//	movq	%rbx, %rdi
//	jmp	parse_csv_.L83
//parse_csv_.L67:
//	leal	-48(%rax), %ecx
//	movq	%r8, %r12
//	cmpb	$9, %cl
//	jbe	parse_csv_.L248
//	jmp	parse_csv_.L47
//parse_csv_.L301:
//	movq	%rcx, %rsi
//	jmp	parse_csv_.L73
//parse_csv_.L50:
//	leal	-48(%rax), %ecx
//	cmpb	$9, %cl
//	jbe	parse_csv_.L246
//	jmp	parse_csv_.L47
//parse_csv_.L49:
//	cmpq	%r12, %rbx
//	je	parse_csv_.L47
//	movsbl	1(%r8), %eax
//	movq	%r12, %r8
//	jmp	parse_csv_.L48
//	.cfi_endproc
//parse_csv_.LFE13901:
//	.size	_Z9parse_csvPKcmPf, .-_Z9parse_csvPKcmPf
//	.section	.text.unlikely
//parse_csv_.LCOLDE15:
//	.text
//parse_csv_.LHOTE15:
//	.section	.text.unlikely
//parse_csv_.LCOLDB16:
//	.section	.text.startup,"ax",@progbits
//parse_csv_.LHOTB16:
//	.p2align 4,,15
//	.type	_GLOBAL__sub_I__Z9parse_csvPKcmPf, @function
//_GLOBAL__sub_I__Z9parse_csvPKcmPf:
//parse_csv_.LFB15504:
//	.cfi_startproc
//	subq	$8, %rsp
//	.cfi_def_cfa_offset 16
//	movl	$_ZStL8__ioinit, %edi
//	call	_ZNSt8ios_base4InitC1Ev
//	movl	$__dso_handle, %edx
//	movl	$_ZStL8__ioinit, %esi
//	movl	$_ZNSt8ios_base4InitD1Ev, %edi
//	addq	$8, %rsp
//	.cfi_def_cfa_offset 8
//	jmp	__cxa_atexit
//	.cfi_endproc
//parse_csv_.LFE15504:
//	.size	_GLOBAL__sub_I__Z9parse_csvPKcmPf, .-_GLOBAL__sub_I__Z9parse_csvPKcmPf
//	.section	.text.unlikely
//parse_csv_.LCOLDE16:
//	.section	.text.startup
//parse_csv_.LHOTE16:
//	.section	.init_array,"aw"
//	.align 8
//	.quad	_GLOBAL__sub_I__Z9parse_csvPKcmPf
//	.section	.rodata
//	.align 32
//	.type	_ZN5boost6spirit13char_encodingL16ascii_char_typesE, @object
//	.size	_ZN5boost6spirit13char_encodingL16ascii_char_typesE, 128
//_ZN5boost6spirit13char_encodingL16ascii_char_typesE:
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	72
//	.byte	72
//	.byte	72
//	.byte	72
//	.byte	72
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	8
//	.byte	64
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	3
//	.byte	3
//	.byte	3
//	.byte	3
//	.byte	3
//	.byte	3
//	.byte	3
//	.byte	3
//	.byte	3
//	.byte	3
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	38
//	.byte	38
//	.byte	38
//	.byte	38
//	.byte	38
//	.byte	38
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	36
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	22
//	.byte	22
//	.byte	22
//	.byte	22
//	.byte	22
//	.byte	22
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	20
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	-128
//	.byte	8
//#	.local	_ZStL8__ioinit
//#	.comm	_ZStL8__ioinit,1,1
//	.section	.rodata.cst8,"aM",@progbits,8
//	.align 8
//parse_csv_.LC6:
//	.long	0
//	.long	0
//	.align 8
//parse_csv_.LC7:
//	.long	0
//	.long	1072693248
//	.section	.rodata.cst4,"aM",@progbits,4
//	.align 4
//parse_csv_.LC8:
//	.long	2143289344
//	.align 4
//parse_csv_.LC9:
//	.long	4290772992
//	.align 4
//parse_csv_.LC10:
//	.long	2139095040
//	.align 4
//parse_csv_.LC11:
//	.long	4286578688
//	.section	.rodata.cst8
//	.align 8
//parse_csv_.LC12:
//	.long	0
//	.long	1076101120
//	.align 8
//parse_csv_.LC13:
//	.long	1017934899
//	.long	2142010143
//	.section	.rodata.cst16,"aM",@progbits,16
//	.align 16
//parse_csv_.LC14:
//	.long	0
//	.long	-2147483648
//	.long	0
//	.long	0
//	.hidden	__dso_handle
//)");

// version with qi::ascii::blank
asm(R"(
	.section	.rodata.str1.1,"aMS",@progbits,1
parse_csv_.LC0:
	.string	"NAN"
parse_csv_.LC1:
	.string	"nan"
parse_csv_.LC2:
	.string	"INF"
parse_csv_.LC3:
	.string	"inf"
parse_csv_.LC4:
	.string	"INITY"
parse_csv_.LC5:
	.string	"inity"
	.section	.text.unlikely,"ax",@progbits
parse_csv_.LCOLDB15:
	.text
parse_csv_.LHOTB15:
	.p2align 4,,15
	.globl	_Z9parse_csvPKcmPf
	.type	_Z9parse_csvPKcmPf, @function
_Z9parse_csvPKcmPf:
parse_csv_.LFB13901:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	leaq	(%rdi,%rsi), %rbx
	subq	$144, %rsp
	.cfi_def_cfa_offset 192
	movq	%fs:40, %rax
	movq	%rax, 136(%rsp)
	xorl	%eax, %eax
	leaq	40(%rsp), %rax
	movq	%rdx, 40(%rsp)
	movq	%rax, 64(%rsp)
	movq	%rax, 48(%rsp)
	movq	%rax, 88(%rsp)
	movq	%rax, 104(%rsp)
	movb	$44, 120(%rsp)
	cmpq	%rdi, %rbx
	je	parse_csv_.L2
	.p2align 4,,10
	.p2align 3
parse_csv_.L553:
	movsbl	(%rdi), %eax
	cmpl	$9, %eax
	movl	%eax, %ecx
	sete	%dl
	cmpl	$32, %eax
	sete	%al
	orb	%dl, %al
	je	parse_csv_.L3
	addq	$1, %rdi
	cmpq	%rdi, %rbx
	jne	parse_csv_.L553
parse_csv_.L2:
	movq	%rbx, %rdi
parse_csv_.L114:
	movq	40(%rsp), %rax
	leaq	4(%rax), %rdx
	movl	$0x7fc00000, (%rax)
	movq	%rdx, 40(%rsp)
parse_csv_.L255:
	vmovsd	parse_csv_.LC14(%rip), %xmm5
	vmovsd	parse_csv_.LC12(%rip), %xmm4
	.p2align 4,,10
	.p2align 3
parse_csv_.L119:
	cmpq	%rdi, %rbx
	je	parse_csv_.L116
parse_csv_.L564:
	movsbl	(%rdi), %eax
	cmpl	$9, %eax
	je	parse_csv_.L362
	cmpl	$32, %eax
	je	parse_csv_.L362
	cmpb	%al, 120(%rsp)
	jne	parse_csv_.L116
parse_csv_.L527:
	addq	$1, %rdi
	cmpq	%rdi, %rbx
	je	parse_csv_.L120
	movsbl	(%rdi), %eax
	cmpl	$9, %eax
	movl	%eax, %ecx
	sete	%dl
	cmpl	$32, %eax
	sete	%al
	orb	%al, %dl
	jne	parse_csv_.L527
	leal	-43(%rcx), %eax
	xorl	%ebp, %ebp
	movq	%rdi, %r11
	testb	$-3, %al
	je	parse_csv_.L554
parse_csv_.L123:
	cmpb	$48, %cl
	jne	parse_csv_.L125
	movq	%r11, %rax
	jmp	parse_csv_.L127
	.p2align 4,,10
	.p2align 3
parse_csv_.L130:
	movzbl	(%rax), %esi
	cmpb	$48, %sil
	jne	parse_csv_.L555
parse_csv_.L127:
	addq	$1, %rax
	movq	%rax, %r8
	subq	%r11, %r8
	cmpq	%rax, %rbx
	jne	parse_csv_.L130
parse_csv_.L128:
	testq	%r8, %r8
	je	parse_csv_.L131
	vxorpd	%xmm2, %xmm2, %xmm2
parse_csv_.L132:
	cmpq	%rax, %rbx
	je	parse_csv_.L353
	movzbl	(%rax), %ecx
	movl	$1, %edx
	cmpb	$46, %cl
	je	parse_csv_.L556
parse_csv_.L158:
	testb	%dl, %dl
	je	parse_csv_.L238
	andl	$-33, %ecx
	cmpb	$69, %cl
	jne	parse_csv_.L169
	addq	$1, %rax
	xorl	%ecx, %ecx
parse_csv_.L168:
	cmpq	%rax, %rbx
	je	parse_csv_.L238
	movzbl	(%rax), %esi
	leal	-43(%rsi), %r8d
	movsbl	%sil, %edx
	andl	$253, %r8d
	je	parse_csv_.L557
parse_csv_.L170:
	cmpb	$48, %dl
	jne	parse_csv_.L190
	movq	%rax, %r12
	jmp	parse_csv_.L193
	.p2align 4,,10
	.p2align 3
parse_csv_.L509:
	movsbl	(%r12), %edx
	cmpb	$48, %dl
	jne	parse_csv_.L192
parse_csv_.L193:
	addq	$1, %r12
	movq	%r12, %rsi
	subq	%rax, %rsi
	cmpq	%r12, %rbx
	jne	parse_csv_.L509
parse_csv_.L541:
	testq	%rsi, %rsi
	je	parse_csv_.L238
parse_csv_.L534:
	xorl	%eax, %eax
parse_csv_.L189:
	subl	%ecx, %eax
	jns	parse_csv_.L558
	vmovsd	%xmm4, 16(%rsp)
	vmovaps	%xmm5, (%rsp)
	cmpl	$-307, %eax
	jl	parse_csv_.L559
	vmovsd	%xmm2, 32(%rsp)
	negl	%eax
parse_csv_.L530:
	vmovsd	parse_csv_.LC12(%rip), %xmm0
	vxorpd	%xmm1, %xmm1, %xmm1
	vcvtsi2sd	%eax, %xmm1, %xmm1
	call	pow
	vmovsd	32(%rsp), %xmm2
	movq	%r12, %rdi
	vmovapd	(%rsp), %xmm5
	vdivsd	%xmm0, %xmm2, %xmm2
	vmovsd	16(%rsp), %xmm4
	jmp	parse_csv_.L206
parse_csv_.L125:
	leal	-48(%rcx), %eax
	cmpb	$9, %al
	jbe	parse_csv_.L560
parse_csv_.L131:
	cmpq	%r11, %rbx
	je	parse_csv_.L238
	andl	$-33, %ecx
	movq	%r11, %rax
	cmpb	$78, %cl
	jne	parse_csv_.L137
	movl	$parse_csv_.LC0, %esi
	movl	$parse_csv_.LC1, %ecx
	.p2align 4,,10
	.p2align 3
parse_csv_.L141:
	addq	$1, %rcx
	movzbl	(%rcx), %r9d
	addq	$1, %rsi
	addq	$1, %rax
	testb	%r9b, %r9b
	je	parse_csv_.L139
	movzbl	(%rsi), %r8d
	testb	%r8b, %r8b
	je	parse_csv_.L139
	cmpq	%rax, %rbx
	je	parse_csv_.L316
	movzbl	(%rax), %r10d
	cmpb	%r10b, %r8b
	je	parse_csv_.L141
	cmpb	%r10b, %r9b
	je	parse_csv_.L141
parse_csv_.L316:
	movq	%r11, %rax
parse_csv_.L137:
	movzbl	(%rax), %ecx
	andl	$-33, %ecx
	cmpb	$73, %cl
	jne	parse_csv_.L318
	movq	%rax, %r11
	movl	$parse_csv_.LC2, %esi
	movl	$parse_csv_.LC3, %ecx
	.p2align 4,,10
	.p2align 3
parse_csv_.L151:
	addq	$1, %rcx
	movzbl	(%rcx), %r8d
	addq	$1, %rsi
	addq	$1, %r11
	testb	%r8b, %r8b
	je	parse_csv_.L148
	movzbl	(%rsi), %r10d
	testb	%r10b, %r10b
	je	parse_csv_.L148
	cmpq	%r11, %rbx
	je	parse_csv_.L149
	movzbl	(%r11), %r9d
	cmpb	%r9b, %r8b
	je	parse_csv_.L151
	cmpb	%r9b, %r10b
	je	parse_csv_.L151
parse_csv_.L318:
	vxorpd	%xmm2, %xmm2, %xmm2
parse_csv_.L587:
	movzbl	(%rax), %ecx
	cmpb	$46, %cl
	jne	parse_csv_.L158
parse_csv_.L556:
	leaq	1(%rax), %rcx
	cmpq	%rcx, %rbx
	je	parse_csv_.L159
	movzbl	1(%rax), %esi
	leal	-48(%rsi), %r8d
	cmpb	$9, %r8b
	jbe	parse_csv_.L561
	testb	%dl, %dl
	je	parse_csv_.L238
	andl	$-33, %esi
	cmpb	$69, %sil
	je	parse_csv_.L562
	movq	%rcx, %rdi
parse_csv_.L256:
	vmovsd	parse_csv_.LC7(%rip), %xmm0
	vucomisd	%xmm0, %xmm2
	jp	parse_csv_.L206
	je	parse_csv_.L563
parse_csv_.L206:
	testb	%bpl, %bpl
	je	parse_csv_.L234
parse_csv_.L581:
	vxorpd	%xmm5, %xmm2, %xmm2
	vcvtsd2ss	%xmm2, %xmm2, %xmm2
parse_csv_.L235:
	movq	88(%rsp), %rdx
	movq	(%rdx), %rax
	leaq	4(%rax), %rcx
	vmovss	%xmm2, (%rax)
	movq	%rcx, (%rdx)
	cmpq	%rdi, %rbx
	jne	parse_csv_.L564
	.p2align 4,,10
	.p2align 3
parse_csv_.L116:
	movq	136(%rsp), %rsi
	xorq	%fs:40, %rsi
	movl	$1, %eax
	jne	parse_csv_.L565
	addq	$144, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
parse_csv_.L370:
	.cfi_restore_state
	addq	$1, %rdi
	cmpq	%rdi, %rbx
	je	parse_csv_.L120
parse_csv_.L238:
	movsbl	(%rdi), %eax
	cmpl	$9, %eax
	je	parse_csv_.L370
	cmpl	$32, %eax
	je	parse_csv_.L370
parse_csv_.L236:
	movq	104(%rsp), %rdx
	movq	(%rdx), %rax
	leaq	4(%rax), %rcx
	movl	$0x7fc00000, (%rax)
	movq	%rcx, (%rdx)
	jmp	parse_csv_.L119
	.p2align 4,,10
	.p2align 3
parse_csv_.L362:
	addq	$1, %rdi
	jmp	parse_csv_.L119
	.p2align 4,,10
	.p2align 3
parse_csv_.L120:
	movq	%rbx, %rdi
	jmp	parse_csv_.L236
parse_csv_.L555:
	leal	-48(%rsi), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L128
parse_csv_.L129:
	movsbl	%sil, %edx
	vxorpd	%xmm2, %xmm2, %xmm2
	subl	$48, %edx
	vcvtsi2sd	%edx, %xmm2, %xmm2
	vaddsd	parse_csv_.LC6(%rip), %xmm2, %xmm2
	leaq	1(%rax), %rdx
	cmpq	%rdx, %rbx
	je	parse_csv_.L311
	movsbl	1(%rax), %ecx
	leal	-48(%rcx), %esi
	cmpb	$9, %sil
	ja	parse_csv_.L313
	vxorpd	%xmm1, %xmm1, %xmm1
	leaq	2(%rax), %rsi
	subl	$48, %ecx
	vmovsd	parse_csv_.LC12(%rip), %xmm0
	vcvtsi2sd	%ecx, %xmm1, %xmm1
	vfmadd132sd	%xmm0, %xmm1, %xmm2
	cmpq	%rsi, %rbx
	je	parse_csv_.L311
	movsbl	2(%rax), %ecx
	leal	-48(%rcx), %eax
	cmpb	$9, %al
	ja	parse_csv_.L566
	leaq	-2(%rbx), %rsi
	vmovapd	%xmm0, %xmm3
	leaq	-1(%rbx), %r8
	jmp	parse_csv_.L135
	.p2align 4,,10
	.p2align 3
parse_csv_.L567:
	movsbl	2(%rdx), %ecx
	leal	-48(%rcx), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L132
	subl	$48, %ecx
	vxorpd	%xmm1, %xmm1, %xmm1
	addq	$3, %rdx
	vcvtsi2sd	%ecx, %xmm1, %xmm1
	vfmadd132sd	%xmm3, %xmm1, %xmm2
	cmpq	%rdx, %rbx
	je	parse_csv_.L311
	movsbl	(%rdx), %eax
	leal	-48(%rax), %ecx
	cmpb	$9, %cl
	ja	parse_csv_.L313
	subl	$48, %eax
	vxorpd	%xmm1, %xmm1, %xmm1
	vcvtsi2sd	%eax, %xmm1, %xmm1
	leaq	1(%rdx), %rax
	vfmadd132sd	%xmm3, %xmm1, %xmm2
	cmpq	%rdx, %r8
	je	parse_csv_.L132
	movsbl	1(%rdx), %ecx
	leal	-48(%rcx), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L132
parse_csv_.L135:
	vxorpd	%xmm1, %xmm1, %xmm1
	leaq	2(%rdx), %rax
	subl	$48, %ecx
	vcvtsi2sd	%ecx, %xmm1, %xmm1
	vfmadd132sd	%xmm0, %xmm1, %xmm2
	cmpq	%rdx, %rsi
	jne	parse_csv_.L567
	jmp	parse_csv_.L132
	.p2align 4,,10
	.p2align 3
parse_csv_.L3:
	leal	-43(%rcx), %edx
	xorl	%ebp, %ebp
	movq	%rdi, %r10
	andl	$253, %edx
	je	parse_csv_.L568
parse_csv_.L5:
	movq	%r10, %r8
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
parse_csv_.L9:
	movzbl	(%r8), %esi
	cmpb	$48, %sil
	jne	parse_csv_.L7
	addq	$1, %r8
	addq	$1, %rdx
	cmpq	%r8, %rbx
	jne	parse_csv_.L9
	testq	%rdx, %rdx
	jne	parse_csv_.L569
parse_csv_.L240:
	andl	$-33, %ecx
	cmpb	$78, %cl
	jne	parse_csv_.L16
	movq	%r10, %rdx
	movl	$parse_csv_.LC0, %esi
	movl	$parse_csv_.LC1, %ecx
	.p2align 4,,10
	.p2align 3
parse_csv_.L19:
	addq	$1, %rcx
	movzbl	(%rcx), %r8d
	addq	$1, %rsi
	addq	$1, %rdx
	testb	%r8b, %r8b
	je	parse_csv_.L15
	movzbl	(%rsi), %r9d
	testb	%r9b, %r9b
	je	parse_csv_.L15
	cmpq	%rdx, %rbx
	je	parse_csv_.L16
	movzbl	(%rdx), %r11d
	cmpb	%r11b, %r8b
	je	parse_csv_.L19
	cmpb	%r11b, %r9b
	je	parse_csv_.L19
parse_csv_.L17:
	cmpq	%r10, %rbx
	je	parse_csv_.L47
parse_csv_.L291:
	movq	%r10, %r8
	vxorpd	%xmm2, %xmm2, %xmm2
	jmp	parse_csv_.L26
	.p2align 4,,10
	.p2align 3
parse_csv_.L554:
	leaq	1(%rdi), %r11
	cmpb	$45, %cl
	sete	%bpl
	cmpq	%r11, %rbx
	je	parse_csv_.L238
	movzbl	1(%rdi), %ecx
	jmp	parse_csv_.L123
	.p2align 4,,10
	.p2align 3
parse_csv_.L7:
	leal	-48(%rsi), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L570
	leaq	1(%r8), %rdx
	movsbl	%sil, %eax
	vxorpd	%xmm2, %xmm2, %xmm2
	subl	$48, %eax
	vcvtsi2sd	%eax, %xmm2, %xmm2
	vaddsd	parse_csv_.LC6(%rip), %xmm2, %xmm2
	cmpq	%rdx, %rbx
	je	parse_csv_.L287
	movsbl	1(%r8), %eax
	leal	-48(%rax), %ecx
	cmpb	$9, %cl
	ja	parse_csv_.L289
	vxorpd	%xmm1, %xmm1, %xmm1
	leaq	2(%r8), %rcx
	subl	$48, %eax
	vmovsd	parse_csv_.LC12(%rip), %xmm0
	vcvtsi2sd	%eax, %xmm1, %xmm1
	vfmadd132sd	%xmm0, %xmm1, %xmm2
	cmpq	%rcx, %rbx
	je	parse_csv_.L287
	movsbl	2(%r8), %eax
	leal	-48(%rax), %esi
	cmpb	$9, %sil
	ja	parse_csv_.L571
	leaq	-2(%rbx), %rcx
	vmovapd	%xmm0, %xmm3
	leaq	-1(%rbx), %rsi
	jmp	parse_csv_.L12
	.p2align 4,,10
	.p2align 3
parse_csv_.L572:
	movsbl	2(%rdx), %eax
	leal	-48(%rax), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L14
	subl	$48, %eax
	vxorpd	%xmm1, %xmm1, %xmm1
	addq	$3, %rdx
	vcvtsi2sd	%eax, %xmm1, %xmm1
	vfmadd132sd	%xmm3, %xmm1, %xmm2
	cmpq	%rdx, %rbx
	je	parse_csv_.L287
	movsbl	(%rdx), %eax
	leal	-48(%rax), %r8d
	cmpb	$9, %r8b
	ja	parse_csv_.L289
	vxorpd	%xmm1, %xmm1, %xmm1
	leaq	1(%rdx), %r8
	subl	$48, %eax
	vcvtsi2sd	%eax, %xmm1, %xmm1
	vfmadd132sd	%xmm3, %xmm1, %xmm2
	cmpq	%rdx, %rsi
	je	parse_csv_.L14
	movsbl	1(%rdx), %eax
	leal	-48(%rax), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L14
parse_csv_.L12:
	vxorpd	%xmm1, %xmm1, %xmm1
	leaq	2(%rdx), %r8
	subl	$48, %eax
	vcvtsi2sd	%eax, %xmm1, %xmm1
	vfmadd132sd	%xmm0, %xmm1, %xmm2
	cmpq	%rdx, %rcx
	jne	parse_csv_.L572
parse_csv_.L14:
	cmpq	%r8, %rbx
	je	parse_csv_.L352
	movl	$1, %eax
parse_csv_.L26:
	movzbl	(%r8), %edx
	cmpb	$46, %dl
	je	parse_csv_.L276
	testb	%al, %al
	jne	parse_csv_.L573
	.p2align 4,,10
	.p2align 3
parse_csv_.L47:
	movsbl	(%rdi), %eax
	cmpl	$9, %eax
	je	parse_csv_.L361
	cmpl	$32, %eax
	jne	parse_csv_.L114
parse_csv_.L361:
	addq	$1, %rdi
	cmpq	%rdi, %rbx
	jne	parse_csv_.L47
	jmp	parse_csv_.L2
	.p2align 4,,10
	.p2align 3
parse_csv_.L570:
	testq	%rdx, %rdx
	je	parse_csv_.L240
	vxorpd	%xmm2, %xmm2, %xmm2
	jmp	parse_csv_.L14
parse_csv_.L568:
	leaq	1(%rdi), %r10
	cmpb	$45, %cl
	sete	%bpl
	cmpq	%r10, %rbx
	je	parse_csv_.L47
	movzbl	1(%rdi), %ecx
	jmp	parse_csv_.L5
	.p2align 4,,10
	.p2align 3
parse_csv_.L290:
	movq	%rdx, %r10
parse_csv_.L16:
	cmpq	%r10, %rbx
	je	parse_csv_.L47
	movzbl	(%r10), %r12d
	movl	%r12d, %edx
	andl	$-33, %edx
	cmpb	$73, %dl
	jne	parse_csv_.L17
	movq	%r10, %r11
	movl	$parse_csv_.LC2, %ecx
	movl	$parse_csv_.LC3, %edx
parse_csv_.L29:
	addq	$1, %rdx
	movzbl	(%rdx), %r8d
	addq	$1, %rcx
	addq	$1, %r11
	testb	%r8b, %r8b
	je	parse_csv_.L25
	movzbl	(%rcx), %esi
	testb	%sil, %sil
	je	parse_csv_.L25
	cmpq	%r11, %rbx
	je	parse_csv_.L291
	movzbl	(%r11), %r9d
	cmpb	%r9b, %sil
	je	parse_csv_.L29
	cmpb	%r9b, %r8b
	je	parse_csv_.L29
	movq	%r10, %r8
	vxorpd	%xmm2, %xmm2, %xmm2
	cmpb	$46, %r12b
	jne	parse_csv_.L47
parse_csv_.L276:
	leaq	1(%r8), %rcx
	cmpq	%rcx, %rbx
	je	parse_csv_.L37
	movzbl	1(%r8), %edx
	leal	-48(%rdx), %esi
	cmpb	$9, %sil
	ja	parse_csv_.L38
	vmovsd	parse_csv_.LC12(%rip), %xmm0
	movsbl	%dl, %eax
	vxorpd	%xmm1, %xmm1, %xmm1
	subl	$48, %eax
	vcvtsi2sd	%eax, %xmm1, %xmm1
	leaq	2(%r8), %rax
	vfmadd132sd	%xmm0, %xmm1, %xmm2
	cmpq	%rax, %rbx
	je	parse_csv_.L39
	movsbl	2(%r8), %edx
	leal	-48(%rdx), %esi
	cmpb	$9, %sil
	ja	parse_csv_.L40
	vxorpd	%xmm1, %xmm1, %xmm1
	leaq	3(%r8), %rsi
	subl	$48, %edx
	vcvtsi2sd	%edx, %xmm1, %xmm1
	vfmadd132sd	%xmm0, %xmm1, %xmm2
	cmpq	%rsi, %rbx
	je	parse_csv_.L294
	movsbl	3(%r8), %edx
	leal	-48(%rdx), %r8d
	cmpb	$9, %r8b
	ja	parse_csv_.L574
	leaq	-2(%rbx), %rsi
	vmovapd	%xmm0, %xmm3
	leaq	-1(%rbx), %r8
	jmp	parse_csv_.L43
	.p2align 4,,10
	.p2align 3
parse_csv_.L575:
	movsbl	2(%rax), %edx
	leal	-48(%rdx), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L42
	subl	$48, %edx
	vxorpd	%xmm1, %xmm1, %xmm1
	addq	$3, %rax
	vcvtsi2sd	%edx, %xmm1, %xmm1
	vfmadd132sd	%xmm3, %xmm1, %xmm2
	cmpq	%rax, %rbx
	je	parse_csv_.L39
	movsbl	(%rax), %edx
	leal	-48(%rdx), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L40
	vxorpd	%xmm1, %xmm1, %xmm1
	leaq	1(%rax), %r12
	subl	$48, %edx
	vcvtsi2sd	%edx, %xmm1, %xmm1
	vfmadd132sd	%xmm3, %xmm1, %xmm2
	cmpq	%rax, %r8
	je	parse_csv_.L42
	movsbl	1(%rax), %edx
	leal	-48(%rdx), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L42
parse_csv_.L43:
	vxorpd	%xmm1, %xmm1, %xmm1
	leaq	2(%rax), %r12
	subl	$48, %edx
	vcvtsi2sd	%edx, %xmm1, %xmm1
	vfmadd132sd	%xmm0, %xmm1, %xmm2
	cmpq	%rsi, %rax
	jne	parse_csv_.L575
parse_csv_.L42:
	movl	%r12d, %esi
	subl	%ecx, %esi
	cmpq	%r12, %rbx
	je	parse_csv_.L45
parse_csv_.L277:
	movzbl	(%r12), %eax
	andl	$-33, %eax
	cmpb	$69, %al
	jne	parse_csv_.L45
	movq	%r12, %r8
	jmp	parse_csv_.L278
parse_csv_.L561:
	movsbl	%sil, %edx
	vxorpd	%xmm0, %xmm0, %xmm0
	subl	$48, %edx
	vcvtsi2sd	%edx, %xmm0, %xmm0
	leaq	2(%rax), %rdx
	vfmadd132sd	%xmm4, %xmm0, %xmm2
	cmpq	%rdx, %rbx
	je	parse_csv_.L161
	movsbl	2(%rax), %esi
	leal	-48(%rsi), %r8d
	cmpb	$9, %r8b
	ja	parse_csv_.L162
	subl	$48, %esi
	vxorpd	%xmm0, %xmm0, %xmm0
	vcvtsi2sd	%esi, %xmm0, %xmm0
	leaq	3(%rax), %rsi
	vfmadd132sd	%xmm4, %xmm0, %xmm2
	cmpq	%rsi, %rbx
	je	parse_csv_.L321
	movsbl	3(%rax), %eax
	leal	-48(%rax), %r8d
	cmpb	$9, %r8b
	ja	parse_csv_.L576
	leaq	-2(%rbx), %rsi
	leaq	-1(%rbx), %r8
	jmp	parse_csv_.L165
	.p2align 4,,10
	.p2align 3
parse_csv_.L577:
	movsbl	2(%rdx), %eax
	leal	-48(%rax), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L164
	subl	$48, %eax
	vxorpd	%xmm0, %xmm0, %xmm0
	addq	$3, %rdx
	vcvtsi2sd	%eax, %xmm0, %xmm0
	vfmadd132sd	%xmm4, %xmm0, %xmm2
	cmpq	%rdx, %rbx
	je	parse_csv_.L161
	movsbl	(%rdx), %eax
	leal	-48(%rax), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L162
	vxorpd	%xmm0, %xmm0, %xmm0
	leaq	1(%rdx), %r12
	subl	$48, %eax
	vcvtsi2sd	%eax, %xmm0, %xmm0
	vfmadd132sd	%xmm4, %xmm0, %xmm2
	cmpq	%r8, %rdx
	je	parse_csv_.L164
	movsbl	1(%rdx), %eax
	leal	-48(%rax), %r9d
	cmpb	$9, %r9b
	ja	parse_csv_.L164
parse_csv_.L165:
	vxorpd	%xmm0, %xmm0, %xmm0
	leaq	2(%rdx), %r12
	subl	$48, %eax
	vcvtsi2sd	%eax, %xmm0, %xmm0
	vfmadd132sd	%xmm4, %xmm0, %xmm2
	cmpq	%rdx, %rsi
	jne	parse_csv_.L577
parse_csv_.L164:
	movl	%r12d, %eax
	subl	%ecx, %eax
	movl	%eax, %ecx
	cmpq	%r12, %rbx
	je	parse_csv_.L167
parse_csv_.L279:
	movzbl	(%r12), %eax
	andl	$-33, %eax
	cmpb	$69, %al
	je	parse_csv_.L578
parse_csv_.L167:
	movq	%r12, %rdi
	testl	%ecx, %ecx
	je	parse_csv_.L256
	movl	%ecx, %eax
	vmovaps	%xmm5, 16(%rsp)
	negl	%eax
	testl	%eax, %eax
	jns	parse_csv_.L579
	cmpl	$-307, %eax
	jl	parse_csv_.L580
	vxorpd	%xmm1, %xmm1, %xmm1
	vcvtsi2sdq	%rcx, %xmm1, %xmm1
	vmovsd	%xmm2, (%rsp)
parse_csv_.L529:
	vmovapd	%xmm4, %xmm0
	vmovsd	%xmm4, 32(%rsp)
	call	pow
	vmovsd	(%rsp), %xmm2
	movq	%r12, %rdi
	vmovsd	32(%rsp), %xmm4
	vdivsd	%xmm0, %xmm2, %xmm2
	vmovapd	16(%rsp), %xmm5
	testb	%bpl, %bpl
	jne	parse_csv_.L581
parse_csv_.L234:
	vcvtsd2ss	%xmm2, %xmm2, %xmm2
	jmp	parse_csv_.L235
parse_csv_.L159:
	testb	%dl, %dl
	je	parse_csv_.L238
parse_csv_.L353:
	movq	%rbx, %rdi
	jmp	parse_csv_.L256
parse_csv_.L169:
	vmovsd	parse_csv_.LC7(%rip), %xmm0
	movq	%rax, %rdi
	vucomisd	%xmm0, %xmm2
	jp	parse_csv_.L206
	jne	parse_csv_.L206
parse_csv_.L281:
	movzbl	(%rdi), %eax
	andl	$-33, %eax
	cmpb	$78, %al
	jne	parse_csv_.L215
	movq	%rdi, %rax
	movl	$parse_csv_.LC0, %ecx
	movl	$parse_csv_.LC1, %edx
	.p2align 4,,10
	.p2align 3
parse_csv_.L219:
	addq	$1, %rdx
	movzbl	(%rdx), %esi
	addq	$1, %rcx
	addq	$1, %rax
	testb	%sil, %sil
	je	parse_csv_.L217
	movzbl	(%rcx), %r9d
	testb	%r9b, %r9b
	je	parse_csv_.L217
	cmpq	%rax, %rbx
	je	parse_csv_.L528
	movzbl	(%rax), %r8d
	cmpb	%r8b, %sil
	je	parse_csv_.L219
	cmpb	%r8b, %r9b
	je	parse_csv_.L219
parse_csv_.L215:
	movzbl	(%rdi), %eax
	andl	$-33, %eax
	cmpb	$73, %al
	jne	parse_csv_.L528
	movq	%rdi, %r9
	movl	$parse_csv_.LC2, %edx
	movl	$parse_csv_.LC3, %eax
parse_csv_.L227:
	addq	$1, %rax
	movzbl	(%rax), %esi
	addq	$1, %rdx
	addq	$1, %r9
	testb	%sil, %sil
	je	parse_csv_.L225
	movzbl	(%rdx), %ecx
	testb	%cl, %cl
	je	parse_csv_.L225
	cmpq	%r9, %rbx
	je	parse_csv_.L528
	movzbl	(%r9), %r8d
	cmpb	%r8b, %cl
	je	parse_csv_.L227
	cmpb	%r8b, %sil
	je	parse_csv_.L227
parse_csv_.L528:
	vmovapd	%xmm0, %xmm2
	jmp	parse_csv_.L206
parse_csv_.L573:
	andl	$-33, %edx
	cmpb	$69, %dl
	je	parse_csv_.L582
	movq	%r8, %rdi
	jmp	parse_csv_.L241
parse_csv_.L569:
	movq	%rbx, %rdi
	vxorpd	%xmm2, %xmm2, %xmm2
parse_csv_.L241:
	vucomisd	parse_csv_.LC7(%rip), %xmm2
	jp	parse_csv_.L83
	je	parse_csv_.L583
parse_csv_.L83:
	testb	%bpl, %bpl
	je	parse_csv_.L112
	vmovsd	parse_csv_.LC14(%rip), %xmm0
	vxorpd	%xmm0, %xmm2, %xmm2
	vcvtsd2ss	%xmm2, %xmm2, %xmm2
parse_csv_.L113:
	movq	40(%rsp), %rax
	leaq	4(%rax), %rdx
	vmovss	%xmm2, (%rax)
	movq	%rdx, 40(%rsp)
	jmp	parse_csv_.L255
parse_csv_.L578:
	movq	%r12, %rax
parse_csv_.L280:
	addq	$1, %rax
	jmp	parse_csv_.L168
parse_csv_.L38:
	testb	%al, %al
	je	parse_csv_.L47
	andl	$-33, %edx
	cmpb	$69, %dl
	jne	parse_csv_.L349
	movq	%rcx, %r8
	xorl	%esi, %esi
parse_csv_.L278:
	addq	$1, %r8
parse_csv_.L46:
	cmpq	%r8, %rbx
	je	parse_csv_.L47
	movzbl	(%r8), %edx
	leal	-43(%rdx), %ecx
	movsbl	%dl, %eax
	andl	$253, %ecx
	je	parse_csv_.L584
parse_csv_.L48:
	cmpb	$48, %al
	jne	parse_csv_.L67
	movq	%r8, %r12
	jmp	parse_csv_.L70
	.p2align 4,,10
	.p2align 3
parse_csv_.L498:
	movsbl	(%r12), %eax
	cmpb	$48, %al
	jne	parse_csv_.L69
parse_csv_.L70:
	addq	$1, %r12
	movq	%r12, %rdx
	subq	%r8, %rdx
	cmpq	%r12, %rbx
	jne	parse_csv_.L498
parse_csv_.L71:
	xorl	%eax, %eax
	testq	%rdx, %rdx
	je	parse_csv_.L47
parse_csv_.L66:
	subl	%esi, %eax
	jns	parse_csv_.L585
	cmpl	$-307, %eax
	jl	parse_csv_.L586
	vmovsd	%xmm2, 32(%rsp)
	negl	%eax
parse_csv_.L526:
	vmovsd	parse_csv_.LC12(%rip), %xmm0
	vxorpd	%xmm1, %xmm1, %xmm1
	vcvtsi2sd	%eax, %xmm1, %xmm1
	call	pow
	vmovsd	32(%rsp), %xmm2
	movq	%r12, %rdi
	vdivsd	%xmm0, %xmm2, %xmm2
	jmp	parse_csv_.L83
parse_csv_.L562:
	movq	%rcx, %rax
	xorl	%ecx, %ecx
	jmp	parse_csv_.L280
parse_csv_.L582:
	addq	$1, %r8
	xorl	%esi, %esi
	jmp	parse_csv_.L46
parse_csv_.L579:
	vxorpd	%xmm1, %xmm1, %xmm1
	vcvtsi2sd	%eax, %xmm1, %xmm1
	vmovapd	%xmm4, %xmm0
	vmovsd	%xmm2, (%rsp)
	vmovsd	%xmm4, 32(%rsp)
	call	pow
	vmovsd	(%rsp), %xmm2
	movq	%r12, %rdi
	vmovsd	32(%rsp), %xmm4
	vmulsd	%xmm0, %xmm2, %xmm2
	vmovapd	16(%rsp), %xmm5
	jmp	parse_csv_.L206
parse_csv_.L149:
	cmpq	%rax, %rbx
	je	parse_csv_.L238
	vxorpd	%xmm2, %xmm2, %xmm2
	jmp	parse_csv_.L587
parse_csv_.L112:
	vcvtsd2ss	%xmm2, %xmm2, %xmm2
	jmp	parse_csv_.L113
parse_csv_.L139:
	cmpq	%rax, %rbx
	je	parse_csv_.L221
	cmpb	$40, (%rax)
	je	parse_csv_.L588
parse_csv_.L221:
	vmovss	parse_csv_.LC8(%rip), %xmm0
	movq	%rax, %rdi
	vmovss	parse_csv_.LC9(%rip), %xmm2
parse_csv_.L267:
	testb	%bpl, %bpl
	jne	parse_csv_.L235
	vmovaps	%xmm0, %xmm2
	jmp	parse_csv_.L235
parse_csv_.L294:
	movq	%rbx, %rax
parse_csv_.L39:
	movl	%eax, %esi
	movq	%rax, %r12
	subl	%ecx, %esi
parse_csv_.L45:
	movq	%r12, %rdi
	testl	%esi, %esi
	je	parse_csv_.L241
	movl	%esi, %eax
	negl	%eax
	testl	%eax, %eax
	jns	parse_csv_.L589
	cmpl	$-307, %eax
	jl	parse_csv_.L590
	vxorpd	%xmm1, %xmm1, %xmm1
	vcvtsi2sdq	%rsi, %xmm1, %xmm1
	vmovsd	%xmm2, 32(%rsp)
	call	pow
	vmovsd	32(%rsp), %xmm2
	movq	%r12, %rdi
	vdivsd	%xmm0, %xmm2, %xmm2
	jmp	parse_csv_.L83
parse_csv_.L557:
	leaq	1(%rax), %r12
	cmpb	$45, %sil
	jne	parse_csv_.L171
	cmpq	%r12, %rbx
	je	parse_csv_.L238
	movsbl	1(%rax), %eax
	cmpb	$48, %al
	jne	parse_csv_.L173
	xorl	%edx, %edx
	jmp	parse_csv_.L176
	.p2align 4,,10
	.p2align 3
parse_csv_.L507:
	movsbl	(%r12), %eax
	cmpb	$48, %al
	jne	parse_csv_.L175
parse_csv_.L176:
	addq	$1, %r12
	addq	$1, %rdx
	cmpq	%r12, %rbx
	jne	parse_csv_.L507
parse_csv_.L539:
	testq	%rdx, %rdx
	jne	parse_csv_.L534
	jmp	parse_csv_.L238
parse_csv_.L175:
	leal	-48(%rax), %esi
	cmpb	$9, %sil
	ja	parse_csv_.L539
parse_csv_.L263:
	leaq	1(%r12), %rdx
	subl	$48, %eax
	negl	%eax
	cmpq	%rdx, %rbx
	je	parse_csv_.L324
	movsbl	1(%r12), %esi
	leal	-48(%rsi), %r8d
	cmpb	$9, %r8b
	ja	parse_csv_.L326
	leaq	-2(%rbx), %r10
	xorl	%r8d, %r8d
	leaq	-1(%rbx), %r9
	jmp	parse_csv_.L181
parse_csv_.L591:
	leal	(%rax,%rax,4), %eax
	subl	$48, %esi
	addl	%eax, %eax
	subl	%esi, %eax
parse_csv_.L183:
	leaq	1(%rdx), %r13
	cmpq	%rdx, %r9
	je	parse_csv_.L330
	movsbl	1(%rdx), %esi
	leal	-48(%rsi), %r11d
	cmpb	$9, %r11b
	ja	parse_csv_.L330
	movq	%rdx, %r11
	subq	%r12, %r11
	cmpq	$7, %r11
	ja	parse_csv_.L184
	leal	(%rax,%rax,4), %eax
	subl	$48, %esi
	addl	%eax, %eax
	subl	%esi, %eax
parse_csv_.L185:
	leaq	2(%rdx), %r13
	cmpq	%rdx, %r10
	je	parse_csv_.L330
	movsbl	2(%rdx), %esi
	leal	-48(%rsi), %r11d
	cmpb	$9, %r11b
	ja	parse_csv_.L330
	leaq	2(%r8), %r11
	cmpq	$7, %r11
	ja	parse_csv_.L186
	leal	(%rax,%rax,4), %eax
	subl	$48, %esi
	addl	%eax, %eax
	subl	%esi, %eax
parse_csv_.L187:
	addq	$3, %rdx
	addq	$3, %r8
	cmpq	%rdx, %rbx
	je	parse_csv_.L324
	movsbl	(%rdx), %esi
	leal	-48(%rsi), %r11d
	cmpb	$9, %r11b
	ja	parse_csv_.L326
parse_csv_.L181:
	cmpq	$7, %r8
	jbe	parse_csv_.L591
	cmpl	$-214748364, %eax
	jl	parse_csv_.L238
	leal	(%rax,%rax,4), %eax
	leal	-48(%rsi), %r11d
	addl	%eax, %eax
	addl	$2147483600, %esi
	cmpl	%esi, %eax
	jl	parse_csv_.L238
	subl	%r11d, %eax
	jmp	parse_csv_.L183
parse_csv_.L192:
	leal	-48(%rdx), %eax
	cmpb	$9, %al
	ja	parse_csv_.L541
parse_csv_.L264:
	leaq	1(%r12), %rsi
	subl	$48, %edx
	cmpq	%rsi, %rbx
	je	parse_csv_.L331
	movsbl	1(%r12), %eax
	leal	-48(%rax), %r8d
	cmpb	$9, %r8b
	ja	parse_csv_.L333
	leaq	-2(%rbx), %r10
	xorl	%r8d, %r8d
	movl	$2147483647, %r11d
	leaq	-1(%rbx), %r9
	jmp	parse_csv_.L198
parse_csv_.L592:
	leal	(%rdx,%rdx,4), %edx
	leal	-48(%rax,%rdx,2), %edx
parse_csv_.L200:
	leaq	1(%rsi), %r14
	cmpq	%rsi, %r9
	je	parse_csv_.L337
	movsbl	1(%rsi), %eax
	leal	-48(%rax), %r13d
	cmpb	$9, %r13b
	ja	parse_csv_.L337
	movq	%rsi, %r13
	subq	%r12, %r13
	cmpq	$7, %r13
	ja	parse_csv_.L201
	leal	(%rdx,%rdx,4), %edx
	leal	-48(%rax,%rdx,2), %edx
parse_csv_.L202:
	leaq	2(%rsi), %r14
	cmpq	%rsi, %r10
	je	parse_csv_.L337
	movsbl	2(%rsi), %eax
	leal	-48(%rax), %r13d
	cmpb	$9, %r13b
	ja	parse_csv_.L337
	leaq	2(%r8), %r13
	cmpq	$7, %r13
	ja	parse_csv_.L203
	leal	(%rdx,%rdx,4), %edx
	leal	-48(%rax,%rdx,2), %edx
parse_csv_.L204:
	addq	$3, %rsi
	addq	$3, %r8
	cmpq	%rsi, %rbx
	je	parse_csv_.L331
	movsbl	(%rsi), %eax
	leal	-48(%rax), %r13d
	cmpb	$9, %r13b
	ja	parse_csv_.L333
parse_csv_.L198:
	cmpq	$7, %r8
	jbe	parse_csv_.L592
	cmpl	$214748364, %edx
	jg	parse_csv_.L238
	leal	(%rdx,%rdx,4), %edx
	movsbl	%al, %r13d
	leal	-48(%r13), %eax
	movl	%r11d, %r13d
	addl	%edx, %edx
	subl	%eax, %r13d
	cmpl	%r13d, %edx
	jg	parse_csv_.L238
	addl	%eax, %edx
	jmp	parse_csv_.L200
parse_csv_.L37:
	testb	%al, %al
	je	parse_csv_.L47
parse_csv_.L352:
	movq	%rbx, %rdi
	jmp	parse_csv_.L241
parse_csv_.L563:
	cmpq	%rdi, %rbx
	jne	parse_csv_.L281
	jmp	parse_csv_.L206
parse_csv_.L311:
	movq	%rbx, %rax
	jmp	parse_csv_.L132
parse_csv_.L186:
	cmpl	$-214748364, %eax
	jl	parse_csv_.L238
	leal	(%rax,%rax,4), %eax
	leal	(%rax,%rax), %r11d
	movsbl	%sil, %eax
	leal	-48(%rax), %esi
	addl	$2147483600, %eax
	cmpl	%eax, %r11d
	jl	parse_csv_.L238
	movl	%r11d, %eax
	subl	%esi, %eax
	jmp	parse_csv_.L187
parse_csv_.L184:
	cmpl	$-214748364, %eax
	jl	parse_csv_.L238
	leal	(%rax,%rax,4), %eax
	leal	(%rax,%rax), %r11d
	movsbl	%sil, %eax
	leal	-48(%rax), %esi
	addl	$2147483600, %eax
	cmpl	%eax, %r11d
	jl	parse_csv_.L238
	movl	%r11d, %eax
	subl	%esi, %eax
	jmp	parse_csv_.L185
parse_csv_.L15:
	cmpq	%rdx, %rbx
	je	parse_csv_.L21
	cmpb	$40, (%rdx)
	je	parse_csv_.L593
parse_csv_.L21:
	vmovss	parse_csv_.LC8(%rip), %xmm0
	movq	%rdx, %rdi
	vmovss	parse_csv_.LC9(%rip), %xmm2
parse_csv_.L254:
	testb	%bpl, %bpl
	jne	parse_csv_.L113
	vmovaps	%xmm0, %xmm2
	jmp	parse_csv_.L113
parse_csv_.L313:
	movq	%rdx, %rax
	jmp	parse_csv_.L132
parse_csv_.L203:
	cmpl	$214748364, %edx
	jg	parse_csv_.L238
	leal	(%rdx,%rdx,4), %edx
	subl	$48, %eax
	movl	%r11d, %r13d
	addl	%edx, %edx
	subl	%eax, %r13d
	cmpl	%r13d, %edx
	jg	parse_csv_.L238
	addl	%eax, %edx
	jmp	parse_csv_.L204
parse_csv_.L201:
	cmpl	$214748364, %edx
	jg	parse_csv_.L238
	leal	(%rdx,%rdx,4), %edx
	subl	$48, %eax
	movl	%r11d, %r13d
	addl	%edx, %edx
	subl	%eax, %r13d
	cmpl	%r13d, %edx
	jg	parse_csv_.L238
	addl	%eax, %edx
	jmp	parse_csv_.L202
parse_csv_.L583:
	cmpq	%rdi, %rbx
	je	parse_csv_.L83
	movzbl	(%rdi), %eax
	andl	$-33, %eax
	cmpb	$78, %al
	jne	parse_csv_.L93
	movq	%rdi, %rax
	movl	$parse_csv_.LC0, %ecx
	movl	$parse_csv_.LC1, %edx
parse_csv_.L97:
	addq	$1, %rdx
	movzbl	(%rdx), %esi
	addq	$1, %rcx
	addq	$1, %rax
	testb	%sil, %sil
	je	parse_csv_.L95
	movzbl	(%rcx), %r9d
	testb	%r9b, %r9b
	je	parse_csv_.L95
	cmpq	%rax, %rbx
	je	parse_csv_.L93
	movzbl	(%rax), %r8d
	cmpb	%r8b, %sil
	je	parse_csv_.L97
	cmpb	%r8b, %r9b
	je	parse_csv_.L97
	jmp	parse_csv_.L83
parse_csv_.L576:
	movq	%rsi, %rdx
parse_csv_.L162:
	movl	%edx, %eax
	movq	%rdx, %r12
	subl	%ecx, %eax
	movl	%eax, %ecx
	jmp	parse_csv_.L279
parse_csv_.L584:
	leaq	1(%r8), %r12
	cmpb	$45, %dl
	jne	parse_csv_.L49
	cmpq	%r12, %rbx
	je	parse_csv_.L47
	movsbl	1(%r8), %eax
	cmpb	$48, %al
	jne	parse_csv_.L50
	xorl	%edx, %edx
	jmp	parse_csv_.L53
	.p2align 4,,10
	.p2align 3
parse_csv_.L496:
	movsbl	(%r12), %eax
	cmpb	$48, %al
	jne	parse_csv_.L52
parse_csv_.L53:
	addq	$1, %r12
	addq	$1, %rdx
	cmpq	%r12, %rbx
	jne	parse_csv_.L496
	jmp	parse_csv_.L71
parse_csv_.L349:
	movq	%rcx, %rdi
	jmp	parse_csv_.L241
parse_csv_.L321:
	movq	%rbx, %rdx
parse_csv_.L161:
	movl	%edx, %eax
	movq	%rdx, %r12
	subl	%ecx, %eax
	movl	%eax, %ecx
	jmp	parse_csv_.L167
parse_csv_.L52:
	leal	-48(%rax), %ecx
	cmpb	$9, %cl
	ja	parse_csv_.L71
parse_csv_.L249:
	leaq	1(%r12), %rcx
	subl	$48, %eax
	negl	%eax
	cmpq	%rcx, %rbx
	je	parse_csv_.L73
	movsbl	1(%r12), %edx
	leal	-48(%rdx), %r8d
	cmpb	$9, %r8b
	ja	parse_csv_.L73
	leaq	-2(%rbx), %r10
	xorl	%r8d, %r8d
	leaq	-1(%rbx), %r9
	jmp	parse_csv_.L58
parse_csv_.L594:
	leal	(%rax,%rax,4), %eax
	subl	$48, %edx
	addl	%eax, %eax
	subl	%edx, %eax
parse_csv_.L60:
	leaq	1(%rcx), %r11
	cmpq	%r9, %rcx
	je	parse_csv_.L300
	movsbl	1(%rcx), %edx
	leal	-48(%rdx), %r13d
	cmpb	$9, %r13b
	ja	parse_csv_.L300
	movq	%rcx, %r11
	subq	%r12, %r11
	cmpq	$7, %r11
	ja	parse_csv_.L61
	leal	(%rax,%rax,4), %eax
	subl	$48, %edx
	addl	%eax, %eax
	subl	%edx, %eax
parse_csv_.L62:
	leaq	2(%rcx), %r11
	cmpq	%r10, %rcx
	je	parse_csv_.L300
	movsbl	2(%rcx), %edx
	leal	-48(%rdx), %r13d
	cmpb	$9, %r13b
	ja	parse_csv_.L300
	leaq	2(%r8), %r11
	cmpq	$7, %r11
	ja	parse_csv_.L63
	leal	(%rax,%rax,4), %eax
	subl	$48, %edx
	addl	%eax, %eax
	subl	%edx, %eax
parse_csv_.L64:
	addq	$3, %rcx
	addq	$3, %r8
	cmpq	%rcx, %rbx
	je	parse_csv_.L73
	movsbl	(%rcx), %edx
	leal	-48(%rdx), %r11d
	cmpb	$9, %r11b
	ja	parse_csv_.L73
parse_csv_.L58:
	cmpq	$7, %r8
	jbe	parse_csv_.L594
	cmpl	$-214748364, %eax
	jl	parse_csv_.L47
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx), %r11d
	addl	%eax, %eax
	addl	$2147483600, %edx
	cmpl	%edx, %eax
	jl	parse_csv_.L47
	subl	%r11d, %eax
	jmp	parse_csv_.L60
parse_csv_.L287:
	movq	%rbx, %r8
	jmp	parse_csv_.L14
parse_csv_.L69:
	leal	-48(%rax), %ecx
	cmpb	$9, %cl
	ja	parse_csv_.L250
parse_csv_.L251:
	leaq	1(%r12), %rcx
	subl	$48, %eax
	cmpq	%rcx, %rbx
	je	parse_csv_.L73
	movsbl	1(%r12), %edx
	leal	-48(%rdx), %r8d
	cmpb	$9, %r8b
	ja	parse_csv_.L73
	leaq	-2(%rbx), %r11
	xorl	%r8d, %r8d
	movl	$2147483647, %r9d
	leaq	-1(%rbx), %r10
	jmp	parse_csv_.L75
parse_csv_.L595:
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx,%rax,2), %eax
parse_csv_.L77:
	leaq	1(%rcx), %r13
	cmpq	%rcx, %r10
	je	parse_csv_.L304
	movsbl	1(%rcx), %edx
	leal	-48(%rdx), %r14d
	cmpb	$9, %r14b
	ja	parse_csv_.L304
	movq	%rcx, %r13
	subq	%r12, %r13
	cmpq	$7, %r13
	ja	parse_csv_.L78
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx,%rax,2), %eax
parse_csv_.L79:
	leaq	2(%rcx), %r13
	cmpq	%r11, %rcx
	je	parse_csv_.L304
	movsbl	2(%rcx), %edx
	leal	-48(%rdx), %r14d
	cmpb	$9, %r14b
	ja	parse_csv_.L304
	leaq	2(%r8), %r13
	cmpq	$7, %r13
	ja	parse_csv_.L80
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx,%rax,2), %eax
parse_csv_.L81:
	addq	$3, %rcx
	addq	$3, %r8
	cmpq	%rcx, %rbx
	je	parse_csv_.L73
	movsbl	(%rcx), %edx
	leal	-48(%rdx), %r13d
	cmpb	$9, %r13b
	ja	parse_csv_.L73
parse_csv_.L75:
	cmpq	$7, %r8
	jbe	parse_csv_.L595
	cmpl	$214748364, %eax
	jg	parse_csv_.L47
	leal	(%rax,%rax,4), %eax
	leal	(%rax,%rax), %r13d
	leal	-48(%rdx), %eax
	movl	%r9d, %edx
	subl	%eax, %edx
	cmpl	%edx, %r13d
	jg	parse_csv_.L47
	addl	%r13d, %eax
	jmp	parse_csv_.L77
parse_csv_.L580:
	leal	-307(%rcx), %eax
	vxorpd	%xmm1, %xmm1, %xmm1
	vdivsd	parse_csv_.LC13(%rip), %xmm2, %xmm2
	vmovsd	%xmm2, (%rsp)
	vcvtsi2sdq	%rax, %xmm1, %xmm1
	jmp	parse_csv_.L529
parse_csv_.L558:
	vxorpd	%xmm1, %xmm1, %xmm1
	vcvtsi2sd	%eax, %xmm1, %xmm1
	vmovaps	%xmm5, (%rsp)
	vmovsd	parse_csv_.LC12(%rip), %xmm0
	vmovsd	%xmm4, 16(%rsp)
	vmovsd	%xmm2, 32(%rsp)
	call	pow
	vmovsd	32(%rsp), %xmm2
	movq	%r12, %rdi
	vmovapd	(%rsp), %xmm5
	vmulsd	%xmm0, %xmm2, %xmm2
	vmovsd	16(%rsp), %xmm4
	jmp	parse_csv_.L206
parse_csv_.L148:
	cmpq	%r11, %rbx
	je	parse_csv_.L153
	movzbl	(%r11), %eax
	andl	$-33, %eax
	cmpb	$73, %al
	jne	parse_csv_.L153
	movq	%r11, %rax
	movl	$parse_csv_.LC4, %ecx
	movl	$parse_csv_.LC5, %edx
parse_csv_.L156:
	addq	$1, %rdx
	movzbl	(%rdx), %edi
	addq	$1, %rcx
	addq	$1, %rax
	testb	%dil, %dil
	je	parse_csv_.L320
	movzbl	(%rcx), %esi
	testb	%sil, %sil
	je	parse_csv_.L320
	cmpq	%rax, %rbx
	je	parse_csv_.L153
	movzbl	(%rax), %r8d
	cmpb	%r8b, %sil
	je	parse_csv_.L156
	cmpb	%r8b, %dil
	je	parse_csv_.L156
parse_csv_.L153:
	vmovss	parse_csv_.LC10(%rip), %xmm0
	movq	%r11, %rdi
	vmovss	parse_csv_.LC11(%rip), %xmm2
	jmp	parse_csv_.L267
parse_csv_.L217:
	cmpq	%rax, %rbx
	je	parse_csv_.L221
	cmpb	$40, (%rax)
	jne	parse_csv_.L221
	movq	%rax, %rdx
parse_csv_.L223:
	addq	$1, %rdx
	cmpq	%rdx, %rbx
	je	parse_csv_.L222
	cmpb	$41, (%rdx)
	jne	parse_csv_.L223
	leaq	1(%rdx), %rax
	jmp	parse_csv_.L221
parse_csv_.L289:
	movq	%rdx, %r8
	jmp	parse_csv_.L14
parse_csv_.L589:
	vxorpd	%xmm1, %xmm1, %xmm1
	vcvtsi2sd	%eax, %xmm1, %xmm1
	vmovsd	%xmm2, 32(%rsp)
	call	pow
	vmovsd	32(%rsp), %xmm2
	movq	%r12, %rdi
	vmulsd	%xmm0, %xmm2, %xmm2
	jmp	parse_csv_.L83
parse_csv_.L559:
	vdivsd	parse_csv_.LC13(%rip), %xmm2, %xmm2
	movl	$-307, %edx
	vmovsd	%xmm2, 32(%rsp)
	subl	%eax, %edx
	movl	%edx, %eax
	jmp	parse_csv_.L530
parse_csv_.L250:
	xorl	%eax, %eax
	testq	%rdx, %rdx
	jne	parse_csv_.L66
	jmp	parse_csv_.L47
parse_csv_.L590:
	leal	-307(%rsi), %eax
	vxorpd	%xmm1, %xmm1, %xmm1
	vdivsd	parse_csv_.LC13(%rip), %xmm2, %xmm2
	vmovsd	%xmm2, 32(%rsp)
	vcvtsi2sdq	%rax, %xmm1, %xmm1
	call	pow
	vmovsd	32(%rsp), %xmm2
	movq	%r12, %rdi
	vdivsd	%xmm0, %xmm2, %xmm2
	jmp	parse_csv_.L83
parse_csv_.L100:
	cmpq	%rax, %rbx
	je	parse_csv_.L305
	movq	%rax, %rdi
parse_csv_.L93:
	movzbl	(%rdi), %eax
	andl	$-33, %eax
	cmpb	$73, %al
	jne	parse_csv_.L83
	movq	%rdi, %rdx
	movl	$parse_csv_.LC2, %ecx
	movl	$parse_csv_.LC3, %eax
parse_csv_.L105:
	addq	$1, %rax
	movzbl	(%rax), %esi
	addq	$1, %rcx
	addq	$1, %rdx
	testb	%sil, %sil
	je	parse_csv_.L103
	movzbl	(%rcx), %r9d
	testb	%r9b, %r9b
	je	parse_csv_.L103
	cmpq	%rdx, %rbx
	je	parse_csv_.L83
	movzbl	(%rdx), %r8d
	cmpb	%r8b, %r9b
	je	parse_csv_.L105
	cmpb	%r8b, %sil
	je	parse_csv_.L105
	jmp	parse_csv_.L83
	.p2align 4,,10
	.p2align 3
parse_csv_.L560:
	movq	%r11, %rax
	movl	%ecx, %esi
	jmp	parse_csv_.L129
parse_csv_.L586:
	vdivsd	parse_csv_.LC13(%rip), %xmm2, %xmm2
	movl	$-307, %edx
	vmovsd	%xmm2, 32(%rsp)
	subl	%eax, %edx
	movl	%edx, %eax
	jmp	parse_csv_.L526
parse_csv_.L566:
	movq	%rsi, %rax
	jmp	parse_csv_.L132
parse_csv_.L190:
	leal	-48(%rdx), %esi
	movq	%rax, %r12
	cmpb	$9, %sil
	jbe	parse_csv_.L264
	jmp	parse_csv_.L238
parse_csv_.L300:
	movq	%r11, %rcx
parse_csv_.L73:
	movq	%rcx, %r12
	jmp	parse_csv_.L66
parse_csv_.L80:
	cmpl	$214748364, %eax
	jg	parse_csv_.L47
	leal	(%rax,%rax,4), %r13d
	leal	-48(%rdx), %eax
	movl	%r9d, %edx
	addl	%r13d, %r13d
	subl	%eax, %edx
	cmpl	%edx, %r13d
	jg	parse_csv_.L47
	addl	%r13d, %eax
	jmp	parse_csv_.L81
parse_csv_.L63:
	cmpl	$-214748364, %eax
	jl	parse_csv_.L47
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx), %r11d
	addl	%eax, %eax
	addl	$2147483600, %edx
	cmpl	%edx, %eax
	jl	parse_csv_.L47
	subl	%r11d, %eax
	jmp	parse_csv_.L64
parse_csv_.L78:
	cmpl	$214748364, %eax
	jg	parse_csv_.L47
	leal	(%rax,%rax,4), %r13d
	leal	-48(%rdx), %eax
	movl	%r9d, %edx
	addl	%r13d, %r13d
	subl	%eax, %edx
	cmpl	%edx, %r13d
	jg	parse_csv_.L47
	addl	%r13d, %eax
	jmp	parse_csv_.L79
parse_csv_.L61:
	cmpl	$-214748364, %eax
	jl	parse_csv_.L47
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx), %r11d
	addl	%eax, %eax
	addl	$2147483600, %edx
	cmpl	%edx, %eax
	jl	parse_csv_.L47
	subl	%r11d, %eax
	jmp	parse_csv_.L62
parse_csv_.L588:
	movq	%rax, %rcx
parse_csv_.L145:
	addq	$1, %rcx
	cmpq	%rcx, %rbx
	je	parse_csv_.L144
	cmpb	$41, (%rcx)
	jne	parse_csv_.L145
	leaq	1(%rcx), %rax
	jmp	parse_csv_.L221
parse_csv_.L95:
	cmpq	%rax, %rbx
	je	parse_csv_.L99
	cmpb	$40, (%rax)
	je	parse_csv_.L596
parse_csv_.L99:
	vmovss	parse_csv_.LC8(%rip), %xmm0
	movq	%rax, %rdi
	vmovss	parse_csv_.LC9(%rip), %xmm2
	jmp	parse_csv_.L254
parse_csv_.L337:
	movq	%r14, %r12
	movl	%edx, %eax
	jmp	parse_csv_.L189
parse_csv_.L330:
	movq	%r13, %r12
	jmp	parse_csv_.L189
parse_csv_.L320:
	movq	%rax, %r11
	jmp	parse_csv_.L153
parse_csv_.L574:
	movq	%rsi, %rax
parse_csv_.L40:
	movl	%eax, %esi
	movq	%rax, %r12
	subl	%ecx, %esi
	jmp	parse_csv_.L277
parse_csv_.L585:
	vxorpd	%xmm1, %xmm1, %xmm1
	vcvtsi2sd	%eax, %xmm1, %xmm1
	vmovsd	%xmm2, 32(%rsp)
	vmovsd	parse_csv_.LC12(%rip), %xmm0
	call	pow
	vmovsd	32(%rsp), %xmm2
	movq	%r12, %rdi
	vmulsd	%xmm0, %xmm2, %xmm2
	jmp	parse_csv_.L83
parse_csv_.L593:
	movq	%rdx, %rcx
parse_csv_.L23:
	addq	$1, %rcx
	cmpq	%rcx, %rbx
	je	parse_csv_.L290
	cmpb	$41, (%rcx)
	jne	parse_csv_.L23
	leaq	1(%rcx), %rdx
	jmp	parse_csv_.L21
parse_csv_.L25:
	cmpq	%r11, %rbx
	je	parse_csv_.L31
	movzbl	(%r11), %eax
	andl	$-33, %eax
	cmpb	$73, %al
	jne	parse_csv_.L31
	movq	%r11, %rax
	movl	$parse_csv_.LC4, %ecx
	movl	$parse_csv_.LC5, %edx
parse_csv_.L34:
	addq	$1, %rdx
	movzbl	(%rdx), %edi
	addq	$1, %rcx
	addq	$1, %rax
	testb	%dil, %dil
	je	parse_csv_.L293
	movzbl	(%rcx), %esi
	testb	%sil, %sil
	je	parse_csv_.L293
	cmpq	%rax, %rbx
	je	parse_csv_.L31
	movzbl	(%rax), %r8d
	cmpb	%r8b, %sil
	je	parse_csv_.L34
	cmpb	%r8b, %dil
	je	parse_csv_.L34
parse_csv_.L31:
	vmovss	parse_csv_.LC10(%rip), %xmm0
	movq	%r11, %rdi
	vmovss	parse_csv_.LC11(%rip), %xmm2
	jmp	parse_csv_.L254
parse_csv_.L293:
	movq	%rax, %r11
	jmp	parse_csv_.L31
parse_csv_.L225:
	cmpq	%r9, %rbx
	je	parse_csv_.L229
	movzbl	(%r9), %eax
	andl	$-33, %eax
	cmpb	$73, %al
	jne	parse_csv_.L229
	movq	%r9, %rax
	movl	$parse_csv_.LC4, %ecx
	movl	$parse_csv_.LC5, %edx
parse_csv_.L232:
	addq	$1, %rdx
	movzbl	(%rdx), %edi
	addq	$1, %rcx
	addq	$1, %rax
	testb	%dil, %dil
	je	parse_csv_.L343
	movzbl	(%rcx), %esi
	testb	%sil, %sil
	je	parse_csv_.L343
	cmpq	%rax, %rbx
	je	parse_csv_.L229
	movzbl	(%rax), %r8d
	cmpb	%r8b, %sil
	je	parse_csv_.L232
	cmpb	%r8b, %dil
	je	parse_csv_.L232
parse_csv_.L229:
	vmovss	parse_csv_.LC10(%rip), %xmm0
	movq	%r9, %rdi
	vmovss	parse_csv_.LC11(%rip), %xmm2
	jmp	parse_csv_.L267
parse_csv_.L343:
	movq	%rax, %r9
	jmp	parse_csv_.L229
parse_csv_.L103:
	cmpq	%rdx, %rbx
	je	parse_csv_.L107
	movzbl	(%rdx), %eax
	andl	$-33, %eax
	cmpb	$73, %al
	jne	parse_csv_.L107
	movq	%rdx, %rax
	movl	$parse_csv_.LC4, %esi
	movl	$parse_csv_.LC5, %ecx
parse_csv_.L110:
	addq	$1, %rcx
	movzbl	(%rcx), %edi
	addq	$1, %rsi
	addq	$1, %rax
	testb	%dil, %dil
	je	parse_csv_.L307
	movzbl	(%rsi), %r9d
	testb	%r9b, %r9b
	je	parse_csv_.L307
	cmpq	%rax, %rbx
	je	parse_csv_.L107
	movzbl	(%rax), %r8d
	cmpb	%r8b, %dil
	je	parse_csv_.L110
	cmpb	%r8b, %r9b
	je	parse_csv_.L110
parse_csv_.L107:
	vmovss	parse_csv_.LC10(%rip), %xmm0
	movq	%rdx, %rdi
	vmovss	parse_csv_.LC11(%rip), %xmm2
	jmp	parse_csv_.L254
parse_csv_.L333:
	movq	%rsi, %r12
	movl	%edx, %eax
	jmp	parse_csv_.L189
parse_csv_.L331:
	movq	%rbx, %r12
	movl	%edx, %eax
	jmp	parse_csv_.L189
parse_csv_.L596:
	movq	%rax, %rdx
parse_csv_.L101:
	addq	$1, %rdx
	cmpq	%rdx, %rbx
	je	parse_csv_.L100
	cmpb	$41, (%rdx)
	jne	parse_csv_.L101
	leaq	1(%rdx), %rax
	jmp	parse_csv_.L99
parse_csv_.L571:
	movq	%rcx, %r8
	jmp	parse_csv_.L14
parse_csv_.L326:
	movq	%rdx, %r12
	jmp	parse_csv_.L189
parse_csv_.L324:
	movq	%rbx, %r12
	jmp	parse_csv_.L189
parse_csv_.L173:
	leal	-48(%rax), %edx
	cmpb	$9, %dl
	jbe	parse_csv_.L263
	jmp	parse_csv_.L238
parse_csv_.L307:
	movq	%rax, %rdx
	jmp	parse_csv_.L107
parse_csv_.L222:
	cmpq	%rax, %rbx
	je	parse_csv_.L347
	movq	%rax, %rdi
	jmp	parse_csv_.L215
parse_csv_.L67:
	leal	-48(%rax), %edx
	movq	%r8, %r12
	cmpb	$9, %dl
	jbe	parse_csv_.L251
	jmp	parse_csv_.L47
parse_csv_.L171:
	cmpq	%r12, %rbx
	je	parse_csv_.L238
	movsbl	1(%rax), %edx
	movq	%r12, %rax
	jmp	parse_csv_.L170
parse_csv_.L347:
	movq	%rbx, %rdi
	jmp	parse_csv_.L528
parse_csv_.L305:
	movq	%rbx, %rdi
	jmp	parse_csv_.L83
parse_csv_.L304:
	movq	%r13, %rcx
	jmp	parse_csv_.L73
parse_csv_.L50:
	leal	-48(%rax), %edx
	cmpb	$9, %dl
	jbe	parse_csv_.L249
	jmp	parse_csv_.L47
parse_csv_.L49:
	cmpq	%r12, %rbx
	je	parse_csv_.L47
	movsbl	1(%r8), %eax
	movq	%r12, %r8
	jmp	parse_csv_.L48
parse_csv_.L144:
	cmpq	%rax, %rbx
	je	parse_csv_.L238
	jmp	parse_csv_.L137
parse_csv_.L565:
	call	__stack_chk_fail
	.cfi_endproc
parse_csv_.LFE13901:
	.size	_Z9parse_csvPKcmPf, .-_Z9parse_csvPKcmPf
	.section	.text.unlikely
parse_csv_.LCOLDE15:
	.text
parse_csv_.LHOTE15:
	.section	.text.unlikely
parse_csv_.LCOLDB16:
	.text
parse_csv_.LHOTB16:
	.p2align 4,,15
	.globl	_Z3foov
	.type	_Z3foov, @function
_Z3foov:
parse_csv_.LFB13904:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
parse_csv_.LFE13904:
	.size	_Z3foov, .-_Z3foov
	.section	.text.unlikely
parse_csv_.LCOLDE16:
	.text
parse_csv_.LHOTE16:
	.section	.text.unlikely
parse_csv_.LCOLDB17:
	.section	.text.startup,"ax",@progbits
parse_csv_.LHOTB17:
	.p2align 4,,15
	.type	_GLOBAL__sub_I__Z9parse_csvPKcmPf, @function
_GLOBAL__sub_I__Z9parse_csvPKcmPf:
parse_csv_.LFB15505:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
parse_csv_.LFE15505:
	.size	_GLOBAL__sub_I__Z9parse_csvPKcmPf, .-_GLOBAL__sub_I__Z9parse_csvPKcmPf
	.section	.text.unlikely
parse_csv_.LCOLDE17:
	.section	.text.startup
parse_csv_.LHOTE17:
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z9parse_csvPKcmPf
#	.local	_ZStL8__ioinit
#	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
parse_csv_.LC6:
	.long	0
	.long	0
	.align 8
parse_csv_.LC7:
	.long	0
	.long	1072693248
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
parse_csv_.LC8:
	.long	2143289344
	.align 4
parse_csv_.LC9:
	.long	4290772992
	.align 4
parse_csv_.LC10:
	.long	2139095040
	.align 4
parse_csv_.LC11:
	.long	4286578688
	.section	.rodata.cst8
	.align 8
parse_csv_.LC12:
	.long	0
	.long	1076101120
	.align 8
parse_csv_.LC13:
	.long	1017934899
	.long	2142010143
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
parse_csv_.LC14:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
	.hidden	__dso_handle
)");

#endif /* SRC_PARSE_CSV_HPP_ */
