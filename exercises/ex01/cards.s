	.file	"cards.c"
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Enter the card_name: \0"
.LC1:
	.ascii "%2s\0"
	.align 8
.LC2:
	.ascii "I don't understand that value!\0"
.LC3:
	.ascii "Current count: %i\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$0, -4(%rbp)
	jmp	.L2
.L12:
	leaq	.LC0(%rip), %rcx
	call	puts
	leaq	-16(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	movl	$0, -8(%rbp)
	movzbl	-16(%rbp), %eax
	movsbl	%al, %eax
	subl	$65, %eax
	cmpl	$23, %eax
	ja	.L3
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L5(%rip), %rax
	movl	(%rdx,%rax), %eax
	movslq	%eax, %rdx
	leaq	.L5(%rip), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L5:
	.long	.L4-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L6-.L5
	.long	.L6-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L6-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L2-.L5
	.text
.L6:
	movl	$10, -8(%rbp)
	jmp	.L8
.L4:
	movl	$11, -8(%rbp)
	jmp	.L8
.L3:
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	atoi
	movl	%eax, -8(%rbp)
	cmpl	$0, -8(%rbp)
	jle	.L9
	cmpl	$10, -8(%rbp)
	jle	.L8
.L9:
	leaq	.LC2(%rip), %rcx
	call	puts
	jmp	.L2
.L8:
	cmpl	$2, -8(%rbp)
	jle	.L10
	cmpl	$6, -8(%rbp)
	jg	.L10
	addl	$1, -4(%rbp)
	jmp	.L11
.L10:
	cmpl	$10, -8(%rbp)
	jne	.L11
	subl	$1, -4(%rbp)
.L11:
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
.L2:
	movzbl	-16(%rbp), %eax
	cmpb	$88, %al
	jne	.L12
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 5.3.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	atoi;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
