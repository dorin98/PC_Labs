#include <stdio.h>

int main()
{
	int n, v[100];
	scanf("%d",&n);
	for (int i=1; i<=n; ++i)
		scanf("%d",&v[i]);
	for (int i=1; i<n; ++i)
	{
		int min=v[i], pos=i;
		for (int j=i+1; j<=n; ++j)
			if (v[j]<min)
			{
				min=v[j];
				pos=j;
			}
		v[0]=v[i];
		v[i]=v[pos];
		v[pos]=v[0];
	}
	for (int i=1; i<=n; ++i)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}
