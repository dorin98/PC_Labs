#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char nume[20], prenume[20]; int varsta; } structPers;

void swapStruct(structPers *x, structPers *y)
{
	structPers tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	int N, ok;
	scanf("%d", &N);
	structPers *v;
	v = (structPers*)calloc(N, sizeof(structPers));
	for (int i = 0 ; i < N ; ++i)
		scanf("%s %s %d", v[i].nume, v[i].prenume, &v[i].varsta);
	do {
		ok = 0;
		for (int i = 0 ; i < N-1 ; ++i)
			if (strcmp(v[i].nume, v[i+1].nume) > 0) { swapStruct(&v[i], &v[i+1]); ok = 1; }
			else if (strcmp(v[i].nume, v[i+1].nume) == 0 && strcmp(v[i].prenume, v[i+1].prenume) > 0) { swapStruct(&v[i], &v[i+1]); ok = 1; }
			else if (strcmp(v[i].nume, v[i+1].nume) == 0 && strcmp(v[i].prenume, v[i+1].prenume) == 0 && v[i].varsta > v[i+1].varsta) { swapStruct(&v[i], &v[i+1]); ok = 1; }
	} while(ok == 1);
	for (int i = 0 ; i < N ; ++i)
		printf("%s %s %d\n", v[i].nume, v[i].prenume, v[i].varsta);
	return 0;
}