#include <stdio.h>
#define maxN 100

void multiply(int a[][maxN], int b[][maxN], int n) // a=a*b
{
	int r[maxN][maxN];
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
        	{
            		r[i][j]=0;
            		for (int p=0; p<n; ++p)
                		r[i][j]+=a[i][p]*b[p][j];
        	}
    	for (int i=0; i<n; ++i)
        	for (int j=0; j<n; ++j)
            		a[i][j]=r[i][j];
}

int main()
{
	int a[maxN][maxN], cnst[maxN][maxN], n, p;
	scanf("%d %d", &n, &p);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
		{
			scanf("%d", &a[i][j]);
			cnst[i][j]=a[i][j];
		}

	while (p>0)
	{
		if (p%2==1) {
			--p;
			multiply(a,cnst,n);
		}
		else {
			p /= 2;
			multiply(a,cnst,n);
		}
	}

	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<n; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
