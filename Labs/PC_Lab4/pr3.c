#include <stdio.h>

int is_prime(int n) {
	for (int i = 2 ; i*i <= n ; ++i)
		if (n % i == 0) return 0;
	return 1;
}

int main() {
	int n;
	scanf("%d",&n);
	while (n>0) {
		printf("* ");
		if (is_prime(n) == 0) {
			int ks = 1, xs, kd = 1, xd;
			for (int i = n-1; i ; --i, ++ks)
				if (is_prime(i) == 1) { xs=i; break; }
			for (int i = n+1; ; ++i, ++kd)
				if (is_prime(i) == 1) { xd=i; break; }
			if (ks < kd) printf("%d", xs);
			else if (kd < ks) printf("%d", xd);
			else printf("%d %d", xs, xd);
		}
		printf("\n");
		scanf("%d", &n);
	}
	return 0;
}
