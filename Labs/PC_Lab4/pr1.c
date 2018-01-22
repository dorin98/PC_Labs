#include <stdio.h>

int sol = 1;

void power(int n, int p) {
	if (p == 0) return;
	if (p % 2 == 1) sol *= n;
	n *= n;
	power(n, p>>1);
}

int number_of_digits(int n) {
	if (n<10) return 1;
	return 1 + number_of_digits(n/10);
}

void reverse_number(int n) {
	printf("%d", n%10);
	if (n>9) reverse_number(n/10);	
}

int main() {
	int n,pow;
	scanf("%d %d",&n,&pow);
	/*1*/ power(n,pow); printf("%d\n", sol);
	/*2*/ printf("%d", number_of_digits(n)); printf("\n");
	/*3*/ reverse_number(n); printf("\n");
	return 0;
}
	
