#include <stdio.h>
#include <stdlib.h>

FILE *fin;

void cmmdc(int *a, int b)
{
	while (*a!=b)
	{
		if (*a>b) *a-=b;
		else b-=*a;
	}
}

int main()
{
	fin = fopen("in.txt", "r");
	int N,x,y;
	fscanf(fin,"%d",&N);
	fscanf(fin,"%d",&x);
	for (int i=2; i<=N; ++i)
	{
		fscanf(fin,"%d",&y);
		cmmdc(&x,y);
	}
	printf("%d\n",x);
	return 0;
}
