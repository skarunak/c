	.file	"var.c"
	.comm	g_i,4,4
	.comm	g_j,4,4
	.comm	g_k,4,4
	.section	.rodata
.LC0:
	.string	"Senthilkumar Karunakaran"
.LC1:
	.string	"%d %d %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$848, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$.LC0, -824(%rbp)
	movl	$1752461889, -16(%rbp)
	movw	$105, -12(%rbp)
	movl	$100, -836(%rbp)
	movl	$200, -832(%rbp)
	movl	$300, -828(%rbp)
	movl	-828(%rbp), %ecx
	movl	-832(%rbp), %edx
	movl	-836(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$600, %ecx
	movl	$500, %edx
	movl	$400, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
