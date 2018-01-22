#include <stdio.h>
#include <string.h>
#define maxLength 100

int main()
{
	int nr = 0;
	char x[maxLength], v[maxLength], *word;
	fgets(x, maxLength, stdin);
	scanf("%s", v);
	word = strtok(x, " ");
	while (word != NULL)
	{
		if (strcmp(word,v)==0) ++nr;
		word = strtok(NULL, " ");
	}
	printf("%d\n", nr);
	return 0;
}