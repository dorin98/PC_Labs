#include <stdio.h>
#include <stdlib.h>

FILE *fin;

int sumDiv(int N)
{
	int S=0;
	for (int i=2; i<N; ++i)
		if (N%i==0) S+=i;
	return S;
}

int main()
{
	fin = fopen("in.txt", "r");
	int n, maxS=0, nr=-1;
	fscanf(fin,"%d",&n);
	for (int i=2; i<n; ++i)
	{
		int currSum = sumDiv(i);
		if (currSum > maxS) {
			nr = i;
			maxS = currSum;
		}
	}
	if (nr!=-1) printf("%d\n", nr);
	else printf("Exista doar numere prime in intervalul (2,N)");
	return 0;
}

