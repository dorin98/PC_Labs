#include <stdio.h>

int main()
{
	int n,x,S=0,bestSum=-(1<<30);
	scanf("%d",&n);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d",&x);
		if (S<0) S=x;
		else S+=x;
		if (S>bestSum) bestSum=S;
	}
	printf("%d\n",bestSum);
	return 0;
}
