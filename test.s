	.file	"test.c"
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	subl	$16, %esp
	.cfi_def_cfa_offset 20
	movl	$0, 12(%esp)
	movl	20(%esp), %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movl	%eax, 12(%esp)
	movl	12(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.globl	abc
	.type	abc, @function
abc:
.LFB1:
	.cfi_startproc
	subl	$16, %esp
	.cfi_def_cfa_offset 20
	movl	$0, 12(%esp)
	movl	20(%esp), %eax
	addl	%eax, %eax
	movl	%eax, 12(%esp)
	movl	12(%esp), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE1:
	.size	abc, .-abc
	.section	.rodata
.LC0:
	.string	"%d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$20, %esp
	movl	$10, -16(%ebp)
	movl	$20, -12(%ebp)
	pushl	-12(%ebp)
	pushl	-16(%ebp)
	call	foo
	addl	$8, %esp
	addl	$1, -16(%ebp)
	subl	$8, %esp
	pushl	-16(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
