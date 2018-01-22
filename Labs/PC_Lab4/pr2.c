#include <stdio.h>

int is_palindrome(int x) {
	int a = x, ogl = 0;
	while (a) {
		ogl = ogl*10 + a%10;
		a /= 10;
	}
	if (x==ogl) return 1;
	return 0;
}

void next_palindrome(int n) {
	for (int i=n ; ; ++i)
		if (is_palindrome(i)==1) { printf("%d\n",n); return; }		
}

int main() {
	int n;
	scanf("%d",&n);
	next_palindrome(n);
	return 0;
}
