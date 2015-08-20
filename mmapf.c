#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>

main()
{
	int fd;
	ssize_t len;
	void *p;

	len = 4096;

	fd = open("test.file", O_RDONLY, 0644);
	if ( fd == -1 )
		perror("open");
	p = mmap(0, len, PROT_READ, MAP_SHARED, fd, 0);
	if( p == MAP_FAILED)
		perror("mmap");
	close(fd);
}
