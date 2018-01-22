#include <stdio.h>
#define maxN 1000

void readMatrix(int a[][maxN], int n, int m)
{
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			scanf("%d",&a[i][j]);
}

void multiMatrix(int a[][maxN], int n1, int m1, int b[][maxN], int n2, int m2)
{
	if (m1 != n2) { printf("Nu se poare realiza inmultirea!"); return; }
	for (int i=1 ; i<=n1; ++i) 
	{	
		for (int j=1; j<=m1; ++j)
		{
			int S=0;
			for (int q=1; q<=m2; ++q)
				for (int p=1; p<=n2; ++p)
					S+=a[i][j]*b[p][q];
			printf("%d ",S);
		}
	printf("\n");
	}
}

int main()
{
	int a[maxN][maxN], b[maxN][maxN], n1, m1, n2, m2;
	scanf("%d %d", &n1, &m1);
	readMatrix(a,n1,m1);
	scanf("%d %d", &n2, &m2);
	readMatrix(b,n2,m2);
	multiMatrix(a,n1,m1,b,n2,m2);
	return 0;
}
