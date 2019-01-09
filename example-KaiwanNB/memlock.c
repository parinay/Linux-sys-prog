#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <limits.h>

void try_mlock(const char *numPgs)
{
	size_t numPages = atol(numPgs);
	const long pageSize = sysconf(_SC_PAGESIZE);
	void *ptr = NULL;
	size_t len;

	len = numPages * pageSize;
	if (len > LONG_MAX) {
		printf("Too many bytes to allocate\n");
		exit(EXIT_FAILURE);
	}
	posix_memalign(&ptr, pageSize, len);

	if (!ptr)
		printf("posix_memalign(for %zu bytes) failed\n", len);
	if (mlock(ptr, len)) {
		free(ptr);
		printf("mlock failed\n");
	}

	printf("Locked %zu bytes from address %p\n", len, ptr);
	memset(ptr, 'L', len);
	sleep(1);
	if (munlock(ptr, len)) {
		free(ptr);
		printf("munlock failed\n");
	}
	printf("unlocked...\n");

}
int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s pages-to-alloc\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	try_mlock(argv[1]);
	exit(EXIT_SUCCESS);
}
