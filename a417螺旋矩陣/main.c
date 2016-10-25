#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

void setValue(int mat[100][100], int N, int level, int value)
{
	const int ArrSize = (N + 2 * level - 1) - level;
	int r, c;

	for (c = level; c < ArrSize; c++)
	{
		mat[level][c] = value++;
	}

	for (r = level; r < ArrSize; r++)
	{
		mat[r][ArrSize] = value++;
	}

	for (c = ArrSize; c > level; c--)
	{
		mat[ArrSize][c] = value++;
	}

	for (r = ArrSize; r > level; r--)
	{
		mat[r][level] = value++;
	}

	if (N - 2 == 1)
		mat[(ArrSize + level) / 2][(ArrSize + level) / 2] = value;
	else if (N - 2 > 1)
		setValue(mat, N - 2, level + 1, value);
}

void printMat(int mat[100][100], int N)
{
	int r, c;
	for (r = 0; r < N; r++)
	{
		for (c = 0; c < N; c++)
		{
			printf("%5d", mat[r][c]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	int T = 0, mat[100][100] = { 0 };

	while (scanf("%d", &T) != EOF)
	{
		debug(printf("[DEBUG] %d\n", T));

		int t;
		for (t = 0; t < T; t++)
		{
			int N, M;
			scanf("%d %d", &N, &M);
			debug(printf("[DEBUG] %d %d\n", N, M));

			setValue(mat, N, 0, 1);
			printMat(mat, N);
		}
	}

	return 0;
}
