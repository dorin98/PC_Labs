#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	unsigned int *v, n, max, ok;
	scanf("%d %d", &n, &max);
	srand(time(NULL));
	v = calloc(n,sizeof(int));
	for (int i = 0 ; i < n ; ++i)
		v[i] = rand()%max;
	for (int i = 0 ; i < n ; ++i)
		printf("%d ", v[i]);
	printf("\n");
	do {
		ok = 0;
		for (int i = 0 ; i < n-1 ; ++i)
			if (v[i] > v[i+1])
			{
				unsigned int aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				ok = 1;
			}
	} while (ok == 1);
	for (int i = 0 ; i < n ; ++i)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}