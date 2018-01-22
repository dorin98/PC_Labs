#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxLength 1000

void aSort(int a[])
{
	int ok;
	do {
		ok = 0;
		for (int i = 1 ; i < a[0] ; ++i)
			if (a[i] > a[i+1])
			{
				int aux;
				aux = a[i];
				a[i] = a[i+1];
				a[i+1] = aux;
				ok = 1;
			}
	} while (ok == 1);
}

void bSort(int a[], int b[], int res[])
{
	int i = 1, j = 1, k = 0;
	while (i <= a[0] && j <= b[0])
	{
		if (a[i] < b[j])
			res[++k] = a[i++];
		else
			res[++k] = b[j++];
	}
	while (i <= a[0])
		res[++k] = a[i++];
	while (j <= b[0])
		res[++k] = b[j++];
	res[0] = k;
}

int main()
{
	FILE *outFile = fopen("sortare.out", "w");
	int n, a[maxLength], b[maxLength], res[maxLength];
	scanf("%d", &n);

	for (int i = 0 ; i < n ; ++i)
	{
		char input_file[] = "inputbonus/in";
		sprintf(input_file, "%s%d", input_file, i); // printf("%s\n", input_file);
		FILE *inFile = fopen(input_file, "rb");
		/// TODO
		fseek(inFile, 0, SEEK_END);
		int len = ftell(inFile) / sizeof(int); //printf("%d ", len);
		fseek(inFile, 0, SEEK_SET);
		if (i == 0) {
			a[0] = len;
			fread(a+1, sizeof(int), len, inFile);
			aSort(a);
			continue;
		}
		b[0] = len;
		//for (int i = 0 ; i <= a[0] ; ++i) printf("%d ", a[i]);
		fread(b+1, sizeof(int), len, inFile);
		aSort(b);
		bSort(a, b, res);
		memcpy(a, res, sizeof(res));
		///
		fclose(inFile);
	}

	for (int i = 1 ; i <= res[0] ; ++i)
		fprintf(outFile, "%d\n", res[i]);
	fclose(outFile);
	return 0;
}