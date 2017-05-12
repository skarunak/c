	.file	"va_arg.c"
	.text
	.globl	average
	.type	average, @function
average:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$240, %rsp
	movl	%edi, -228(%rbp)
	movq	%rsi, -168(%rbp)
	movq	%rdx, -160(%rbp)
	movq	%rcx, -152(%rbp)
	movq	%r8, -144(%rbp)
	movq	%r9, -136(%rbp)
	testb	%al, %al
	je	.L2
	movaps	%xmm0, -128(%rbp)
	movaps	%xmm1, -112(%rbp)
	movaps	%xmm2, -96(%rbp)
	movaps	%xmm3, -80(%rbp)
	movaps	%xmm4, -64(%rbp)
	movaps	%xmm5, -48(%rbp)
	movaps	%xmm6, -32(%rbp)
	movaps	%xmm7, -16(%rbp)
.L2:
	movq	%fs:40, %rax
	movq	%rax, -184(%rbp)
	xorl	%eax, %eax
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -216(%rbp)
	movl	$0, -220(%rbp)
	movl	$8, -208(%rbp)
	movl	$48, -204(%rbp)
	leaq	16(%rbp), %rax
	movq	%rax, -200(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, -192(%rbp)
	movl	$0, -220(%rbp)
	jmp	.L3
.L6:
	movl	-204(%rbp), %eax
	cmpl	$176, %eax
	jnb	.L4
	movq	-192(%rbp), %rax
	movl	-204(%rbp), %edx
	movl	%edx, %edx
	addq	%rdx, %rax
	movl	-204(%rbp), %edx
	addl	$16, %edx
	movl	%edx, -204(%rbp)
	jmp	.L5
.L4:
	movq	-200(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	%rdx, -200(%rbp)
.L5:
	movsd	(%rax), %xmm0
	movsd	-216(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -216(%rbp)
	addl	$1, -220(%rbp)
.L3:
	movl	-220(%rbp), %eax
	cmpl	-228(%rbp), %eax
	jl	.L6
	pxor	%xmm0, %xmm0
	cvtsi2sd	-228(%rbp), %xmm0
	movsd	-216(%rbp), %xmm1
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movq	-184(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L8
	call	__stack_chk_fail
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	average, .-average
	.section	.rodata
.LC1:
	.string	"Senthilkumar Karunakaran"
.LC5:
	.string	"%f\n"
.LC6:
	.string	"%d %d %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	$.LC1, -8(%rbp)
	movsd	.LC2(%rip), %xmm1
	movsd	.LC3(%rip), %xmm0
	movabsq	$4623057607486498406, %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movl	$3, %edi
	movl	$3, %eax
	call	average
	movl	$.LC5, %edi
	movl	$1, %eax
	call	printf
	movl	$300, %ecx
	movl	$200, %edx
	movl	$100, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	0
	.long	1074921472
	.align 8
.LC3:
	.long	3435973837
	.long	1077300428
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
