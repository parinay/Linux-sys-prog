#include <stdio.h>
#include <stdlib.h>
void print(int *A, int n)
{
	printf("[] -%s", __func__);
	for(int i=0; i<n;i++)
		printf(" %d ", A[i]);
	printf("\n");
}
void input(int *A, int n)
{
	for(int i=0; i<n; i++) {
		A[i] = i+1;
	}

}
int main()
{
	int n;

	printf("Enter Size of an array:");
	scanf("%d", &n);

	int *A = (int *)malloc(n * sizeof(int));

	printf("Local print -\n");
	for(int i=0; i<n; i++) {
		printf(" %d ", A[i]);
	}
	input(A, n);
	printf("\n");
	print(A, n);
	printf("\n");
	//free(A);
	int *B =(int *)calloc(n, sizeof(int));
	print(B, n);
	printf("\n");
	free(B);

	//int *C = (int *)realloc(NULL, n*2*sizeof(int)); - malloc()
	//int *C = (int *)realloc(A, 0); - free()
	int *C = (int *)realloc(A,n*2*sizeof(int));
	printf("Prev block address =%p, new address =%p\n", A, C);
	print(C, n*2);
	free(A);
	free(C);
	exit(0);
}
