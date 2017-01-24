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
	.section	.text.unlikely,"x"
.LCOLDB4:
	.section	.text.startup,"x"
.LHOTB4:
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	.L5(%rip), %rbx
	xorl	%esi, %esi
	call	__main
	movzbl	32(%rsp), %edx
	leaq	32(%rsp), %rdi
.L2:
	cmpb	$88, %dl
	je	.L15
.L11:
	leaq	.LC0(%rip), %rcx
	call	puts
	leaq	.LC1(%rip), %rcx
	movq	%rdi, %rdx
	call	scanf
	movzbl	32(%rsp), %edx
	leal	-65(%rdx), %eax
	cmpb	$23, %al
	ja	.L3
	movzbl	%al, %eax
	movslq	(%rbx,%rax,4), %rax
	addq	%rbx, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L5:
	.long	.L10-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L13-.L5
	.long	.L13-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L13-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L3-.L5
	.long	.L2-.L5
	.section	.text.startup,"x"
	.p2align 4,,10
.L3:
	movq	%rdi, %rcx
	call	atoi
	leal	-1(%rax), %edx
	cmpl	$9, %edx
	ja	.L16
	leal	-3(%rax), %edx
	cmpl	$3, %edx
	ja	.L9
	addl	$1, %esi
.L10:
	leaq	.LC3(%rip), %rcx
	movl	%esi, %edx
	call	printf
	movzbl	32(%rsp), %edx
	cmpb	$88, %dl
	jne	.L11
.L15:
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
.L9:
	cmpl	$10, %eax
	jne	.L10
.L13:
	subl	$1, %esi
	jmp	.L10
	.p2align 4,,10
.L16:
	leaq	.LC2(%rip), %rcx
	call	puts
	movzbl	32(%rsp), %edx
	jmp	.L2
	.seh_endproc
	.section	.text.unlikely,"x"
.LCOLDE4:
	.section	.text.startup,"x"
.LHOTE4:
	.ident	"GCC: (GNU) 5.3.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	atoi;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
