#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 100000

int main(int argc, char *argv[])
{
	char input, inputPrev;

	while (scanf("%c", &input) != EOF)
	{
		debug(printf("[DEBUG] %c", input));

		unsigned int count = 0, sum[N] = { 0 };
		while (true)
		{
			inputPrev = input;
			scanf("%c", &input);
			if (input == '\n')
				break;
			debug(printf("%c", input));

			++count;

			if (inputPrev == input)
				sum[count - 1]++;

			sum[count] += sum[count - 1];
		}
		debug(printf("\n"));

		int T;
		scanf("%d", &T);
		debug(printf("[DEBUG] %d\n", T));

		int day;
		for (day = 0; day < T; day++)
		{
			int l, r, count = 0;
			scanf("%d %d", &l, &r);
			debug(printf("[DEBUG] [%d,%d)\n", l, r));

			if (r - 2 == l - 1)
				printf("%d\n", sum[l - 1] - sum[l - 2]);
			else
				printf("%d\n", sum[r - 2] - sum[l - 1]);
		}
	}

	return 0;
}
