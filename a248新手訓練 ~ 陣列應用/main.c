#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int a, b, N;

	while (scanf("%d %d %d", &a, &b, &N) != EOF)
	{
		printf("%d.", a / b);
		int mod = a % b;

		int i = N;
		for (; i > 0; i--)
		{
			mod *= 10;
			int j;
			for (j = 0; mod >= b; j++)
			{
				mod -= b;
			}
			printf("%d", j);
		}
		printf("\n");
	}

	return 0;
}
