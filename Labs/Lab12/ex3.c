#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxLength 30

typedef struct {
	int day, month, year;
} Birthday;

typedef struct {
	char *name;
	Birthday birthday;
	float md;
} Student;

int main()
{
	FILE *inFile = fopen("student1.txt", "r");
	FILE *outFile = fopen("student2.bin", "wb");
	Student v,x;
	int len;
	char nameLen[maxLength];

	while (fscanf(inFile, "%s%d%d%d%f\n", nameLen, &v.birthday.day, &v.birthday.month, &v.birthday.year, &v.md)!=EOF)
	{
		len = strlen(nameLen);
		fwrite(&len, sizeof(int), 1, outFile);
		fwrite(nameLen, sizeof(char), len, outFile);
		fwrite(&v.birthday, sizeof(Birthday), 1, outFile);
		fwrite(&v.md, sizeof(float), 1, outFile);
	}
	fclose(inFile);
	fclose(outFile);
	FILE *in = fopen("student2.bin", "rb");
	while (fread(&len, sizeof(int), 1, in)!=0)
	{
		v.name = malloc(len * sizeof(char));
		fread(v.name, sizeof(char), len, in);
		fread(&v.birthday, sizeof(Birthday), 1, in);
		fread(&v.md, sizeof(float), 1, in);
		printf("%s\n%d/%d/%d\n%.0f\n-----\n", v.name, v.birthday.day, v.birthday.month, v.birthday.year, v.md);
		free(v.name);
	}
	fclose(in);
	return 0;
}