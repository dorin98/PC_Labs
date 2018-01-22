#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define uint unsigned int

uint myAtoI(char x[]) {
	int len = strlen(x);
	uint number = 0, p = 1;
	for (int i = len - 1 ; i>=0 ; --i)
	{
		number += (x[i]-'0')*p;
		p *= 10;
	}
	return number;
}

int cmp(const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		fprintf(stderr, "Gigeleee, cel putin doua!\n");
		return -2;
	}

	uint v[argc];
	for (int i = 1 ; i < argc ; ++i)
	{
		if (argv[i][0] == '-') {
			fprintf(stderr, "Gigeleee, da-mi numere naturale!\n");
			return INT_MIN;
		}
		v[i-1] = myAtoI(argv[i]);
	}

	qsort(v, argc-1, sizeof(uint), cmp);
	for (int i = 0 ; i < argc-1 ; ++i)
		printf("%d ", v[i]);

	printf("\n");
	return 0;
}