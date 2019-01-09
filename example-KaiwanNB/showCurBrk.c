#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX (128*1024)
int main()
{
	char *heapPtr;
	size_t isize;

	printf("Current program break : %p\n", sbrk(0));

	printf("Enter dynamic allocation size: ");
	scanf("%lu", &isize);

	if(isize > MAX)
		perror("Error: Value more than allowed MAX");

	heapPtr = (char*)malloc(isize);

	//if(!heapPtr)
	//	perror("Error: malloc() failed.");

	printf("malloc(%lu) = %16p currernt sbreak = %16p\n",
	       isize, heapPtr, sbrk(0));

	free(heapPtr);

	exit(EXIT_SUCCESS);
}
