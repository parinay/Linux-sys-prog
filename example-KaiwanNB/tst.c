#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct sbar {
		int a[10];
		int b[10];
		char buf[256];
	};

	struct sbar *psbar;

	psbar = malloc(sizeof(struct sbar));
	psbar->a[10] = 0;
	psbar->b[10] = 0;
	strcpy(psbar->buf,"abcdefghijklmn\0");

	free(psbar);


	exit(0);
}
