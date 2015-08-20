#include <stdio.h>
#include <stdlib.h>

#define OBP(op)    o_## op
int o_create(){
	printf("in o_create \n");
	return 0;
}
int main()
{
	OBP(create());
	return 0;
}

