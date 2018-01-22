#include <stdio.h>

int main() 
{
	int n,v[100],min,max,pozmax,k;
	double ma;
	scanf("%d",&n);
	for (int i=0; i<n; ++i)
	{
		scanf("%d",&v[i]);
		ma+=v[i];
	}
	min=max=v[0];
	pozmax=k=0;
	ma/=n;
	if (v[0]>ma) ++k;
	for (int i=1; i<n; ++i)
	{
		if (v[i]<min) min=v[i];
		if (v[i]>max) { max=v[i]; pozmax=i+1; }
		if (v[i]>ma) ++k;
	}
	printf("%d %d %d\n", min, pozmax, k);
	return 0;
}
	
