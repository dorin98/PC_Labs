#include <stdio.h>
#define maxN 100

int main()
{
	int n, m, a[maxN][maxN], ok;
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			scanf("%d", &a[i][j]);

	do {
		ok = 0;
		for (int i=1, j=1; i<n && j<m; ++i,++j)
			if (a[i][j] > a[i+1][j+1]) 
			{
				int tmp = a[i][j];
				a[i][j] = a[i+1][j+1];
				a[i+1][j+1] = tmp;
				ok = 1;
			}
	} while(ok==1);
	
	printf("\n");
	for (int i=1; i<=n; ++i)
	{
		for (int j=1; j<=m; ++j)
			printf("%d ", a[i][j]);	
		printf("\n");
	}
	
	return 0;
}
	
