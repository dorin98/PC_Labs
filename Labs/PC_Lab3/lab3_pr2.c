#include <stdio.h>
#include <stdlib.h>

FILE *fin;
int k=0;

void printDiv(int N)
{
	int ok=0;
	for (int i=2; i<N; ++i)
	{ 	
		if(N%i==0)
		{
			printf ("%d ", i);
			ok=1;
		}
	}
	if (!ok) { printf("PRIM"); ++k; }
	printf("\n");
}

int main()
{
	fin = fopen("in.txt", "r");
	int x;
	fscanf(fin,"%d",&x);
	while (x>0)
	{	
		printDiv(x);
		fscanf(fin,"%d",&x);
	}
	printf("S-au gasit %d numere prime\n", k);
	return 0;
}

	
