#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <string.h>

#define N 100000

int main(int argc, char *argv[])
{
	char input[N + 1] = { NULL };

	while (scanf("%s", &input) != EOF)
	{
		unsigned int sum[N] = { 0 };
		debug(printf("[DEBUG] %s\n", input));

		int T;
		scanf("%d", &T);
		debug(printf("[DEBUG] %d\n", T));

		int i;
		for (i = 0; i < T; i++)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			debug(printf("[DEBUG] [%d,%d)\n", l, r));

			int j, count = 0;
			for (j = l - 1; j < r - 1; j++)
			{
				if (input[j] == input[j + 1])
					count++;
			}
			printf("%d\n", count);
		}
	}

	return 0;
}
