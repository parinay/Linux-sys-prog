#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void out (void)
{
	printf ("atexit() succeeded!\n");
}
int main (void)
{
	long atexit_max;
	atexit_max = sysconf (_SC_ATEXIT_MAX);
	printf ("atexit_max=%ld\n", atexit_max);

	if (atexit (out))
		fprintf(stderr, "atexit() failed!\n");
	return 0;
}

