#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

main()
{
	int fd;
	int readn;
	int writen;
	int len;
	char *buf;
	char *filename;
	printf("Enter the name of the file:");
	scanf("%s",filename);
	fd = open (filename, O_RDONLY,0644);
	if( fd == -1){
		//printf("%s \n",strerror(errno));
		perror("open");
	}
	len = 1024;
	buf = (char *) malloc (sizeof (char) * (len+1));
	readn = read (fd, buf, len);

	if(readn == 0)
		printf("Its EOF \n");
	else
		printf("The value read is:\n%s\nlenth:%d \nread=%d \n",
		       buf, len, readn);

	close(fd);

	fd = open (filename, O_WRONLY | O_APPEND,0644);
	
	if( fd == -1){
		perror("open write");
	}

	writen = write(fd, "This is write from Parinay\n",
		       strlen("This is write from Parinay\n"));
	
	if (writen == 0)
		printf("EOF \n");
	else
		printf("The length:%zd \nwrite=%d \n",
		       strlen("This is write from Parinay\n"), writen);
	close(fd);
}
