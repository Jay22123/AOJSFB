#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

typedef enum _ClockDir
{
	CLOCK = 1,
	INVERSE = 2
}ClockDir;

typedef enum _Dir
{
	NONE = 0,
	UP = 1 << 3,
	DOWN = 1 << 2,
	LEFT = 1 << 1,
	RIGHT = 1 << 0
}Dir;

const Dir DIRECTION[][4] =
{ { NONE, NONE, NONE, NONE },
 { RIGHT ,DOWN ,LEFT ,UP },
{ DOWN ,RIGHT ,UP,LEFT } };

void getIndex(int *row, int *col, Dir d)
{
	if (d & UP)
		(*row)--;
	if (d & DOWN)
		(*row)++;
	if (d & LEFT)
		(*col)--;
	if (d & RIGHT)
		(*col)++;
}

void setValue(int mat[100][100], ClockDir dir, int N, int level, int value)
{
	if (N == 1)
	{
		mat[0][0] = value;
		return;
	}

	int r = level, c = level;

	int d;
	for (d = 0; d < 4; d++)
	{
		int i;
		for (i = 0; i < N - 1; i++)
		{
			mat[r][c] = value++;
			getIndex(&r, &c, DIRECTION[dir][d]);
		}
	}

	if (N - 2 > 1)
		setValue(mat, dir, N - 2, level + 1, value);
	else if (N - 2 == 1)
	{
		getIndex(&r, &c, RIGHT | DOWN);
		mat[r][c] = value++;
	}
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
	int T = 0;

	while (scanf("%d", &T) != EOF)
	{
		debug(printf("[DEBUG] %d\n", T));

		int t;
		for (t = 0; t < T; t++)
		{
			int N, M, mat[100][100] = { 0 };
			scanf("%d %d", &N, &M);
			debug(printf("[DEBUG] %d %d\n", N, M));

			setValue(mat, M, N, 0, 1);
			printMat(mat, N);
		}
	}

	return 0;
}
