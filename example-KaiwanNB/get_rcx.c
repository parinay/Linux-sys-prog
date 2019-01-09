#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef unsigned long u64;

static u64 get_rcx(void)
{
	/*
	 * Pro Tip: x86 ABI: query a register's value by moving its value into RAX.
	 * [RAX] is returned by the function!
	 */
	/*
	 * at&t syntax: movq <src_reg>, <dest_reg>
	 * Register        : prefix name with %
	 * Immediate value : prefix with $
	 */
	__asm__ __volatile__(
			     "push %rcx\n\t"
			     "movq $5, %rcx\n\t"
			     "movq %rcx, %rax");

	__asm__ __volatile__("pop %rcx");

}
int main(void)
{
	printf("Hello, inline assembly:\n [RCX] = 0x%1lx\n",
	       get_rcx());
	exit(0);
}
