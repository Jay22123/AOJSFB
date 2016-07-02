#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int first, last, ai[10000] = { 0 };

int getBigNum(int *sum)
{
	if (first >= 0 && last >= 0)
	{
		if (first == last)
		{
			*sum += ai[first];
			first = last = -1;
		}
		else if (ai[first] >= ai[last])
			*sum += ai[first++];
		else
			*sum += ai[last--];

		return 1;
	}

	return 0;
}


int main(int argc, char *argv[])
{
	int n = 0;

	while (scanf("%d", &n) != EOF)
	{
		debug(printf("[DEBUG] %d\n", n));

		debug(printf("[DEBUG] "));
		int i;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &ai[i]);
			debug(printf("%d ", ai[i]));
		}
		debug(printf("\n"); );

		first = 0;
		last = n - 1;
		int O = 0, X = 0;

		while (1)
		{
			if (!getBigNum(&O))
				break;

			if (!getBigNum(&X))
				break;
		}

		if (O == X)
			printf("D\n");
		else
			printf("%c\n", (O > X) ? 'O' : 'X');

		printf("%d %d\n", O, X);

	}

	return 0;
}
