#include <stdio.h>
#include <string.h>

int main()
{
	char answer[3], *p;
	printf("Type something:\n");
	p = fgets(answer, sizeof(answer), stdin);
  if((p = strchr(answer, '\n')) != NULL)
    *p = '\0';
    printf("You typed \"%s\"\n", answer);
}
