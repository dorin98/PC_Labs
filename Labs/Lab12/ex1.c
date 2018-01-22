#include <stdio.h>

int main()
{
	FILE *inFile = fopen("gigel.bin", "rb");
	FILE *outFile = fopen("gigel.txt", "w");
	int S = 0, x;
	while (fread(&x, sizeof(int), 1, inFile))
		if (x % 2 == 1	)
			S += x;
		else
			fprintf(outFile, "%d ", x);
	fprintf(outFile, "\n");
	printf("%d\n", S);
	return 0;
}