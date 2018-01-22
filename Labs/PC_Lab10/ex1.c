#include <stdio.h>
#include <string.h>
#define maxSize 100
#define maxLength 30

void sortWords(char v[][maxLength], int n)
{
	int ok;
	do {
		ok = 0;
		for (int i = 1 ; i < n ; ++i)
		{
			if (strlen(v[i]) > strlen(v[i+1]))
			{
				char x[maxSize];
				strcpy(x,v[i]);
				strcpy(v[i],v[i+1]);
				strcpy(v[i+1],x);
				ok = 1;

			}
			else if (strlen(v[i]) == strlen(v[i+1]) && strcmp(v[i], v[i+1]) > 0)
			{
				char x[maxSize];
				strcpy(x,v[i]);
				strcpy(v[i],v[i+1]);
				strcpy(v[i+1],x);
				ok = 1;
			}
		}
	} while (ok == 1);
}

int main()
{
	int n;
	char vectorsChar[maxSize][maxLength];
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%s", vectorsChar[i]);
	sortWords(vectorsChar, n);
	for (int i = 1 ; i<= n ; ++i)
		printf("%s ", vectorsChar[i]);
	printf("\n");
	return 0;
}