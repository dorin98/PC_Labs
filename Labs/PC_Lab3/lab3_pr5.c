#include <stdio.h>

int isPal(int x)
{	
	int t=x,ogl=0;
	while (t>0)
	{
		ogl = ogl*10 + (t%10);
		t/=10;
	}
	if (ogl==x) return 1;
	return 0;
}		

int main()
{
	int n;
	scanf("%d", &n);
	if (isPal(n)==1) printf("Este palindrom\n");
	else printf("Nu este palindrom\n");
	return 0;
}

	
