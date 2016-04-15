#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int row = 0, column = 0, mat[100][100] = { 0 };

	while (scanf("%d %d", &row, &column) != EOF)
	{
		int row_i, column_i;
		for (row_i = 0; row_i < row; row_i++)
			for (column_i = 0; column_i < column; column_i++)
				scanf("%d%*c", &mat[row_i][column_i]);

		for (column_i = 0; column_i < column; column_i++)
		{
			for (row_i = 0; row_i < row; row_i++)
			{
				printf("%d", mat[row_i][column_i]);
				if (row_i < row - 1)
					printf(" ");
			}
			printf("\n");
		}
	}

	return 0;
}
