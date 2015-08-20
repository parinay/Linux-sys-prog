#include <unistd.h>
#include <stdio.h>
#include <sys/user.h>

main()
{
	long pagesize;

	pagesize = sysconf(_SC_PAGESIZE);
	printf("Page size is :%ld\n",pagesize);

	pagesize = PAGE_SIZE;
	printf("Page size is :%ld\n",pagesize);

	return 0;
}
