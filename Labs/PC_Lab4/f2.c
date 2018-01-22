#include <stdio.h>

extern int g;

int f() {
	printf("%d\n", 1<<g);
}






