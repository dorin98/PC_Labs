#include <stdio.h>
#define maxSize 100


typedef struct {
	int maxGrade;
	int q[maxSize];
} Polynomial;

void readPolynomial(Polynomial *X)
{
	scanf("%d", &X->maxGrade);
	for (int i = X->maxGrade; i >= 0 ; --i)
		scanf("%d", &X->q[i]);
}

void printPolynomial(Polynomial X)
{
	int nada = 1;
	for (int i = X.maxGrade; i ; --i)
		if (X.q[i] != 0) {
			if (nada == 1) {
				printf("%d%s%d ", X.q[i], "*x^", i);
				nada = 0;
			}
			else
				printf("+ %d%s%d ", X.q[i], "*x^", i);
		}
	if (X.q[0] != 0) {
		if (nada == 0) printf("+ %d\n", X.q[0]);
		else printf("%d\n", X.q[0]);
	}
}

void add(Polynomial A, Polynomial B)
{
	int nada = 1, max = A.maxGrade > B.maxGrade ? A.maxGrade : B.maxGrade;
	for (int i = max ; i ; --i)
	{
		int s = 0;
		if (A.maxGrade >= i) s += A.q[i];
		if (B.maxGrade >= i) s += B.q[i];
		if (s != 0) {
			if (nada == 1) {
				printf("%d%s%d ", s, "*x^", i);
				nada = 0;
			}
			else
				printf("+ %d%s%d ", s, "*x^", i);
		}
	}
	if (A.q[0] + B.q[0] != 0) {
		if (nada == 0) printf("+ %d\n", A.q[0] + B.q[0]);
		else printf("%d\n", A.q[0] + B.q[0]);
	}
}

int main()
{
	Polynomial P, Q;

	readPolynomial(&P);
	printf("A: "); printPolynomial(P);

	readPolynomial(&Q);
	printf("B: "); printPolynomial(Q);

	printf("A + B = ");
	add(P,Q);

	return 0;
}