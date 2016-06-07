#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int num = -1;

	while (scanf("%d", &num) != EOF)
	{
		debug(printf("[DEBUG] %d\n", num));
		if (num < 1)
			break;

		int bit[31] = { 0 }, i;
		for (i = 0; i < 31, num > 0; i++, num >>= 1)
		{
			bit[i] = (num & 1);
		}

		debug(;
		printf("[DEBUG] ");
		for (i = 30; i >= 0; i--)
		{
			printf("%d", bit[i]);
		}
		printf("\n");
		);

		int count = 0;
		for (i = 0; i < 31; i++)
		{
			if (bit[i] != 0)
				++count;
			else
				break;
		}
		printf("%d\n", count);
	}

	return 0;
}
