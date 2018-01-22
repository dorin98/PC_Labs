#include <stdio.h>

int binSrch(int v[], int n, int val)
{
	int i, p=1;
	for ( ; p<n; p<<=1) ;
	for (i=0; p ; p>>=1)
		if (i+p<n && v[i+p]<=val) 
			i+=p;
	return i;
}
