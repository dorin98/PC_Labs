#include <stdio.h>

int main()
{
	int a=1;
	char *s = (char *)&a;
	if (*s) {
		printf ("Little Endian");
	}
	else printf ("Big Endian");
	return 0;
}