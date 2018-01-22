#include <stdio.h>

int main()
{
	int a[]={6,4,2,1,7}, b[]={4,6,3,1};
	for (int i=0; i<5; ++i)
	{
		int ok=0;
		for (int j=0; j<4; ++j)
			if (a[i]==b[j])
			{
				ok=1;
				break;
			}
		if (ok==0) printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
