#include <stdio.h>
#include <string.h>
#define maxLength 500

void moveLeft(char v[], int p, int n)
{
	for (int i = p ; i < n ; ++i)
		v[i] = v[i+1];
}

int main()
{
	int n;
	char x[maxLength], c;
	fgets(x, maxLength, stdin);
	n = strlen(x);
	for (int i = 0 ; i < n ; ++i)
		if (x[i] == ' ')
		{
			moveLeft(x,i,n);
			--n;
		}
	n = strlen(x) - 2;
	for (int i = 0 ; i < n/2 ; ++i)
		if (x[i] != x[n-i])
		{
			printf("Nu este propozitie palindroma\n");
			return 0;
		}
	printf("Este propozitie palindroma\n");
	return 0;
}