	.file	"hello.c"
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Hello, World!\0"
.LC1:
	.ascii "%d\0"
	.section	.text.unlikely,"x"
.LCOLDB2:
	.section	.text.startup,"x"
.LHOTB2:
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rcx
	call	printf
	leaq	.LC1(%rip), %rcx
	movl	$6, %edx
	call	printf
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.section	.text.unlikely,"x"
.LCOLDE2:
	.section	.text.startup,"x"
.LHOTE2:
	.ident	"GCC: (GNU) 5.3.0"
	.def	printf;	.scl	2;	.type	32;	.endef
