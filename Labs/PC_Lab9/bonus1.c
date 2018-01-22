#include <stdio.h>
#include <stdlib.h>

char *buildNumber(int value)
{
	char *number;
	int nrD = 0, temp = value;
	while (temp)
	{
		++nrD;
		temp /= 10;
	}
	number = calloc(nrD+1, sizeof(char));
	number[0] = nrD + '0';
	for (int i = 1 ; i <= nrD ; ++i)
	{
		number[i] = (value % 10) + '0';
		value /= 10;
	}
	return number;
}

void char_multiply(char *A, char *B)
{
	int R[(A[0]-'0')+(B[0]-'0')+1], T = 0;
	R[0] = A[0] -'0' + B[0] -'0' - 1;
	for (int i = 1 ; i <= A[0]-'0' + B[0]-'0' ; ++i)
		R[i] = 0;
	for (int i = 1 ; i <= A[0]-'0' ; ++i)
		for (int j = 1; j <= B[0]-'0' ; ++j)
				R[i + j - 1] += (A[i]-'0') * (B[j]-'0');
	for (int i = 1 ; i <= R[0] ; ++i)
	{
		R[i] += T;
		T = R[i] / 10;
		R[i] %= 10;
	}
	if (T > 0) R[++R[0]] = T;
	printf("Produs: ");
	for (int i = R[0] ; i ; --i)
		printf("%d",R[i]);
	printf("\n");
	for (int i = 0 ; i <= R[0] ; ++i)
		A[i] = R[i] + '0';
}

int main()
{
	char *a, *b;
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	a = buildNumber(n1);
	b = buildNumber(n2);
	char_multiply(a,b);
	a = buildNumber(1);
	for (int i = 1 ; i <= 50 ; ++i)
	{
		b = buildNumber(i);
		char_multiply(a,b);
	}
	return 0;
}