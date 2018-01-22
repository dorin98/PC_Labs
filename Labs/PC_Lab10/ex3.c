#include <stdio.h>
#include <string.h>
#define maxLength 100

int main()
{
	char x[maxLength], *word;
	fgets(x, maxLength, stdin);
	word = strtok(x," ");
	while (word != NULL)
	{
		printf("%s ", word);
		word = strtok(NULL, " ");
	}
	return 0;
}