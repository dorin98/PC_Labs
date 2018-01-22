#include <stdio.h>
#define maxSize 100

typedef struct {
	int lin, col;
	float x;
} element;

typedef struct {
	int L, C, N;
	element V[maxSize];
} rareMatrix;

void readMatrix(rareMatrix *A) 
{
	scanf("%d %d %d", &A->L, &A->C, &A->N);
	for (int i = 0 ; i < A->N ; ++i)
		scanf("%d %d %f", &A->V[i].lin, &A->V[i].col, &A->V[i].x);
}

void printMatrix(rareMatrix A)
{
	int cnt = 0;
	float useless = 0;
	for (int i = 0 ; i < A.L ; ++i)
	{
		for (int j = 0 ; j < A.C ; ++j)
			if (cnt < A.N)
			{
				if (A.V[cnt].lin == i && A.V[cnt].col == j) 
					{
						printf("%f ", A.V[cnt].x);
						++cnt;
					}
				else 
					printf("%f ", useless);
			}
		printf("\n");
	}
	printf("\n");
}

void add(rareMatrix A, rareMatrix B)
{
	int cntA = 0, cntB = 0;
	if (A.L != B.L || A.C != B.C) return;
	for (int i = 0 ; i < A.L ; ++i)
	{
		for (int j = 0 ; j < A.C ; ++j)
		{
			float S = 0;
			if (cntA < A.N && A.V[cntA].lin == i && A.V[cntA].col == j) 
				S += A.V[cntA++].x;
			if (cntB < B.N && B.V[cntB].lin == i && B.V[cntB].col == j)
				S += B.V[cntB++].x;
			printf("%f ", S);
		}
		printf("\n");
	}
}

int main() 
{
	rareMatrix A, B;

	// scanf("%d %d %d", &A.L, &A.C, &A.N);
	// for (int i = 0 ; i < A.N ; ++i)
	// 	scanf("%d %d %f", &A.V[i].lin, &A.V[i].col, &A.V[i].x);
	readMatrix(&A);
	printf("A:\n"); printMatrix(A);

	// scanf("%d %d %d", &B.L, &B.C, &B.N);
	// for (int i = 0 ; i < B.N ; ++i)
	// 	scanf("%d %d %f", &B.V[i].lin, &B.V[i].col, &B.V[i].x);
	readMatrix(&B);
	printf("B:\n"); printMatrix(B);

	printf("Suma celor 2 matrice rare este:\n");
	add(A,B);

	return 0;
}