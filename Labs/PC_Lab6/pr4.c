#include <stdio.h>
#define maxN 100

int a[maxN][maxN], b[maxN][maxN];
typedef struct {
	int x1,y1,x2,y2,val;
} subMatrix;

void readMatrix(int a[][maxN], int n, int m)
{
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
		{
			scanf("%d", &a[i][j]);
			a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
}

int main()
{	
	int n1, m1, n2, m2, k;
	subMatrix vA[maxN*maxN], vB[maxN*maxN];	

	scanf("%d %d", &n1, &m1);
	readMatrix(a,n1,m1);
	scanf("%d %d", &n2, &m2);
	readMatrix(b,n2,m2);

	/// Crearea sumelor partiale pentru A
	k = 0;
	for (int i=1; i<n1; ++i)
		for (int j=1; j<m1; ++j)
			{
				for (int p=i+1; p<=n1; ++p)
					for (int q=j+1; q<=m1; ++q)
					{
						vA[++k].val = a[p][q]-a[i-1][q]-a[p][j-1]+a[i-1][j-1];
						vA[k].x1 = i; vA[k].y1 = j;
						vA[k].x2 = p; vA[k].y2 = q;
					}
			}
	vA[0].val=k;

	/// Crearea sumelor partiale pentru B
	k = 0;
	for (int i=1; i<n2; ++i)
		for (int j=1; j<m2; ++j)
			{
				for (int p=i+1; p<=n2; ++p)
					for (int q=j+1; q<=m2; ++q)
					{
						vB[++k].val = b[p][q]-b[i-1][q]-b[p][j-1]+b[i-1][j-1];
						vB[k].x1 = i; vB[k].y1 = j;
						vB[k].x2 = p; vB[k].y2 = q;
					}
			}
	vB[0].val=k;
	
	/// Afisarea submatricilor de suma egala
	for (int i=1; i<=vA[0].val; ++i)
		for (int j=1; j<=vB[0].val; ++j)
			if (vA[i].val == vB[j].val)
			{	
				printf("%d, %d, %d, %d --- ", vA[i].x1, vA[i].y1, vA[i].x2, vA[i].y2);
				printf("%d, %d, %d, %d\n", vB[j].x1, vB[j].y1, vB[j].x2, vB[j].y2);
			}
	return 0;
}
	
