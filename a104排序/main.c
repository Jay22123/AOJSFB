#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdbool.h>

void sort(int *num, int arrSize)
{
	int i, j;
	for (i = 0; i < arrSize; i++)
	{
		bool isSwap = false;
		for (j = 0; j < arrSize - 1; j++)
		{
			if (*(num + j) > *(num + j + 1))
			{
				isSwap = true;
				int tmp = *(num + j);
				*(num + j) = *(num + j + 1);
				*(num + j + 1) = tmp;
			}
		}
		if (!isSwap)
			break;
	}
}

int main(int argc, char *argv[])
{
	int n, num[1000];
	while (scanf("%d", &n) != EOF)
	{
		debug(printf("[DEBUG] n=%d\n", n));
		int i, j;
		debug(printf("[DEBUG] "));
		for (i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
			debug(printf("%d ", num[i]));
		}
		debug(printf("\n"));

		sort(num, n);

		for (i = 0; i < n; i++)
		{
			printf("%d ", num[i]);
		}
		printf("\n");
	}

	return 0;
}
