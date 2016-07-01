#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int n = 0;

	/*
		2 <= n <= 2000
		1 <= a_i <= n
	*/

	while (scanf("%d", &n) != EOF)
	{
		int i, a_i, maxIndex, minIndex;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a_i);

			if (a_i == n)
				maxIndex = i;
			else if (a_i == 1)
				minIndex = i;
		}
		debug(
			printf("[DEBUG] maxIndex=%d, minIndex=%d\n"
				, maxIndex, minIndex)
		);

		printf("%d\n",
			(int)fmax(
				fmax(n - maxIndex, maxIndex - 1),
				fmax(n - minIndex, minIndex - 1)
			)
		);
	}

	return 0;
}
