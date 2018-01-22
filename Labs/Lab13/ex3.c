#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y) void *tmp; tmp = malloc(sizeof(x)); tmp = x; x = y; y = tmp;

int main(int argc, char *argv[])
{
	SWAP(argv[1],argv[2]);
	printf("%s %s\n", argv[1], argv[2]);
	return 0;
}