#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1000

int main(int argc, char *argv[])
{
	int n = 0, num[MAX_INPUT] = { 0 };
	while (scanf("%d", &n) != EOF)
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}

		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if ((num[i] % 10) >(num[j] % 10))
				{
					int tmp = num[i];
					num[i] = num[j];
					num[j] = tmp;
				}
				else if ((num[i] % 10) == (num[j] % 10))
				{
					if ((num[i] / 10) < (num[j] / 10))
					{
						int tmp = num[i];
						num[i] = num[j];
						num[j] = tmp;
					}
				}
			}
		}

		for (i = 0; i < n; i++)
		{
			printf("%d ", num[i]);
		}
		printf("\n");

	}

	return 0;
}
