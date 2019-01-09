#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int szt=sizeof(size_t);
	float max=0;

	max = pow(2, szt*8);

	printf("Sizeof size_t=%u\n"
	       "max value of the param malloc = %0.0f\n",
	       szt, max);
	exit(0);
}
