#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		perror("fork");

	if(!pid) {
		char * const args[] = {"vi", NULL};
		int ret;

		ret = execv("/usr/bin/vi", args);
		if ( ret == -1)
			perror("execv");
	}

}

