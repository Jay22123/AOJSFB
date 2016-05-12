#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int num;

	while (scanf("%d", &num) != EOF)
	{
		int x;
		for (x = 2; x <= num; x++)
		{
			if (num % x == 0)
			{
				int pow;
				for (pow = 0; num % x == 0; ++pow)
				{
					num /= x;
				}

				if (pow > 1)
					printf("%d^%d", x, pow);
				else
					printf("%d", x);

				if (num > 1)
					printf(" * ");
			}
		}
		printf("\n");
	}
	return 0;
}
