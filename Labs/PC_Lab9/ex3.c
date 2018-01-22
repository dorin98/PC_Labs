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

void add(char *A, char *B)
{
	int R[A[0]-'0'+B[0]-'0'+2], T = 0;
	if (B[0] > A[0])
		for (int i = A[0]-'0' + 1 ; i <= B[0]-'0' ; ++i)
			A[i] = '0';
	else 
		for (int i = B[0]-'0' + 1 ; i <= A[0]-'0' ; ++i)
			B[i] = '0';
	int N = (A[0]-'0' > B[0]-'0') ? A[0]-'0' : B[0]-'0';
	for (int i = 1; i <= N ; ++i)
	{
		R[i] = A[i]-'0' + B[i]-'0' + T;
		T = R[i]/10;
		R[i] %= 10;
	}
	if (T>0)
		R[N+1] = T;
	printf("Suma: ");
	for (int i = N + T ; i ; --i)
		printf("%d", R[i]);
	printf("\n");
}

void addForFibo(int A[], int B[])
{
	int R[30], T = 0; 
	if (B[0] > A[0])
		for (int i = A[0] + 1 ; i <= B[0] ; ++i)
			A[i] = 0;
	else 
		for (int i = B[0] + 1 ; i <= A[0] ; ++i)
			B[i] = 0;
	int N = (A[0] > B[0]) ? A[0] : B[0];
	for (int i = 1; i <= N ; ++i)
	{
		R[i] = A[i] + B[i] + T;
		T = R[i]/10;
		R[i] %= 10;
	}
	if (T>0)
		R[N+1] = T;
	for (int i = N + T ; i ; --i)
		printf("%d", R[i]);
	printf("\n");
	for (int i = 0 ; i <= B[0] ; ++i)
		A[i] = B[i];
	B[0] = N + T;
	for (int i = 1 ; i <= B[0] ; ++i)
		B[i] = R[i];
}

int main()
{
	char *a, *b;
	int val1, val2;
	scanf("%d %d", &val1, &val2);
	a = buildNumber(val1);
	b = buildNumber(val2);
	add(a, b);
	a[0] = '1' ; a[1] = '1'; a[2] = '\0';
	b[0] = '1' ; b[1] = '1'; b[2] = '\0';
	int *f1, *f2;
	f1 = calloc(30, sizeof(int));
	f2 = calloc(30, sizeof(int));
	f1[0]=f1[1]=f2[0]=f2[1]=1;
	printf("1\n1\n");
	for (int i = 98 ; i ; --i)
		addForFibo(f1,f2);
	//for (int i = 0 ; i <= a[0] - '0' ; ++i) printf("%c ", a[i]); printf("\n"); for (int i = 0 ; i <= b[0] - '0' ; ++i) printf("%c ", b[i]); printf("\n");
	return 0;
}