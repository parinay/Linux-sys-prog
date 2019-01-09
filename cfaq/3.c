#include <stdio.h>
#include <stdlib.h>

#define LINELEN 180
#define LINES 100

int main()
{
	char *linebuf;
	char *lines[LINES];
	FILE *fp;
	char *p;
	int i;

	fp = fopen("/home/user/syslog", "r");
	if (fp == NULL)
		printf("Failed to open file.\n");
	for(i=0; i<LINES; i++) {
		linebuf = malloc(LINELEN * sizeof(char *));
		p = fgets(linebuf, LINELEN, fp);
		if(p == NULL) {
			printf("Failed Reading from file\n");
			free(linebuf);
			break;
		}
		lines[i] = p;
	}
	for(i=0; i<LINES; i++) {
		printf("%s", lines[i]);
	}
}
