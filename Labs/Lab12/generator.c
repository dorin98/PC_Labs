#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	FILE *outFile=fopen("inputbonus/in4", "wb");
	int n; 
	scanf("%d", &n);
	srand(time(NULL));
	while (n--)
	{
		int x = rand()%1000;
		fwrite(&x, sizeof(int), 1, outFile);
		//printf("%d ", x);
	}
	printf("\n");
	return 0;
}