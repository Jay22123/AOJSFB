#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, m;

	while (scanf("%d %d", &n, &m) != EOF)
	{
		int i, sum = 0;
		for (i = 0; sum <= m; i++)
		{
			sum += n + i;
			debug(printf("[DEBUG] [%d] = %d\n", i, sum));
		}
		printf("%d\n", (n <= m) ? i : 1);
	}

	return 0;
}
