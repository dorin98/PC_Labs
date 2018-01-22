#include <stdio.h>
#define maxLength 30

typedef struct {
	int day, month, year;
} Birthday;

typedef struct {
	char name[maxLength];
	Birthday birthday;
	float md;
} Student;

int main()
{
	FILE *inFile = fopen("student1.txt", "r");
	FILE *outFile = fopen("student.bin", "wb");
	Student v;
	
	while (fscanf(inFile, "%s %d %d %d %f\n", v.name, &v.birthday.day, &v.birthday.month, &v.birthday.year, &v.md)!=EOF)
		fwrite(&v, sizeof(Student), 1, outFile);
	fclose(outFile);

	FILE *in = fopen("student.bin", "rb");
	while (fread(&v, sizeof(Student), 1, in))
		printf("%s\n%d/%d/%d\n%.0f\n-----\n", v.name, v.birthday.day, v.birthday.month, v.birthday.year, v.md);
	return 0;
}