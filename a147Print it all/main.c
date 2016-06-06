#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (!(n > 0))
			break;

		int i;
		for (i = 1; i < n; i++)
		{
			if (i % 7 > 0)
				printf("%d ", i);
		}
		printf("\n");
	}

	return 0;
}
