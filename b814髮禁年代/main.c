#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100000

int main(int argc, char *argv[])
{
	char input[N + 1] = { '\0' };

	while (scanf("%s", input) != EOF)
	{
		debug(printf("[DEBUG] %s\n", input));

		int T = 0;
		scanf("%d", &T);
		debug(printf("[DEBUG] %d\n", T));

		int day, min_index = N, max_index = 0,
			*l = malloc(T * sizeof(int)),
			*r = malloc(T * sizeof(int));
		for (day = 0; day < T; day++)
		{
			scanf("%d %d", (l + day), (r + day));
			debug(printf("[DEBUG] [%d,%d)\n",
				*(l + day), *(r + day)));

			--(*(l + day));
			--(*(r + day));

			min_index = (int)fmin(min_index, *(l + day));
			max_index = (int)fmax(max_index, *(r + day));
		}

		int i, *sum = malloc(T * sizeof(int));
		memset(sum, 0, T * sizeof(int));
		for (i = min_index; i < max_index; i++)
		{
			if (input[i] == input[i + 1])
				for (day = 0; day < T; day++)
				{
					if (*(l + day) <= i && i < *(r + day))
						(*(sum + day))++;
				}
		}

		for (day = 0; day < T; day++)
		{
			printf("%d\n", *(sum + day));
		}

		free(l);
		free(r);
		free(sum);
	}

	return 0;
}
