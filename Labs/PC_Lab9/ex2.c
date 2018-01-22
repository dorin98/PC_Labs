#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **a, **b, **r, n;
	scanf("%d", &n);
	a = calloc(n, sizeof(int *));
	for (int i = 0 ; i < n ; ++i)
		a[i] = calloc(i+1,sizeof(int));
	b = calloc(n, sizeof(int *));
	for (int i = 0 ; i < n ; ++i)
		b[i] = calloc(i+1,sizeof(int));
	r = calloc(n, sizeof(int *));
	for (int i = 0 ; i < n ; ++i)
		r[i] = calloc(n, sizeof(int));
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < n ; ++j)
		{
			int x;
			scanf("%d ", &x);
			if (j <= i) a[i][j] = x;
		}
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < n ; ++j)
		{
			int x;
			scanf("%d ", &x);
			if (j >= i) b[j][i] = x;
		}
	for (int i = 0 ; i < n ; ++i)
	{
		for (int j = 0 ; j < n ; ++j)
			{
				for (int k = 0 ; k < n ; ++k)
				{
					if (k>i) { r[i][j]+=0; continue; }
					if (k>j) { r[i][j]+=0; continue; }
					r[i][j] += a[i][k]*b[j][k];
				}
			}
	}
	for (int i = 0 ; i < n; ++i)
	{
		for (int j = 0 ; j < n ; ++j)
			printf("%d ", r[i][j]);
		printf("\n");
	}
	return 0;
}