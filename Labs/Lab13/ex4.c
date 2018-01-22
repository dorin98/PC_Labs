#include <stdio.h>
#include <stdarg.h>

void gcd(int a, int b, ...) {
	if (a < 0 || b < 0) {
		printf("Trebuie cel putin 2 numere\n");
		return;
	}

	va_list args;
	va_start(args, b);

	int curr1 = a, curr2 = b;
	int r;
	do {
		// GCD -> a = gcd(a,b)
		while (curr2)
		{
			r = curr1 % curr2;
			curr1 = curr2;
			curr2 = r;
		}
		//
		curr2 = va_arg(args, int);
	} while (curr2 >= 0);
	printf("%d\n", curr1);
	va_end(args);
}

int main()
{
	gcd(128, 1024, 512, -1);
	return 0;
}