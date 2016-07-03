#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct _Classmate
{
	float Ch, En, height;
}Classmate;

Classmate classmate[100000] = { 0 };

/*
傳回-1代表 a < b
傳回 0代表 a = b
傳回 1代表 a > b
*/
int compare(const Classmate *A, const Classmate *B)
{
	if (A->Ch + A->En != B->Ch + B->En)
		return (A->Ch + A->En < B->Ch + B->En) ? -1 : 1;

	if (A->Ch < B->Ch)
		return -1;

	if (A->En < B->En)
		return -1;

	return 1;
}


int main(int argc, char *argv[])
{
	int N = 0;

	while (scanf("%d", &N) != EOF)
	{
		debug(printf("[DEBUG] %d\n", N));

		Classmate *head = &classmate[0];
		int i;
		for (i = 0; i < N; i++)
		{
			scanf("%f %f %f",
				&classmate[i].Ch,
				&classmate[i].En,
				&classmate[i].height
			);
			debug(
				printf("[DEBUG] %f %f %f\n",
					classmate[i].Ch,
					classmate[i].En,
					classmate[i].height)
			);
		}
		qsort(classmate, N, sizeof(Classmate), compare);

		debug(
			printf("[DEBUG] qsort start\n");
		int DEBUG_qsort_i;
		for (DEBUG_qsort_i = 0;
			DEBUG_qsort_i < N;
			DEBUG_qsort_i++)
		{
			printf("[DEBUG] %f %f %f\n",
				classmate[DEBUG_qsort_i].Ch,
				classmate[DEBUG_qsort_i].En,
				classmate[DEBUG_qsort_i].height);
		}
		printf("[DEBUG] qsort end\n");
		);

		int K = 0, A, B;
		for (A = 0; A < N - 1; A++)
		{
			for (B = A + 1; B < N; B++)
			{
				if (classmate[A].height >
					classmate[B].height)
					K++;
			}
		}

		printf("%d\n", K);
	}

	return 0;
}
