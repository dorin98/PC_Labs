#include <stdio.h>
#define maxN 100

void printMatrix(int a[][maxN], int n, int m)
{
	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<m; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

void runD(int a[][maxN], int n, int m, int x, int y)
{
	if (x==n || y==m) { printMatrix(a,n,m); return; }
	int tmp = a[x][y];
	a[x][y]=0;
	++x; ++y;
	runD(a, n, m, x, y);
	--x; --y;
	a[x][y]=tmp;
}

void runS(int a[][maxN], int n, int m, int x, int y)
{
	if (x==n || y==m) { printMatrix(a,n,m); return; }
	int tmp = a[x][y];
	a[x][y]=0;
	++x; --y;
	runD(a, n, m, x, y);
	--x; ++y;
	a[x][y]=tmp;
}

int main()
{
	int n, m, d, a[maxN][maxN];
	scanf("%d %d %d", &n, &m, &d);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			scanf("%d", &a[i][j]);
	printf("\n");
	runD(a,n,m,0,d);
	printf("\n");
	runS(a,n,m,0,d);
	return 0;
}	
