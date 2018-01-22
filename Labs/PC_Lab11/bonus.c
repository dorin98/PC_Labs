#include <stdio.h>
#include <string.h>
#define maxSize 100
#define uint unsigned int

typedef union {
	float n;
	char c[3];
} Mark;

typedef struct {
	char name[50];
	uint grade;
	Mark mark;
} Student;

int main()
{
	int k = 0;
	Student V[maxSize];
	char x[50];
	fgets(x, 50, stdin);
	while (strncmp(x, "stop", 4) != 0)
	{
		strcpy(V[k].name, x);
		scanf("%d\n", &V[k].grade);
		if (V[k].grade < 5) scanf("%s\n", V[k].mark.c);
		else scanf("%f\n", &V[k].mark.n);
		fgets(x, 50, stdin);
		++k;
	}
	
	for (int i = 0 ; i < k ; ++i)
	{
		printf("%s %u", V[i].name, V[i].grade);
		printf("\n");
	}

	return 0;
}