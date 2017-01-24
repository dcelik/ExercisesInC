#include <stdio.h>

/* With normal optimization level:

	movl	$5, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	leaq	.LC0(%rip), %rcx
	call	printf

This is where the x and y values are set.

With O2 optimization level:

	leaq	.LC1(%rip), %rcx
	movl	$6, %edx
	call	printf

The O2 realizes that these are just constant that don't change,
so it doe sthe addition during compile time to get 6, and prints that,
rather than doing the addition at runtime and moving variable around.

*/

/*

This part of the main function declaration does not exist in the O2 version.

	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	
%rbp is the base pointe( base of current stack frame)
%rsp is the stack pointer (top of current stack frame)

the fact that rsp is only used to start and end the program in the O2 version
seems to hint that the stack frame is omitted in this example as it is
unneeded, saving space and instructions.
	
instead, it uses the %rip and %rcx, which I believe are the next instruction
pointer and a general register, respectively. */




int main (){
	int x = 5;
	int y = x+1;
	printf("Hello, World!");
	printf("%d",y);
}