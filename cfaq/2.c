#include <stdio.h>
#include <string.h>

int main()
{
	char s1[20] = "Hello, ";
	char *s2 = "world!";
	char *s3 = strcat(s1, s2);
  printf("s1 %s, s2 %s, s3 %s\n", s1, s2, s3);
}
