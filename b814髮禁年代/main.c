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

		int day;
		for (day = 0; day < T; day++)
		{
			int l, r, count = 0;
			scanf("%d %d", &l, &r);
			debug(printf("[DEBUG] [%d,%d)\n", l, r));

			for (l = l - 1; l < r - 1; l++)
			{
				if (input[l] == input[l + 1])
					count++;
			}
			printf("%d\n", count);
		}
	}

	return 0;
}
