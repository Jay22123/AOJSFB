#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdbool.h>

bool fineRow(int mat[9][9])
{
	int row, col;
	for (row = 0; row < 9; row++)
	{
		bool num[9] = { false };
		for (col = 0; col < 9; col++)
		{
			if (num[mat[row][col] - 1] == true)
				return false;
			num[mat[row][col] - 1] = true;
		}
	}

	return true;
}

bool fineCol(int mat[9][9])
{
	int row, col;
	for (col = 0; col < 9; col++)
	{
		bool num[9] = { false };
		for (row = 0; row < 9; row++)
		{
			if (num[mat[row][col] - 1] == true)
				return false;
			num[mat[row][col] - 1] = true;
		}
	}

	return true;
}

const int NO[9][2] = {
	{ 0,0 },
	{ 0,3 },
	{ 0,6 },
	{ 3,0 },
	{ 3,3 },
	{ 3,6 },
	{ 6,0 },
	{ 6,3 },
	{ 6,6 }
};

bool fineSubMat(int mat[9][9])
{
	int i, row, col;

	for (i = 0; i < 9; i++)
	{
		bool num[9] = { false };
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (num[mat[row + NO[i][0]][col + NO[i][1]] - 1] == true)
					return false;
				num[mat[row + NO[i][0]][col + NO[i][1]] - 1] = true;
			}
		}
	}

	return true;
}

int main(int argc, char *argv[])
{
	int mat[9][9];

	while (scanf("%d", &mat[0][0]) != EOF)
	{
		int  row, col;
		for (row = 0; row < 9; row++)
		{
			for (col = ((row > 0) ? 0 : 1); col < 9; col++)
			{
				scanf("%d", &mat[row][col]);
			}
		}

		debug(
			for (row = 0; row < 9; row++)
			{
				for (col = 0; col < 9; col++)
				{
					printf("%d ", mat[row][col]);
				}
				printf("\n");
			}
		);
		bool result = fineRow(mat) && fineCol(mat) && fineSubMat(mat);

		printf("%s\n", (result) ? "yes" : "no");
	}
	return 0;
}
